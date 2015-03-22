// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.IO;

public class HelloWorld : ModuleRules
{
	public HelloWorld(TargetInfo Target)
	{
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });

		PrivateDependencyModuleNames.AddRange(new string[] { "TestPlugin" });

		/*var module_path = Path.GetFullPath(Path.GetDirectoryName(RulesCompiler.GetModuleFilename(this.GetType().Name)));
		var plugin = Path.Combine(module_path, "../../Plugins/rust-extern/");
		var plugin_lib_path = Path.Combine(plugin, "target/debug");
		var plugin_lib = Path.Combine(plugin_lib_path, "libextern.a");
		var plugin_headers = Path.Combine(plugin, "include");
		Log.TraceError(plugin);
		Log.TraceError(plugin_lib);
		Log.TraceError(plugin_headers);
		PublicIncludePaths.Add(plugin_headers);
		PublicAdditionalLibraries.Add(plugin_lib);
		Definitions.Add(string.Format("WITH_RS_BINDING=1"));*/


		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");
		// if ((Target.Platform == UnrealTargetPlatform.Win32) || (Target.Platform == UnrealTargetPlatform.Win64))
		// {
		//		if (UEBuildConfiguration.bCompileSteamOSS == true)
		//		{
		//			DynamicallyLoadedModuleNames.Add("OnlineSubsystemSteam");
		//		}
		// }
	}
}
