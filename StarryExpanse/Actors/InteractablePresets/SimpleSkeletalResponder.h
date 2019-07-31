//
// Copyright, 59 Volt Entertainment, all rights reserved.
//
#pragma once

#include "Enums/EInteractable.h"
#include "GameFramework/Actor.h"
#include "Interfaces/RivenInteractable.h"
#include "Structs/InteractabilityProbeResponse.h"
#include "Actors//Info/ASoundConfigurationBase.h"
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"
#include "Runtime/Engine/Classes/Components/AudioComponent.h"
#include "Runtime/Engine/Classes/Animation/AnimSequence.h"
#include "Runtime/Engine/Classes/Components/TimelineComponent.h"
#include "Runtime/Engine/Classes/Engine/EngineTypes.h"
#include "SaveGame/ESaveGameField.h"
#include "Structs/InteractableSettingsSkeletal.h"
#include "SimpleSkeletalResponder.generated.h"

UCLASS()
class STARRYEXPANSE_API ASimpleSkeletalResponder : public AActor,
                                                   public IRivenInteractable {
  GENERATED_BODY()

public:
  ASimpleSkeletalResponder(const FObjectInitializer &ObjectInitializer);

  // Methods:
  UFUNCTION(BlueprintCallable)
  void Initialize(FInteractableSettingsSkeletal Settings);

  // Actor:
  void BeginPlay() override;
  void Tick(float DeltaTime) override;

  // RivenInteractable:
  UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
  void LookingAt_Begin(FHitResult HitInfo);

  UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
  void LookingAt_End();

  UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
  void Touched();

  UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
  FDragCallbackPreferences Drag_Begin(FHitResult HitInfo, FVector2D Origin,
                                      AActor *DragOwner);

  UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
  void Extra_Drag_Details_Available(FHitResult HitInfo);

  UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
  void Drag_Update(FVector2D Origin, FVector2D SmallDelta,
                   FVector2D OverallDelta);

  UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
  void Drag_Finished(FHitResult HitInfo, FVector2D Origin, FVector2D SmallDelta,
                     FVector2D OverallDelta, bool WasDragCanceled);

  UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
  FInteractabilityProbeResponse ProbeInteractability();

private:
  UPROPERTY()
  USkeletalMeshComponent *MainSkeleton = nullptr;

  UPROPERTY()
  UAnimSequence *BackwardsAnimation = nullptr;

  UPROPERTY()
  UAnimSequence *ForwardsAnimation = nullptr;

  UPROPERTY()
  ASoundConfigurationBase *SoundConfiguration;

  UPROPERTY()
  bool IsFalseAtEnd;

  void OnAnimationDone();

  void GoToStart();
  void GoToEnd();

  bool IsPlaying = false;
  bool IsComingFromEnd = false;
  ESaveGameField m_save_game_field;
};
