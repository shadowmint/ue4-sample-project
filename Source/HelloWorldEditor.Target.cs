// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;
using System;

public class HelloWorldEditorTarget : TargetRules
{
	public HelloWorldEditorTarget(TargetInfo Target)
	{
		Type = TargetType.Editor;
		AdditionalPlugins.Add("TestPlugin");
		Dev.Build.Log("Message Here");
		//PublicDependencyModuleNames.AddRange(new string[] { "TestPlugin" });
		// throw new NotImplementedException();
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
