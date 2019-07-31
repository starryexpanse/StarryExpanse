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

ASimpleSpinnerResponder::ASimpleSpinnerResponder(
    const FObjectInitializer &ObjectInitializer)
    : AActor(ObjectInitializer) {
  PrimaryActorTick.bCanEverTick = true;
  // TODO(cmumford): Should only enable ticks when animation is running.
  PrimaryActorTick.bStartWithTickEnabled = true;
}

void ASimpleSpinnerResponder::SetRotation(float val) {
  FRotator rotator(0, 0, 0);
  switch (m_axis) {
  case EAxis::X:
    rotator.Roll = val;
    break;
  case EAxis::Y:
    rotator.Pitch = val;
    break;
  case EAxis::Z:
    rotator.Yaw = val;
    break;
  }
  m_moveablePart->SetRelativeRotation(rotator);
}

void ASimpleSpinnerResponder::AnimationProgressCallback(float val) {
  SetRotation(val);
}

void ASimpleSpinnerResponder::AnimationDone() {
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

void ASimpleSpinnerResponder::BeginPlay() { AActor::BeginPlay(); }

void ASimpleSpinnerResponder::Tick(float DeltaTime) {
  AActor::Tick(DeltaTime);
  m_timeline.TickTimeline(DeltaTime);
}

void ASimpleSpinnerResponder::Initialize(FInteractableSettingsAxial settings) {
  m_save_game_field = settings.SaveGameField;
  m_moveablePart = settings.MoveablePart;
  m_axis = settings.Axis;

  check(m_moveablePart);

  FOnTimelineFloat progressCallback{};
  progressCallback.BindUFunction(this,
                                 FName{TEXT("AnimationProgressCallback")});

  FOnTimelineEvent finishedCallback{};
  finishedCallback.BindUFunction(this, FName{TEXT("AnimationDone")});

  auto floatCurve = NewObject<UCurveFloat>();

  auto startKey =
      floatCurve->FloatCurve.AddKey(0, settings.AnimationStartValue);
  auto endKey = floatCurve->FloatCurve.AddKey(settings.AnimationDuration,
                                              settings.AnimationEndValue);
  floatCurve->FloatCurve.SetKeyTime(startKey, 0);
  floatCurve->FloatCurve.SetKeyTime(endKey, settings.AnimationDuration);
  floatCurve->FloatCurve.SetKeyInterpMode(endKey, RCIM_Cubic);
  floatCurve->FloatCurve.SetKeyTangentMode(endKey, RCTM_Auto);

  check(floatCurve->GetFloatValue(0.0) == settings.AnimationStartValue);
  check(floatCurve->GetFloatValue(settings.AnimationDuration) ==
        settings.AnimationEndValue);

  m_timeline.SetTimelineLength(settings.AnimationDuration);
  m_timeline.AddInterpFloat(floatCurve, progressCallback,
                            FName{TEXT("InteractableTimelineAnimation")});
  m_timeline.SetTimelineFinishedFunc(finishedCallback);

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

void ASimpleSpinnerResponder::LookingAt_Begin_Implementation(
    FHitResult HitInfo) {
  UGameInstance *game = GetGameInstance();
  if (!game)
    return;
  UEngine *engine = game->GetEngine();
  if (engine) {
    engine->AddOnScreenDebugMessage(INDEX_NONE, 10, FColor::Yellow,
                                    "Looking at the actor.");
  }
}

void ASimpleSpinnerResponder::LookingAt_End_Implementation() {}

void ASimpleSpinnerResponder::Extra_Drag_Details_Available_Implementation(
    FHitResult HitInfo) {}

FDragCallbackPreferences ASimpleSpinnerResponder::Drag_Begin_Implementation(
    FHitResult HitInfo, FVector2D Origin, AActor *DragOwner) {
  return FDragCallbackPreferences::NoUpdates();
}

void ASimpleSpinnerResponder::Drag_Finished_Implementation(
    FHitResult HitInfo, FVector2D Origin, FVector2D SmallDelta,
    FVector2D OverallDelta, bool WasDragCanceled) {}

void ASimpleSpinnerResponder::Touched_Implementation() {
  if (m_timeline.GetPlaybackPosition() > 0) {
    m_timeline.Reverse();
  } else {
    m_timeline.Play();
  }
}

FInteractabilityProbeResponse
ASimpleSpinnerResponder::ProbeInteractability_Implementation() {
  return FInteractabilityProbeResponse::BasicResponse();
}

void ASimpleSpinnerResponder::Drag_Update_Implementation(
    FVector2D Origin, FVector2D SmallDelta, FVector2D OverallDelta) {}
