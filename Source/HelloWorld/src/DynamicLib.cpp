#include "HelloWorld.h"
#include "DynamicLib.h"
#include "Runtime/Core/Public/HAL/FileManagerGeneric.h"

// Extern decl
typedef int32(*rs_trigger)(int32 value, void (*handle)(int32));

int32 DynamicLib::thing()
{
  int32 rtn = -1;

  // Get library ext
  #if PLATFORM_WINDOWS
    FString libpath = TEXT("dll");
  #elif PLATFORM_MAC
    FString libext = TEXT("dylib");
  #elif PLATFORM_LINUX
    FString libpath = TEXT("so");
  #else
    NOT IMPLEMENTED
  #endif

  // Find library, if any
  TArray<FString> output;
  FString seek = FPaths::Combine(*FPaths::GamePluginsDir(), TEXT("rust-extern/target/debug/*"));
  UE_LOG(LogTemp, Warning, TEXT("Seek: %s"), *seek);
  FFileManagerGeneric::Get().FindFiles(output, *seek, true, false);
  FString filePath = TEXT("Nope");
  for (int32 i = 0; i < output.Num(); i++) {
    UE_LOG(LogTemp, Warning, TEXT("Path: %s"), *output[i]);
    if (output[i].EndsWith(libext, ESearchCase::IgnoreCase)) {
      filePath = FPaths::Combine(*FPaths::GamePluginsDir(), TEXT("rust-extern/target/debug/"), *output[i]);
      UE_LOG(LogTemp, Warning, TEXT("FOUND A MATCH"));
      break;
    }
  }
  UE_LOG(LogTemp, Warning, TEXT("Attempting to open library: %s"), *filePath);

  if (FPaths::FileExists(filePath))
  {
    UE_LOG(LogTemp, Warning, TEXT("File exists!"));
    void *DLLHandle;
    DLLHandle = FPlatformProcess::GetDllHandle(*filePath); // Retrieve the DLL.
    if (DLLHandle != NULL)
    {
      UE_LOG(LogTemp, Warning, TEXT("Valid lib."));
      FString procName = "rs_trigger";
      rs_trigger fp = NULL;
      fp = (rs_trigger) FPlatformProcess::GetDllExport(DLLHandle, *procName);
      if (fp != NULL) {
        UE_LOG(LogTemp, Warning, TEXT("Valid sym."));
        rtn = (* fp) (1, &actions::perform_action);
        UE_LOG(LogTemp, Warning, TEXT("return: %d"), rtn);
        return rtn;
      }
      else {
        UE_LOG(LogTemp, Warning, TEXT("Invalid sym."));
      }
      FPlatformProcess::FreeDllHandle(DLLHandle);
    }
    else {
      UE_LOG(LogTemp, Warning, TEXT("Invalid lib."));
    }
  }
  else {
    UE_LOG(LogTemp, Warning, TEXT("Invalid file."));
  }
  return -1;
}

void actions::perform_action(int32 value) {
  UE_LOG(LogTemp, Warning, TEXT("Called with %d."), value);
}
