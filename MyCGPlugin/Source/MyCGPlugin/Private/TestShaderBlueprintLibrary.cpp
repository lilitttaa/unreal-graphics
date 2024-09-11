// Fill out your copyright notice in the Description page of Project Settings.

#include "TestShaderBlueprintLibrary.h"
#include "Engine/TextureRenderTarget2D.h"

struct FMyShaderVertex
{
	FVector4 Position;
	FVector2D UV;
};

class FMyShaderQuadVertexBuffer: public FVertexBuffer
{
public:
	/**
	 * Initialize the RHI for this rendering resource
	 */
	virtual void InitRHI() override
	{
		// create a static vertex buffer
		FRHIResourceCreateInfo CreateInfo;
		VertexBufferRHI = RHICreateVertexBuffer(sizeof(FMyShaderVertex) * 4, BUF_Static, CreateInfo);
		void* VoidPtr   = RHILockVertexBuffer(VertexBufferRHI, 0, sizeof(FMyShaderVertex) * 4, RLM_WriteOnly);
		// Generate the vertices used
		FMyShaderVertex* Vertices = reinterpret_cast<FMyShaderVertex*>(VoidPtr);
		Vertices[0].Position        = FVector4(-1.0f, -1.0f, 0.0f, 1.0f);
		Vertices[1].Position        = FVector4(1.0f, -1.0f, 0.0f, 1.0f);
		Vertices[2].Position        = FVector4(-1.0f, 1.0f, 0.0f, 1.0f);
		Vertices[3].Position        = FVector4(1.0f, 1.0f, 0.0f, 1.0f);
		Vertices[0].UV              = FVector2D(0.0f, 0.0f);
		Vertices[1].UV              = FVector2D(1.0f, 0.0f);
		Vertices[2].UV              = FVector2D(0.0f, 1.0f);
		Vertices[3].UV              = FVector2D(1.0f, 1.0f);
		RHIUnlockVertexBuffer(VertexBufferRHI);
	}
};



class FMyShaderVertexDeclaration: public FRenderResource
{
public:
	FVertexDeclarationRHIRef VertexDeclarationRHI;
	virtual void InitRHI() override
	{
		FVertexDeclarationElementList Elements;
		Elements.Add(FVertexElement(0, STRUCT_OFFSET(FMyShaderVertex, Position), VET_Float4, 0, sizeof(FMyShaderVertex)));
		Elements.Add(FVertexElement(0, STRUCT_OFFSET(FMyShaderVertex, UV), VET_Float2, 1, sizeof(FMyShaderVertex)));
		VertexDeclarationRHI = PipelineStateCache::GetOrCreateVertexDeclaration(Elements);
	}
	virtual void ReleaseRHI() override
	{
		VertexDeclarationRHI.SafeRelease();
	}
};

TGlobalResource<FMyShaderQuadVertexBuffer> GMyShaderQuadVertexBuffer;
void DrawTestShaderRenderTarget_RenderThread(FRHICommandListImmediate& RHICmdList, FTextureRenderTargetResource* OutputRenderTargetResource,
	ERHIFeatureLevel::Type FeatureLevel, FName TextureRenderTargetName, FLinearColor MyColor, FTextureReferenceRHIRef MyTexture)
{
	check(IsInRenderingThread());

#if WANTS_DRAW_MESH_EVENTS
	FString EventName;
	TextureRenderTargetName.ToString(EventName);
	SCOPED_DRAW_EVENTF(RHICmdList, ShaderPlugin_RenderToTarget, TEXT("ShaderPlugin_RenderToTarget %s"), *EventName);
#else
	SCOPED_GPU_EVENT(RHICmdList, DrawTestShaderRenderTarget_RenderThread);
#endif

	FRHITexture2D* RenderTargetTexture = OutputRenderTargetResource->GetRenderTargetTexture();

	RHICmdList.Transition(FRHITransitionInfo(RenderTargetTexture, ERHIAccess::SRVMask, ERHIAccess::RTV));
	FRHIRenderPassInfo RPInfo(RenderTargetTexture, ERenderTargetActions::DontLoad_Store);
	RHICmdList.BeginRenderPass(RPInfo, TEXT("DrawMyShader"));
	{
		// Get shaders.
		FGlobalShaderMap* GlobalShaderMap = GetGlobalShaderMap(FeatureLevel);
		TShaderMapRef<FMyShaderVS> VertexShader(GlobalShaderMap);
		TShaderMapRef<FMyShaderPS> PixelShader(GlobalShaderMap);

		FMyShaderVertexDeclaration VertexDec;
		VertexDec.InitRHI();
		
		// Set the graphic pipeline state.
		FGraphicsPipelineStateInitializer GraphicsPSOInit;
		RHICmdList.ApplyCachedRenderTargets(GraphicsPSOInit);
		GraphicsPSOInit.DepthStencilState = TStaticDepthStencilState<false, CF_Always>::GetRHI();
		GraphicsPSOInit.BlendState = TStaticBlendState<>::GetRHI();
		GraphicsPSOInit.RasterizerState = TStaticRasterizerState<>::GetRHI();
		GraphicsPSOInit.PrimitiveType = PT_TriangleStrip;
		GraphicsPSOInit.BoundShaderState.VertexDeclarationRHI = VertexDec.VertexDeclarationRHI;
		GraphicsPSOInit.BoundShaderState.VertexShaderRHI = VertexShader.GetVertexShader();
		GraphicsPSOInit.BoundShaderState.PixelShaderRHI = PixelShader.GetPixelShader();
		SetGraphicsPipelineState(RHICmdList, GraphicsPSOInit);
		
		PixelShader->SetParameters(RHICmdList, MyColor, MyTexture);

		RHICmdList.SetStreamSource(0, GMyShaderQuadVertexBuffer.VertexBufferRHI, 0);
		RHICmdList.DrawPrimitive(0, 2, 1);
	}
	RHICmdList.EndRenderPass();
	RHICmdList.Transition(FRHITransitionInfo(RenderTargetTexture, ERHIAccess::RTV, ERHIAccess::SRVMask));
}

void UTestShaderBlueprintLibrary::DrawMyShader2RenderTarget(UTextureRenderTarget2D* OutputRenderTarget, FLinearColor Color, UTexture* Texture)
{
	check(IsInGameThread());
	if (!OutputRenderTarget)
	{
		UE_LOG(LogTemp, Warning, TEXT("OutputRenderTarget is not valid"));
		return;
	}

	FTextureRenderTargetResource* TextureRenderTargetResource = OutputRenderTarget->GameThread_GetRenderTargetResource();
	if (!TextureRenderTargetResource)
	{
		UE_LOG(LogTemp, Warning, TEXT("TextureRenderTargetResource is not valid"));
		return;
	}

	FTextureReferenceRHIRef TextureRHI= Texture->TextureReference.TextureReferenceRHI;

	ENQUEUE_RENDER_COMMAND(CaptureCommand)
	(
		[TextureRenderTargetResource, Color, TextureRHI](FRHICommandListImmediate& RHICmdList)
		{
			DrawTestShaderRenderTarget_RenderThread(RHICmdList, TextureRenderTargetResource, GMaxRHIFeatureLevel, FName("MyShader"), Color, TextureRHI);
		}
	);
}

IMPLEMENT_SHADER_TYPE(, FMyShaderVS, TEXT("/Plugin/MyCGPlugin/MyShader.usf"), TEXT("MainVS"), SF_Vertex)
IMPLEMENT_SHADER_TYPE(, FMyShaderPS, TEXT("/Plugin/MyCGPlugin/MyShader.usf"), TEXT("MainPS"), SF_Pixel)
