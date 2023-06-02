// Copyright Epic Games, Inc. All Rights Reserved.

#include "Spirina_AnastasiaGameMode.h"
#include "Spirina_AnastasiaCharacter.h"
#include "UObject/ConstructorHelpers.h"

ASpirina_AnastasiaGameMode::ASpirina_AnastasiaGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
