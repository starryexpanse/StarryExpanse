//
// Copyright 2017 59 Volt Entertainment, all rights reserved.
//
#include "RivenInteractableActor.h"
#include "Engine/Engine.h"
#include "Editor/UnrealEd/Classes/Editor/EditorEngine.h"
#include "Runtime/Engine/Classes/Engine/GameViewportClient.h"
#include "RivenGameInstance.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"

ARivenInteractableActor::ARivenInteractableActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
  PrimaryActorTick.bCanEverTick = true;
  // TODO(cmumford): Should only enable ticks when animation is running.
  PrimaryActorTick.bStartWithTickEnabled = true;
  PrimaryActorTick.bAllowTickOnDedicatedServer = true;
}

void ARivenInteractableActor::SetRotation(float val) {
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
#if 0
  auto game = static_cast<URivenGameInstance*>(GetGameInstance());
  if (!game)
    return;
  UEngine* engine = game->GetEngine();
  if (engine) {
    engine->AddOnScreenDebugMessage(INDEX_NONE, 10, FColor::Yellow, FString::Printf(TEXT("update %f."), val));
  }
#endif
#if 0
  auto game = static_cast<URivenGameInstance*>(GetGameInstance());
  if (!game)
    return;
  UGameViewportClient* client = game->GetGameViewportClient();
  client->RedrawRequested();
  
  UEditorEngine* editor = nullptr;
  editor->RedrawAllViewports();
#endif
}

void ARivenInteractableActor::AnimationProgressCallback(float val)
{
  SetRotation(val);
}

void ARivenInteractableActor::AnimationDone() {
  auto game = static_cast<URivenGameInstance*>(GetGameInstance());
  if (!game)
    return;
  game->SetInteractableState(m_interactable, m_timeline.GetPlaybackPosition());
}

void ARivenInteractableActor::BeginPlay()
{
  Super::BeginPlay();
}

void ARivenInteractableActor::Tick(float DeltaTime)
{
  Super::Tick(DeltaTime);
  m_timeline.TickTimeline(DeltaTime);

#if 0
  auto game = static_cast<URivenGameInstance*>(GetGameInstance());
  if (!game)
    return;
  UGameViewportClient* client = game->GetGameViewportClient();
  client->Tick(DeltaTime);
#endif
}

void ARivenInteractableActor::Initialize_Implementation(EInteractable interactable,
  UStaticMeshComponent* moveablePart, float animDuration, EAxis::Type axis,
  float animStartVal, float animEndVal) {

  m_interactable = interactable;
  m_moveablePart = moveablePart;
  m_axis = axis;

  FOnTimelineFloat progressCallback{};
  progressCallback.BindUFunction(this, FName{ TEXT("AnimationProgressCallback") });

  FOnTimelineEvent  finishedCallback{};
  finishedCallback.BindUFunction(this, FName{ TEXT("AnimationDone") });

  auto floatCurve = NewObject<UCurveFloat>();

  auto startKey = floatCurve->FloatCurve.AddKey(0, animStartVal);
  auto endKey = floatCurve->FloatCurve.AddKey(animDuration, animEndVal);
  floatCurve->FloatCurve.SetKeyTime(startKey, 0);
  floatCurve->FloatCurve.SetKeyTime(endKey, animDuration);
  floatCurve->FloatCurve.SetKeyInterpMode(endKey, RCIM_Cubic);
  floatCurve->FloatCurve.SetKeyTangentMode(endKey, RCTM_Auto);

  check(floatCurve->GetFloatValue(0.0) == animStartVal);
  check(floatCurve->GetFloatValue(animDuration) == animEndVal);

  m_timeline.SetTimelineLength(animDuration);
  m_timeline.AddInterpFloat(floatCurve, progressCallback, FName{ TEXT("InteractableTimelineAnimation") });
  m_timeline.SetTimelineFinishedFunc(finishedCallback);

  auto game = static_cast<URivenGameInstance*>(GetGameInstance());
  if (!game)
    return;
  float rotation = game->GetInteractableState(m_interactable);
  SetRotation(rotation);
  if (rotation > animStartVal) {
    m_timeline.SetNewTime(animDuration);
  }
}

void ARivenInteractableActor::LookingAt_Implementation() {
  UGameInstance* game = GetGameInstance();
  if (!game)
    return;
  UEngine* engine = game->GetEngine();
  if (engine) {
    engine->AddOnScreenDebugMessage(INDEX_NONE, 10, FColor::Yellow, "Looking at the actor.");
  }
}

void ARivenInteractableActor::Touched_Implementation() {
  if (m_timeline.GetPlaybackPosition() > 0) {
    m_timeline.Reverse();
  } else {
    m_timeline.Play();
  }
}