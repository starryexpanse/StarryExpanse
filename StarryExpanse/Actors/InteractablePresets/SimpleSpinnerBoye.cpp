//
// Copyright, 59 Volt Entertainment, all rights reserved.
//
#include "SimpleSpinnerBoye.h"
#include "Engine/Engine.h"
#include "Kismet/GameplayStatics.h"
#include "RivenGameState.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"
#include "Runtime/Engine/Classes/Engine/GameViewportClient.h"
#include "Structs/InteractableSettingsAxial.h"

ASimpleSpinnerBoye::ASimpleSpinnerBoye(
    const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer) {
  PrimaryActorTick.bCanEverTick = true;
  // TODO(cmumford): Should only enable ticks when animation is running.
  PrimaryActorTick.bStartWithTickEnabled = true;
  PrimaryActorTick.bAllowTickOnDedicatedServer = true;
}

void ASimpleSpinnerBoye::SetRotation(float val) {
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

void ASimpleSpinnerBoye::AnimationProgressCallback(float val) {
  SetRotation(val);
}

void ASimpleSpinnerBoye::AnimationDone() {
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

void ASimpleSpinnerBoye::BeginPlay() { Super::BeginPlay(); }

void ASimpleSpinnerBoye::Tick(float DeltaTime) {
  Super::Tick(DeltaTime);
  m_timeline.TickTimeline(DeltaTime);
}

void ASimpleSpinnerBoye::Initialize(FInteractableSettingsAxial settings) {
  m_save_game_field = settings.SaveGameField;
  m_moveablePart = settings.MoveablePart;
  m_axis = settings.Axis;

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

void ASimpleSpinnerBoye::LookingAt_Implementation() {
  UGameInstance *game = GetGameInstance();
  if (!game)
    return;
  UEngine *engine = game->GetEngine();
  if (engine) {
    engine->AddOnScreenDebugMessage(INDEX_NONE, 10, FColor::Yellow,
                                    "Looking at the actor.");
  }
}

void ASimpleSpinnerBoye::Touched_Implementation() {
  if (m_timeline.GetPlaybackPosition() > 0) {
    m_timeline.Reverse();
  } else {
    m_timeline.Play();
  }
}

FInteractabilityProbeResponse ARivenInteractableActor::PollInteractability_Implementation() {
  return FInteractabilityProbeResponse::BasicResponse();
}