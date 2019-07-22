// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.IO;

public class StarryExpanse : ModuleRules
{
	public StarryExpanse(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"OnlineSubsystemUtils",
			"UMG"
		});

		PrivateDependencyModuleNames.AddRange(new string[] {
			"HeadMountedDisplay",
			"SteamVR",
			"SteamVRController"
		});

		var ThirdPartyPath = Path.Combine( ModuleDirectory, "../../ThirdParty/" );
		var IncludesPath = Path.Combine(ThirdPartyPath, "BoostInternalLibrary", "includes");

		PublicIncludePaths.Add(IncludesPath);
		PublicSystemIncludePaths.Add(IncludesPath);
	}
}
