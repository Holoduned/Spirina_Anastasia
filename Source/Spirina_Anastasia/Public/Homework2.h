#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Homework2.generated.h"

UCLASS()
class SPIRINA_ANASTASIA_API AHomework2 final : public AActor
{
	GENERATED_BODY()
 
public: 
	// Sets default values for this actor's properties
	AHomework2();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Color")
	float ColorInterval;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Metallic")
	float MetallicInterval;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UMaterialInstanceDynamic* Mesh1Material;
	UMaterialInstanceDynamic* Mesh2Material;
	FTimerHandle ColorTimerHandle;
	FTimerHandle MetallicTimerHandle;
	int32 NumColorChanges;
	int32 NumMetallicChanges;

	void ChangeMesh1Color();
	void ChangeMesh2Metallic();
};