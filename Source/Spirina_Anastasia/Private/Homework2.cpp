#include "Homework2.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInstanceDynamic.h"

// Sets default values
AHomework2::AHomework2()
{
  // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
 PrimaryActorTick.bCanEverTick = false;

 // Create and attach two static mesh components
 UStaticMeshComponent* Mesh1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh1"));
 RootComponent = Mesh1;

 UStaticMeshComponent* Mesh2 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh2"));
 Mesh2->SetupAttachment(RootComponent);

 // Set default values for properties
 ColorInterval = 1.0f;
 MetallicInterval = 1.0f;

 // Initialize material instances for both meshes
 Mesh1Material = Mesh1->CreateAndSetMaterialInstanceDynamic(0);
 Mesh2Material = Mesh2->CreateAndSetMaterialInstanceDynamic(0);

 // Initialize timer handles
 ColorTimerHandle.Invalidate();
 MetallicTimerHandle.Invalidate();

 // Initialize counters for number of changes
 NumColorChanges = 0;
 NumMetallicChanges = 0;
}

// Called when the game starts or when spawned
void AHomework2::BeginPlay()
{
 Super::BeginPlay();
 
 // Start timers for color and metallic changes
 GetWorldTimerManager().SetTimer(ColorTimerHandle, this, &AHomework2::ChangeMesh1Color, ColorInterval, true);
 GetWorldTimerManager().SetTimer(MetallicTimerHandle, this, &AHomework2::ChangeMesh2Metallic, MetallicInterval, true);
}

void AHomework2::ChangeMesh1Color()
{
 // Check if maximum number of color changes has been reached
 if (NumColorChanges >= 5)
 {
  // Reset timer and counter
  GetWorldTimerManager().ClearTimer(ColorTimerHandle);
  ColorTimerHandle.Invalidate();
  NumColorChanges = 0;
  return;
 }

 // Get current base color of mesh 1
 FLinearColor BaseColor;
 Mesh1Material->GetVectorParameterValue(TEXT("BaseColor"), BaseColor);

 // Change base color to red or blue
 if (BaseColor.R == 1.0f && BaseColor.G == 0.0f && BaseColor.B == 0.0f)
 {
  BaseColor = FLinearColor(0.0f, 0.0f, 1.0f);
 }
 else
 {
  BaseColor = FLinearColor(1.0f, 0.0f, 0.0f);
 }

 // Set new base color for mesh 1
 Mesh1Material->SetVectorParameterValue(TEXT("BaseColor"), BaseColor);

 // Increment counter for number of color changes
 NumColorChanges++;
}

void AHomework2::ChangeMesh2Metallic()
{
 // Check if maximum number of metallic changes has been reached
 if (NumMetallicChanges >= 5)
 {
  // Reset timer and counter
  GetWorldTimerManager().ClearTimer(MetallicTimerHandle);
  MetallicTimerHandle.Invalidate();
  NumMetallicChanges = 0;
  return;
 }

 // Get current metallic value of mesh 2
 float Metallic;
 Mesh2Material->GetScalarParameterValue(TEXT("Metallic"), Metallic);

 // Change metallic value to 0 or 1
 if (Metallic == 1.0f)
 {
  Metallic = 0.0f;
 }
 else
 {
  Metallic = 1.0f;
 }

 // Set new metallic value for mesh 2
 Mesh2Material->SetScalarParameterValue(TEXT("Metallic"), Metallic);

 // Increment counter for number of metallic changes
 NumMetallicChanges++; 
}