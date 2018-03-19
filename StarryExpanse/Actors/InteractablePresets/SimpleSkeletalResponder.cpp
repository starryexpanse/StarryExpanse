//
// Copyright, 59 Volt Entertainment, all rights reserved.
//
#include "SimpleSpinnerResponder.h"
#include "Engine/Engine.h"
#include "Kismet/GameplayStatics.h"
#include "RivenGameState.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"
#include "Runtime/Engine/Classes/Engine/EngineTypes.h"
#include "Runtime/Engine/Classes/Engine/GameViewportClient.h"
#include "Structs/InteractableSettingsAxial.h"

ASimpleSkeletalResponder::ASimpleSkeletalResponder(
    const FObjectInitializer &ObjectInitializer)
    : AActor(ObjectInitializer) {
  PrimaryActorTick.bCanEverTick = true;
  // TODO(cmumford): Should only enable ticks when animation is running.
  PrimaryActorTick.bStartWithTickEnabled = true;
  PrimaryActorTick.bAllowTickOnDedicatedServer = true;
}

void ASimpleSkeletalResponder::AnimationProgressCallback(float val) {
  SetRotation(val);
}

void ASimpleSkeletalResponder::AnimationDone() {
  auto gs = Cast<ARivenGameState>(GetWorld()->GetGameState());

  if (!gs) {
    return;
  }

  auto saveGame = gs->Instantaneous_SaveGame;

  if (!saveGame) {
    return;
  }

  auto at_end = m_timeline.GetPlaybackPosition() > 0; // TODO: "&& isAnimating"
  saveGame->SetBooleanBySaveGameField(m_save_game_field,
                                      at_end); // TODO: ^ is_false_at_end
}

void ASimpleSkeletalResponder::BeginPlay() { AActor::BeginPlay(); }

void ASimpleSkeletalResponder::Tick(float DeltaTime) {
  AActor::Tick(DeltaTime);
  m_timeline.TickTimeline(DeltaTime);
}

void ASimpleSkeletalResponder::Initialize(FInteractableSettingsAxial settings) {
  m_save_game_field = settings.SaveGameField;
  m_moveablePart = settings.MoveablePart;
  m_axis = settings.Axis;


  auto gs = Cast<ARivenGameState>(GetWorld()->GetGameState());
  if (!gs) {
    return;
  }

  auto saveGame = gs->Instantaneous_SaveGame;
  if (!saveGame) {
    return;
  }

  auto isInInitialPosition = !saveGame->GetBooleanBySaveGameField(
      m_save_game_field); // TODO: ^ is_false_at_end

  if (isInInitialPosition) {
    SetRotation(settings.AnimationStartValue);
    m_timeline.SetNewTime(0);
  } else {
    SetRotation(settings.AnimationEndValue);
    m_timeline.SetNewTime(settings.AnimationDuration);
  }
}

void ASimpleSkeletalResponder::LookingAt_Begin_Implementation() {
  
}

void ASimpleSkeletalResponder::LookingAt_End_Implementation() {}

void ASimpleSkeletalResponder::Extra_Drag_Details_Available_Implementation(
    FHitResult HitInfo) {}

FDragCallbackPreferences ASimpleSkeletalResponder::Drag_Begin_Implementation(
    FHitResult HitInfo, FVector2D Origin, AActor *DragOwner) {
  return FDragCallbackPreferences::NoUpdates();
}

void ASimpleSkeletalResponder::Drag_Finished_Implementation(
    FHitResult HitInfo, FVector2D Origin, FVector2D SmallDelta,
    FVector2D OverallDelta, bool WasDragCanceled) {}

void ASimpleSkeletalResponder::Touched_Implementation() {
  if (m_timeline.GetPlaybackPosition() > 0) {
    m_timeline.Reverse();
  } else {
    m_timeline.Play();
  }
}

FInteractabilityProbeResponse
ASimpleSkeletalResponder::ProbeInteractability_Implementation() {
  return FInteractabilityProbeResponse::BasicResponse();
}

void ASimpleSkeletalResponder::Drag_Update_Implementation(
    FVector2D Origin, FVector2D SmallDelta, FVector2D OverallDelta) {}
