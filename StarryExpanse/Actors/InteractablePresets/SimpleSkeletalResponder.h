//
// Copyright, 59 Volt Entertainment, all rights reserved.
//
#pragma once

#include "Enums/EInteractable.h"
#include "GameFramework/Actor.h"
#include "Interfaces/RivenInteractable.h"
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"
#include "Structs/InteractabilityProbeResponse.h"
#include "Runtime/Engine/Classes/Components/TimelineComponent.h"
#include "Runtime/Engine/Classes/Engine/EngineTypes.h"
#include "SaveGame/ESaveGameField.h"
#include "Structs/InteractableSettingsAxial.h"
#include "SimpleSpinnerResponder.generated.h"

UCLASS()
class STARRYEXPANSE_API ASimpleSkeletalResponder : public AActor,
                                                  public IRivenInteractable {
  GENERATED_BODY()

public:
  ASimpleSkeletalResponder(const FObjectInitializer &ObjectInitializer);

  // Methods:
  UFUNCTION(BlueprintCallable)
  void Initialize(FInteractableSettingsAxial Settings);

  // Actor:
  void BeginPlay() override;
  void Tick(float DeltaTime) override;

  // RivenInteractable:
  UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
  void LookingAt_Begin();

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
  UFUNCTION(Category = Gameplay)
  void AnimationProgressCallback(float val);

  UFUNCTION(Category = Gameplay)
  void AnimationDone();

  void SetRotation(float val);

  ESaveGameField m_save_game_field;

  UPROPERTY(BlueprintReadWrite)
    UAnimationAsset* ForwardsAnimation;

  UPROPERTY(BlueprintReadWrite)
    UAnimationAsset* BackwardsAnimation;
};