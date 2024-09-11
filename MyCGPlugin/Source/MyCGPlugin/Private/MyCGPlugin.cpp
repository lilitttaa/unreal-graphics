// Copyright Epic Games, Inc. All Rights Reserved.

#include "MyCGPlugin.h"

#include "Interfaces/IPluginManager.h"

#define LOCTEXT_NAMESPACE "FMyCGPluginModule"

void FMyCGPluginModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	FString PluginShaderDir = FPaths::Combine(IPluginManager::Get().FindPlugin(TEXT("MyCGPlugin"))->GetBaseDir(), TEXT("Shaders"));
	AddShaderSourceDirectoryMapping(TEXT("/Plugin/MyCGPlugin"), PluginShaderDir);
}

void FMyCGPluginModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FMyCGPluginModule, MyCGPlugin)