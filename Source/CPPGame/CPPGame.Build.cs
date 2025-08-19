// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class CPPGame : ModuleRules
{
	public CPPGame(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
