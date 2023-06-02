#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Homework1.generated.h"

UCLASS()
class SPIRINA_ANASTASIA_API AHomework1 : public ACharacter
{
	GENERATED_BODY()

public:
	AHomework1();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};