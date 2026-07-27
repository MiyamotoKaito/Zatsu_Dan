// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Zatsu_Dan : ModuleRules
{
	public Zatsu_Dan(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"Zatsu_Dan",
			"Zatsu_Dan/Variant_Horror",
			"Zatsu_Dan/Variant_Horror/UI",
			"Zatsu_Dan/Variant_Shooter",
			"Zatsu_Dan/Variant_Shooter/AI",
			"Zatsu_Dan/Variant_Shooter/UI",
			"Zatsu_Dan/Variant_Shooter/Weapons"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
