// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "TestShaderBlueprintLibrary.generated.h"

static void DrawTestShaderRenderTarget_RenderThread(
	FRHICommandListImmediate& RHICmdList,
	FTextureRenderTargetResource* OutputRenderTargetResource,
	ERHIFeatureLevel::Type FeatureLevel,
	FName TextureRenderTargetName,
	FLinearColor MyColor
);

/**
 * 
 */
UCLASS()
class MYCGPLUGIN_API UTestShaderBlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "MyCGPlugin")
	static void DrawMyShader2RenderTarget(UTextureRenderTarget2D* OutputRenderTarget, FLinearColor Color, UTexture* Texture);
};

class FMyShader : public FGlobalShader
{
public:
	FMyShader() {}

	FMyShader(const ShaderMetaType::CompiledShaderInitializerType& Initializer)
		: FGlobalShader(Initializer) {  }

	static bool ShouldCache(EShaderPlatform Platform) { return true; }

	static void ModifyCompilationEnvironment(const FGlobalShaderPermutationParameters& Parameters, FShaderCompilerEnvironment& OutEnvironment)
	{
		FGlobalShader::ModifyCompilationEnvironment(Parameters, OutEnvironment);
		OutEnvironment.SetDefine(TEXT("MY_DEFINE"), 1);
	}

	static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters& Parameters) { return true; }
};

class FMyShaderVS : public FMyShader
{
	DECLARE_SHADER_TYPE(FMyShaderVS, Global);

public:
	FMyShaderVS(){}

	FMyShaderVS(const ShaderMetaType::CompiledShaderInitializerType& Initializer)
		: FMyShader(Initializer) {}
};


class FMyShaderPS : public FMyShader
{
	DECLARE_SHADER_TYPE(FMyShaderPS, Global);
public:
	FMyShaderPS(){}

	FMyShaderPS(const ShaderMetaType::CompiledShaderInitializerType& Initializer)
		: FMyShader(Initializer)
	{
		MyColorParameter.Bind(Initializer.ParameterMap, TEXT("MyColor"));
		MyTextureParameter.Bind(Initializer.ParameterMap, TEXT("MyTexture"));
		MyTextureSamplerParameter.Bind(Initializer.ParameterMap, TEXT("MyTextureSampler"));
	}

	void SetParameters(FRHICommandListImmediate& RHICmdList, FLinearColor Color, FTextureReferenceRHIRef Texture)
	{
		SetShaderValue(RHICmdList, RHICmdList.GetBoundPixelShader(), MyColorParameter, Color);
		SetTextureParameter(RHICmdList, RHICmdList.GetBoundPixelShader(), MyTextureParameter, MyTextureSamplerParameter,
			TStaticSamplerState<SF_Bilinear, AM_Clamp, AM_Clamp, AM_Clamp>::GetRHI(), Texture);
		SetShaderValue(RHICmdList, RHICmdList.GetBoundPixelShader(), MyColorParameter, Color);
	}
private:
	LAYOUT_FIELD(FShaderParameter, MyColorParameter);
	LAYOUT_FIELD(FShaderResourceParameter, MyTextureParameter);
	LAYOUT_FIELD(FShaderResourceParameter, MyTextureSamplerParameter);
};


