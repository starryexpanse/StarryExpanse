// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "StarryExpanseGameMode.h"
#include "StarryExpanseHUD.h"
#include "UObject/ConstructorHelpers.h"

AStarryExpanseGameMode::AStarryExpanseGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Content/FirstPersonBP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AStarryExpanseHUD::StaticClass();
}
