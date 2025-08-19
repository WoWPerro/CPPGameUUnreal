// Copyright Epic Games, Inc. All Rights Reserved.

#include "CPPGameGameMode.h"
#include "CPPGameCharacter.h"
#include "UObject/ConstructorHelpers.h"

ACPPGameGameMode::ACPPGameGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
