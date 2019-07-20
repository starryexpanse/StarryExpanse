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

  static ConstructorHelpers::FClassFinder<APawn> VrPawnClassFinder(
      //    TEXT("/Game/StarryExpanse/Core/Player/VR/BP_VRCharacter"));
      TEXT("/Game/VirtualRealityBP/Blueprints/MotionControllerPawn"));
  VrPawnClass = VrPawnClassFinder.Class;

  // set default pawn class to our Blueprinted character
  PlayerControllerClass = AStrangerController::StaticClass();

  static ConstructorHelpers::FClassFinder<AStarryExpanseHUD> HudClassFinder(
      TEXT("/Game/StarryExpanse/Interface/Widgets/BP_HUD_Root.BP_HUD_Root_C"));

  HUDClass = HudClassFinder.Class;

  GameStateClass = ARivenGameState::StaticClass();

  // use our custom HUD class
  // HUDClass = AStarryExpanseHUD::StaticClass();
}
