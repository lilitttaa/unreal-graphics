// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MyCGPlugin/Public/TestShaderBlueprintLibrary.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTestShaderBlueprintLibrary() {}
// Cross Module References
	MYCGPLUGIN_API UClass* Z_Construct_UClass_UTestShaderBlueprintLibrary_NoRegister();
	MYCGPLUGIN_API UClass* Z_Construct_UClass_UTestShaderBlueprintLibrary();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	UPackage* Z_Construct_UPackage__Script_MyCGPlugin();
	ENGINE_API UClass* Z_Construct_UClass_UTextureRenderTarget2D_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor();
// End Cross Module References
	DEFINE_FUNCTION(UTestShaderBlueprintLibrary::execDrawMyShader2RenderTarget)
	{
		P_GET_OBJECT(UTextureRenderTarget2D,Z_Param_OutputRenderTarget);
		P_GET_STRUCT(FLinearColor,Z_Param_Color);
		P_FINISH;
		P_NATIVE_BEGIN;
		UTestShaderBlueprintLibrary::DrawMyShader2RenderTarget(Z_Param_OutputRenderTarget,Z_Param_Color);
		P_NATIVE_END;
	}
	void UTestShaderBlueprintLibrary::StaticRegisterNativesUTestShaderBlueprintLibrary()
	{
		UClass* Class = UTestShaderBlueprintLibrary::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "DrawMyShader2RenderTarget", &UTestShaderBlueprintLibrary::execDrawMyShader2RenderTarget },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UTestShaderBlueprintLibrary_DrawMyShader2RenderTarget_Statics
	{
		struct TestShaderBlueprintLibrary_eventDrawMyShader2RenderTarget_Parms
		{
			UTextureRenderTarget2D* OutputRenderTarget;
			FLinearColor Color;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OutputRenderTarget;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Color;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UTestShaderBlueprintLibrary_DrawMyShader2RenderTarget_Statics::NewProp_OutputRenderTarget = { "OutputRenderTarget", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(TestShaderBlueprintLibrary_eventDrawMyShader2RenderTarget_Parms, OutputRenderTarget), Z_Construct_UClass_UTextureRenderTarget2D_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UTestShaderBlueprintLibrary_DrawMyShader2RenderTarget_Statics::NewProp_Color = { "Color", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(TestShaderBlueprintLibrary_eventDrawMyShader2RenderTarget_Parms, Color), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UTestShaderBlueprintLibrary_DrawMyShader2RenderTarget_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UTestShaderBlueprintLibrary_DrawMyShader2RenderTarget_Statics::NewProp_OutputRenderTarget,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UTestShaderBlueprintLibrary_DrawMyShader2RenderTarget_Statics::NewProp_Color,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UTestShaderBlueprintLibrary_DrawMyShader2RenderTarget_Statics::Function_MetaDataParams[] = {
		{ "Category", "MyCGPlugin" },
		{ "ModuleRelativePath", "Public/TestShaderBlueprintLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UTestShaderBlueprintLibrary_DrawMyShader2RenderTarget_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UTestShaderBlueprintLibrary, nullptr, "DrawMyShader2RenderTarget", nullptr, nullptr, sizeof(TestShaderBlueprintLibrary_eventDrawMyShader2RenderTarget_Parms), Z_Construct_UFunction_UTestShaderBlueprintLibrary_DrawMyShader2RenderTarget_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UTestShaderBlueprintLibrary_DrawMyShader2RenderTarget_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04822401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UTestShaderBlueprintLibrary_DrawMyShader2RenderTarget_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UTestShaderBlueprintLibrary_DrawMyShader2RenderTarget_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UTestShaderBlueprintLibrary_DrawMyShader2RenderTarget()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UTestShaderBlueprintLibrary_DrawMyShader2RenderTarget_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UTestShaderBlueprintLibrary_NoRegister()
	{
		return UTestShaderBlueprintLibrary::StaticClass();
	}
	struct Z_Construct_UClass_UTestShaderBlueprintLibrary_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UTestShaderBlueprintLibrary_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_MyCGPlugin,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UTestShaderBlueprintLibrary_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UTestShaderBlueprintLibrary_DrawMyShader2RenderTarget, "DrawMyShader2RenderTarget" }, // 582402048
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UTestShaderBlueprintLibrary_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "TestShaderBlueprintLibrary.h" },
		{ "ModuleRelativePath", "Public/TestShaderBlueprintLibrary.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UTestShaderBlueprintLibrary_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UTestShaderBlueprintLibrary>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UTestShaderBlueprintLibrary_Statics::ClassParams = {
		&UTestShaderBlueprintLibrary::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UTestShaderBlueprintLibrary_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UTestShaderBlueprintLibrary_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UTestShaderBlueprintLibrary()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UTestShaderBlueprintLibrary_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UTestShaderBlueprintLibrary, 4121109547);
	template<> MYCGPLUGIN_API UClass* StaticClass<UTestShaderBlueprintLibrary>()
	{
		return UTestShaderBlueprintLibrary::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UTestShaderBlueprintLibrary(Z_Construct_UClass_UTestShaderBlueprintLibrary, &UTestShaderBlueprintLibrary::StaticClass, TEXT("/Script/MyCGPlugin"), TEXT("UTestShaderBlueprintLibrary"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UTestShaderBlueprintLibrary);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
