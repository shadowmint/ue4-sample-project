// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "Foo.generated.h"

/**
 *
 */
UCLASS()
class HELLOWORLD_API UFoo : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	public:
		UFUNCTION(BlueprintCallable, Category = "GlobalFunctions")
		static int32 GetHappyMessage();
};
