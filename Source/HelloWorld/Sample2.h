// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Shared.h"
#include "GameFramework/Actor.h"
#include "Sample2.generated.h"

UCLASS()
class HELLOWORLD_API ASample2 : public AActor
{
	GENERATED_BODY()

public:

	// Or TWeakObjectPtr or whatever
	ASample1 *one;

	// Sets default values for this actor's properties
	ASample2();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;



};
