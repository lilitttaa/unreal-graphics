// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UTextureRenderTarget2D;
struct FLinearColor;
#ifdef MYCGPLUGIN_TestShaderBlueprintLibrary_generated_h
#error "TestShaderBlueprintLibrary.generated.h already included, missing '#pragma once' in TestShaderBlueprintLibrary.h"
#endif
#define MYCGPLUGIN_TestShaderBlueprintLibrary_generated_h

#define EM_Plugins_MyCGPlugin_Source_MyCGPlugin_Public_TestShaderBlueprintLibrary_h_23_SPARSE_DATA
#define EM_Plugins_MyCGPlugin_Source_MyCGPlugin_Public_TestShaderBlueprintLibrary_h_23_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execDrawMyShader2RenderTarget);


#define EM_Plugins_MyCGPlugin_Source_MyCGPlugin_Public_TestShaderBlueprintLibrary_h_23_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execDrawMyShader2RenderTarget);


#define EM_Plugins_MyCGPlugin_Source_MyCGPlugin_Public_TestShaderBlueprintLibrary_h_23_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUTestShaderBlueprintLibrary(); \
	friend struct Z_Construct_UClass_UTestShaderBlueprintLibrary_Statics; \
public: \
	DECLARE_CLASS(UTestShaderBlueprintLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/MyCGPlugin"), NO_API) \
	DECLARE_SERIALIZER(UTestShaderBlueprintLibrary)


#define EM_Plugins_MyCGPlugin_Source_MyCGPlugin_Public_TestShaderBlueprintLibrary_h_23_INCLASS \
private: \
	static void StaticRegisterNativesUTestShaderBlueprintLibrary(); \
	friend struct Z_Construct_UClass_UTestShaderBlueprintLibrary_Statics; \
public: \
	DECLARE_CLASS(UTestShaderBlueprintLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/MyCGPlugin"), NO_API) \
	DECLARE_SERIALIZER(UTestShaderBlueprintLibrary)


#define EM_Plugins_MyCGPlugin_Source_MyCGPlugin_Public_TestShaderBlueprintLibrary_h_23_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UTestShaderBlueprintLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UTestShaderBlueprintLibrary) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UTestShaderBlueprintLibrary); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UTestShaderBlueprintLibrary); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UTestShaderBlueprintLibrary(UTestShaderBlueprintLibrary&&); \
	NO_API UTestShaderBlueprintLibrary(const UTestShaderBlueprintLibrary&); \
public:


#define EM_Plugins_MyCGPlugin_Source_MyCGPlugin_Public_TestShaderBlueprintLibrary_h_23_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UTestShaderBlueprintLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UTestShaderBlueprintLibrary(UTestShaderBlueprintLibrary&&); \
	NO_API UTestShaderBlueprintLibrary(const UTestShaderBlueprintLibrary&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UTestShaderBlueprintLibrary); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UTestShaderBlueprintLibrary); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UTestShaderBlueprintLibrary)


#define EM_Plugins_MyCGPlugin_Source_MyCGPlugin_Public_TestShaderBlueprintLibrary_h_23_PRIVATE_PROPERTY_OFFSET
#define EM_Plugins_MyCGPlugin_Source_MyCGPlugin_Public_TestShaderBlueprintLibrary_h_20_PROLOG
#define EM_Plugins_MyCGPlugin_Source_MyCGPlugin_Public_TestShaderBlueprintLibrary_h_23_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	EM_Plugins_MyCGPlugin_Source_MyCGPlugin_Public_TestShaderBlueprintLibrary_h_23_PRIVATE_PROPERTY_OFFSET \
	EM_Plugins_MyCGPlugin_Source_MyCGPlugin_Public_TestShaderBlueprintLibrary_h_23_SPARSE_DATA \
	EM_Plugins_MyCGPlugin_Source_MyCGPlugin_Public_TestShaderBlueprintLibrary_h_23_RPC_WRAPPERS \
	EM_Plugins_MyCGPlugin_Source_MyCGPlugin_Public_TestShaderBlueprintLibrary_h_23_INCLASS \
	EM_Plugins_MyCGPlugin_Source_MyCGPlugin_Public_TestShaderBlueprintLibrary_h_23_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define EM_Plugins_MyCGPlugin_Source_MyCGPlugin_Public_TestShaderBlueprintLibrary_h_23_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	EM_Plugins_MyCGPlugin_Source_MyCGPlugin_Public_TestShaderBlueprintLibrary_h_23_PRIVATE_PROPERTY_OFFSET \
	EM_Plugins_MyCGPlugin_Source_MyCGPlugin_Public_TestShaderBlueprintLibrary_h_23_SPARSE_DATA \
	EM_Plugins_MyCGPlugin_Source_MyCGPlugin_Public_TestShaderBlueprintLibrary_h_23_RPC_WRAPPERS_NO_PURE_DECLS \
	EM_Plugins_MyCGPlugin_Source_MyCGPlugin_Public_TestShaderBlueprintLibrary_h_23_INCLASS_NO_PURE_DECLS \
	EM_Plugins_MyCGPlugin_Source_MyCGPlugin_Public_TestShaderBlueprintLibrary_h_23_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> MYCGPLUGIN_API UClass* StaticClass<class UTestShaderBlueprintLibrary>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID EM_Plugins_MyCGPlugin_Source_MyCGPlugin_Public_TestShaderBlueprintLibrary_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
