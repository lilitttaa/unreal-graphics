// Fill out your copyright notice in the Description page of Project Settings.

#include "TestShaderBlueprintLibrary.h"
#include "Engine/TextureRenderTarget2D.h"

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
		VertexBufferRHI = RHICreateVertexBuffer(sizeof(FVector4) * 4, BUF_Static, CreateInfo);
		void* VoidPtr   = RHILockVertexBuffer(VertexBufferRHI, 0, sizeof(FVector4) * 4, RLM_WriteOnly);
		// Generate the vertices used
		FVector4* Vertices = reinterpret_cast<FVector4*>(VoidPtr);
		Vertices[0]        = FVector4(-1.0f, 1.0f, 0.0f, 1.0f);
		Vertices[1]        = FVector4(1.0f, 1.0f, 0.0f, 1.0f);
		Vertices[2]        = FVector4(-1.0f, -1.0f, 0.0f, 1.0f);
		Vertices[3]        = FVector4(1.0f, -1.0f, 0.0f, 1.0f);
		RHIUnlockVertexBuffer(VertexBufferRHI);
	}
};
TGlobalResource<FMyShaderQuadVertexBuffer> GMyShaderQuadVertexBuffer;
void DrawTestShaderRenderTarget_RenderThread(FRHICommandListImmediate& RHICmdList, FTextureRenderTargetResource* OutputRenderTargetResource,
	ERHIFeatureLevel::Type FeatureLevel, FName TextureRenderTargetName, FLinearColor MyColor)
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

		// Set the graphic pipeline state.
		FGraphicsPipelineStateInitializer GraphicsPSOInit;
		RHICmdList.ApplyCachedRenderTargets(GraphicsPSOInit);
		GraphicsPSOInit.DepthStencilState = TStaticDepthStencilState<false, CF_Always>::GetRHI();
		GraphicsPSOInit.BlendState = TStaticBlendState<>::GetRHI();
		GraphicsPSOInit.RasterizerState = TStaticRasterizerState<>::GetRHI();
		GraphicsPSOInit.PrimitiveType = PT_TriangleStrip;
		GraphicsPSOInit.BoundShaderState.VertexDeclarationRHI = GetVertexDeclarationFVector4();
		GraphicsPSOInit.BoundShaderState.VertexShaderRHI = VertexShader.GetVertexShader();
		GraphicsPSOInit.BoundShaderState.PixelShaderRHI = PixelShader.GetPixelShader();
		SetGraphicsPipelineState(RHICmdList, GraphicsPSOInit);
		
		PixelShader->SetParameters(RHICmdList, MyColor);

		RHICmdList.SetStreamSource(0, GMyShaderQuadVertexBuffer.VertexBufferRHI, 0);
		RHICmdList.DrawPrimitive(0, 2, 1);
	}
	RHICmdList.EndRenderPass();
	RHICmdList.Transition(FRHITransitionInfo(RenderTargetTexture, ERHIAccess::RTV, ERHIAccess::SRVMask));
}

void UTestShaderBlueprintLibrary::DrawMyShader2RenderTarget(UTextureRenderTarget2D* OutputRenderTarget, FLinearColor Color)
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

	ENQUEUE_RENDER_COMMAND(CaptureCommand)
	(
		[TextureRenderTargetResource, Color](FRHICommandListImmediate& RHICmdList)
		{
			DrawTestShaderRenderTarget_RenderThread(RHICmdList, TextureRenderTargetResource, GMaxRHIFeatureLevel, FName("MyShader"), Color);
		}
	);
}

IMPLEMENT_SHADER_TYPE(, FMyShaderVS, TEXT("/Plugin/MyCGPlugin/MyShader.usf"), TEXT("MainVS"), SF_Vertex)
IMPLEMENT_SHADER_TYPE(, FMyShaderPS, TEXT("/Plugin/MyCGPlugin/MyShader.usf"), TEXT("MainPS"), SF_Pixel)
