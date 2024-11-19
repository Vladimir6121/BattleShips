// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class BattleShips : ModuleRules
{
	public BattleShips(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
