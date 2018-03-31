//
// Copyright, 59 Volt Entertainment, all rights reserved.
//
#include "SimpleSkeletalResponder.h"
#include "Engine/Engine.h"
#include "Kismet/GameplayStatics.h"
#include "RivenGameState.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"
#include "Runtime/Engine/Classes/Engine/EngineTypes.h"
#include "Runtime/Engine/Classes/Engine/GameViewportClient.h"
#include "Runtime/Engine/Classes/Animation/AnimationAsset.h"
#include "Runtime/Engine/Classes/Animation/AnimSingleNodeInstance.h"
#include "Runtime/Engine/Public/Animation/AnimNotifyQueue.h"
#include "Runtime/Engine/Classes/Animation/AnimationAsset.h"
#include "Structs/InteractableSettingsSkeletal.h"

ASimpleSkeletalResponder::ASimpleSkeletalResponder(
    const FObjectInitializer &ObjectInitializer)
    : AActor(ObjectInitializer) {
  PrimaryActorTick.bCanEverTick = true;
  // TODO(cmumford): Should only enable ticks when animation is running.
  PrimaryActorTick.bStartWithTickEnabled = true;
  PrimaryActorTick.bAllowTickOnDedicatedServer = true;
}

void ASimpleSkeletalResponder::AnimationProgressCallback(float val) {
  // TODO possible
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

  // TODO stuff
}

void ASimpleSkeletalResponder::BeginPlay() { AActor::BeginPlay(); }

void ASimpleSkeletalResponder::Tick(float DeltaTime) {
  AActor::Tick(DeltaTime);
  if (IsPlaying) {
    UAnimSingleNodeInstance *singleNode = MainSkeleton->GetSingleNodeInstance();
    if (singleNode) {
      auto length = singleNode->GetLength();
      auto time = singleNode->GetCurrentTime();
      if (time >= length) {
        OnAnimationDone();
        IsPlaying = false;
      }
    }
  }
}

void ASimpleSkeletalResponder::OnAnimationDone() {
  auto gs = Cast<ARivenGameState>(GetWorld()->GetGameState());
  if (!gs) {
    return;
  }

  auto saveGame = gs->Instantaneous_SaveGame;
  if (!saveGame) {
    return;
  }

  saveGame->SetBooleanBySaveGameField(m_save_game_field, !IsComingFromEnd ^ IsFalseAtEnd);
}

void ASimpleSkeletalResponder::Initialize(FInteractableSettingsSkeletal settings) {
  m_save_game_field = settings.SaveGameField;

  auto gs = Cast<ARivenGameState>(GetWorld()->GetGameState());
  if (!gs) {
    return;
  }

  auto saveGame = gs->Instantaneous_SaveGame;
  if (!saveGame) {
    return;
  }

  auto isInInitialPosition = !saveGame->GetBooleanBySaveGameField(
      m_save_game_field) ^ settings.IsFalseAtEnd;

  this->BackwardsAnimation = settings.BackwardsAnimation;
  this->ForwardsAnimation = settings.ForwardsAnimation;
  this->MainSkeleton = settings.MainSkeleton;
  this->IsFalseAtEnd = settings.IsFalseAtEnd;

  if (isInInitialPosition) {
    GoToStart();
  } else {
    GoToEnd();
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
  auto gs = Cast<ARivenGameState>(GetWorld()->GetGameState());
  if (!gs) {
    return;
  }

  auto saveGame = gs->Instantaneous_SaveGame;
  if (!saveGame) {
    return;
  }

  if (!saveGame->GetBooleanBySaveGameField(m_save_game_field) ^ IsFalseAtEnd) {
    IsComingFromEnd = false;
    IsPlaying = true;
    MainSkeleton->PlayAnimation(ForwardsAnimation, false);
  }
  else {
    IsComingFromEnd = true;
    IsPlaying = true;
    MainSkeleton->PlayAnimation(BackwardsAnimation, false);
  }
}

FInteractabilityProbeResponse
ASimpleSkeletalResponder::ProbeInteractability_Implementation() {
  if (IsPlaying) {
    return FInteractabilityProbeResponse::NotInteractableResponse();
  }
  return FInteractabilityProbeResponse::BasicResponse();
}

void ASimpleSkeletalResponder::Drag_Update_Implementation(
    FVector2D Origin, FVector2D SmallDelta, FVector2D OverallDelta) {}

void ASimpleSkeletalResponder::GoToStart() {
  MainSkeleton->PlayAnimation(ForwardsAnimation, false);
  MainSkeleton->Stop();
}

void ASimpleSkeletalResponder::GoToEnd() {
  MainSkeleton->PlayAnimation(BackwardsAnimation, false);
  MainSkeleton->Stop();
}