// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "TestShaderBlueprintLibrary.generated.h"


USTRUCT(BlueprintType)  
struct FMyShaderStructData  
{  
	GENERATED_USTRUCT_BODY()  
  
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = ShaderData)  
	FLinearColor ColorOne;  
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = ShaderData)  
	FLinearColor ColorTwo;  
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = ShaderData)  
	FLinearColor Colorthree;  
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = ShaderData)  
	FLinearColor ColorFour;  
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = ShaderData)  
	int32 ColorIndex;  
}; 

static void DrawTestShaderRenderTarget_RenderThread(
	FRHICommandListImmediate& RHICmdList,
	FTextureRenderTargetResource* OutputRenderTargetResource,
	ERHIFeatureLevel::Type FeatureLevel,
	FName TextureRenderTargetName,
	FLinearColor MyColor
);

BEGIN_GLOBAL_SHADER_PARAMETER_STRUCT(FMyShaderColorUniformParamater, MYCGPLUGIN_API)
SHADER_PARAMETER(FVector4, ColorOne)
SHADER_PARAMETER(FVector4, ColorTwo)
SHADER_PARAMETER(FVector4, ColorThree)
SHADER_PARAMETER(FVector4, ColorFour)
SHADER_PARAMETER(int, ColorIndex)
END_GLOBAL_SHADER_PARAMETER_STRUCT()


/**
 * 
 */
UCLASS()
class MYCGPLUGIN_API UTestShaderBlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "MyCGPlugin")
	static void DrawMyShader2RenderTarget(UTextureRenderTarget2D* OutputRenderTarget, const FMyShaderStructData& ColorData,UTexture* Texture);
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

	void SetParameters(FRHICommandListImmediate& RHICmdList, const FMyShaderStructData& ColorData, FTextureReferenceRHIRef Texture)
	{
		SetTextureParameter(RHICmdList, RHICmdList.GetBoundPixelShader(), MyTextureParameter, MyTextureSamplerParameter,
			TStaticSamplerState<SF_Bilinear, AM_Clamp, AM_Clamp, AM_Clamp>::GetRHI(), Texture);
		FMyShaderColorUniformParamater UniformParam;
		UniformParam.ColorOne = FVector4(ColorData.ColorOne);
		UniformParam.ColorTwo = FVector4(ColorData.ColorTwo);
		UniformParam.ColorThree = FVector4(ColorData.Colorthree);
		UniformParam.ColorFour = FVector4(ColorData.ColorFour);
		UniformParam.ColorIndex = ColorData.ColorIndex;
		SetUniformBufferParameterImmediate(RHICmdList, RHICmdList.GetBoundPixelShader(), GetUniformBufferParameter<FMyShaderColorUniformParamater>(), UniformParam);
	}
private:
	LAYOUT_FIELD(FShaderParameter, MyColorParameter);
	LAYOUT_FIELD(FShaderResourceParameter, MyTextureParameter);
	LAYOUT_FIELD(FShaderResourceParameter, MyTextureSamplerParameter);
};


