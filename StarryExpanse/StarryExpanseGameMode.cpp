// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "StarryExpanseGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "EverPresent/StrangerController.h"
#include "RivenGameState.h"
#include "StarryExpanseHUD.h"
#include "UObject/ConstructorHelpers.h"

AStarryExpanseGameMode::AStarryExpanseGameMode() : Super() {
  // set default pawn class to our Blueprinted character
  static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(
      TEXT("/Game/FirstPersonBP/Blueprints/FirstPersonCharacter"));
  DefaultPawnClass = PlayerPawnClassFinder.Class;

  // set default pawn class to our Blueprinted character
  PlayerControllerClass = AStrangerController::StaticClass();

  static ConstructorHelpers::FClassFinder<AHUD> HudClassFinder(
      TEXT("/Game/StarryExpanse/Core/Engine/Gui/loadingHUD"));
  HUDClass = HudClassFinder.Class;

  GameStateClass = ARivenGameState::StaticClass();

  // use our custom HUD class
  // HUDClass = AStarryExpanseHUD::StaticClass();
}
