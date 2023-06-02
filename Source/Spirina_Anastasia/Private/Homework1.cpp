// Fill out your copyright notice in the Description page of Project Settings.


#include "Spirina_Anastasia/Public/Homework1.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInstanceDynamic.h"

// Sets default values
AHomework1::AHomework1()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AHomework1::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHomework1::Tick(float DeltaTime)
{
	UE_LOG(LogTemp, Display, TEXT("This is display"));
	UE_LOG(LogTemp, Warning, TEXT("This is warning"));
	UE_LOG(LogTemp, Error, TEXT("This is error"));
}

// Called to bind functionality to input
void AHomework1::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


