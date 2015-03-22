// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;
using System.IO;
using System;

/// Static build helpers class
namespace Dev {
	public class Build {

		/// Log a message during the build
		public static void Log(string msg) {
			UnrealBuildTool.Log.TraceError(msg);
		}
	}
}

public class HelloWorldTarget : TargetRules
{
	public HelloWorldTarget(TargetInfo Target)
	{
		Type = TargetType.Game;
	}

	//
	// TargetRules interface.
	//
	public override void SetupBinaries(
		TargetInfo Target,
		ref List<UEBuildBinaryConfiguration> OutBuildBinaryConfigurations,
		ref List<string> OutExtraModuleNames
		)
	{
		OutExtraModuleNames.AddRange( new string[] { "HelloWorld" } );
	}
}
