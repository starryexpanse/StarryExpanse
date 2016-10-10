#include "StarryExpanse.h"
#include "Base/GUI/SEHUD.h"
#include "Base/Character/SECharacter.h"
#include "Base/Character/SECharacterController.h"
#include "Base/Character/SECharacterState.h"
#include "SEGameMode.h"
#include "EverPresent/EverpresentLoadGroupManager.h"


ASEGameMode::ASEGameMode() : Super()
{
  // Use our custom Character pawn class
  DefaultPawnClass = ASECharacter::StaticClass();

  // Use our custom PlayerController class
  PlayerControllerClass = ASECharacterController::StaticClass();

  // Use our custom PlayerState class
  PlayerStateClass = ASECharacterState::StaticClass();

  // Use our custom HUD class
  HUDClass = ASEHUD::StaticClass();


  // Components
  LoadGroupManagerComponent = CreateDefaultSubobject<ULoadGroupManagerComponent>(
    TEXT("LoadGroupManager")
  );
}

void ASEGameMode::BeginPlay() {


  if (LoadGroupManagerComponent) {
    LoadGroupManagerComponent->InferLoadedLevels();
  }
}
