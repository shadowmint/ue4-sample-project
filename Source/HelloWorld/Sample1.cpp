// Fill out your copyright notice in the Description page of Project Settings.

#include "HelloWorld.h"
#include "Sample1.h"
#include "Sample2.h"

// Sets default values
ASample1::ASample1()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASample1::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ASample1::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}
