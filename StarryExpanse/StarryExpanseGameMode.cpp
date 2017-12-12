// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "StarryExpanseGameMode.h"
#include "StarryExpanseHUD.h"
#include "RivenGameState.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"

AStarryExpanseGameMode::AStarryExpanseGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(
		TEXT("/Game/FirstPersonBP/Blueprints/FirstPersonCharacter")
	);
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<AController> PlayerControllerClassFinder(
		TEXT("/Game/StarryExpanse/Core/Engine/RivenPlayerController")
	);
	PlayerControllerClass = PlayerControllerClassFinder.Class;

  static ConstructorHelpers::FClassFinder<AHUD> HudClassFinder(
    TEXT("/Game/StarryExpanse/Core/Engine/Gui/loadingHUD")
  );
  HUDClass = HudClassFinder.Class;

  GameStateClass = ARivenGameState::StaticClass();

	// use our custom HUD class
	// HUDClass = AStarryExpanseHUD::StaticClass();
}
