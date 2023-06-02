// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Spirina_Anastasia : ModuleRules
{
	public Spirina_Anastasia(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput" });
	}
}
