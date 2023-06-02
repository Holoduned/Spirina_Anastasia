// Fill out your copyright notice in the Description page of Project Settings.


#include "Loging.h"

// Sets default values
ALoging::ALoging()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ALoging::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALoging::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UE_LOG(LogTemp, Warning, TEXT("Hello"));

}

