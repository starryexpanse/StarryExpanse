#include "VRPlayerController.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "Runtime/Engine/Classes/GameFramework/Pawn.h"
#include "Runtime/Engine/Classes/Engine/World.h"

AVRPlayerController::AVRPlayerController() {}

void AVRPlayerController::BeginPlayingState() { Super::BeginPlayingState(); }

void AVRPlayerController::SetupInputComponent() {
  Super::SetupInputComponent();
}
