//
// Copyright, 59 Volt Entertainment, all rights reserved.
//

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Enums/EGameMenuPage.h"
#include "Templates/SharedPointer.h"
#include "StrangerController.generated.h"

UCLASS()
class STARRYEXPANSE_API AStrangerController : public APlayerController {
  GENERATED_BODY()

public:
  AStrangerController();

  UPROPERTY(BlueprintReadOnly)
  bool IsCursorLockedToCenter;

  UFUNCTION()
  void PossiblyFreezeOrUnfreeze();

  UFUNCTION()
  void Interact();

  UFUNCTION()
  void RequestSwitchCursorMode();

  UFUNCTION()
  void EnterCursorMode(bool fixed);

  UFUNCTION()
  FHitResult CastInteractionRay(bool &gotHit, FVector worldLocation,
                                FVector worldDirection);

  UFUNCTION(BlueprintCallable)
  void AddHorizontalMousePan(float amount);

  UFUNCTION(BlueprintCallable)
  void AddVerticalMousePan(float amount);

  UFUNCTION(BlueprintCallable)
  void AddHorizontalMouseScan(float amount);

  UFUNCTION(BlueprintCallable)
  void AddVerticalMouseScan(float amount);

  UFUNCTION()
  void ReactToMenuState(EGameMenuPage menuPage);

  UPROPERTY()
  float HorizontalMousePosition = 0.5;

  UPROPERTY()
  float VerticalMousePosition = 0.5;

  //how close (0.0 - 1.0) to the edge of the left/right of the screen you can get (in cursor mode) before the camera begins to pan
  UPROPERTY(BlueprintReadWrite)
  float HorizontalMouseNudgeThreshold = 0.25; //means that if the cursor is within 25% of the left/right of the screen, you'll start to pan

  //how close (0.0 - 1.0) to the edge of the top/bottom of the screen you can get (in cursor mode) before the camera begins to pan
  UPROPERTY(BlueprintReadWrite)
  float VerticalMouseNudgeThreshold = 0.25; //means that if the cursor is within 25% of the top/bottom of the screen, you'll start to pan

  UPROPERTY(BlueprintReadWrite)
  float HorizontalMouseNudgeMultiplier = 4.0; 

  UPROPERTY(BlueprintReadWrite)
  float VerticalMouseNudgeMultiplier = 4.0; 

  UFUNCTION()
  void Cbk_MenuStateChanged();

  TScriptDelegate<FWeakObjectPtr> MenuStateChanged;

  // Override defaults

  virtual void PostInitializeComponents() override;

  virtual void SetIgnoreMoveInput(bool bNewMoveInput) override;

  virtual void SetIgnoreLookInput(bool bNewLookInput) override;

protected:
  virtual void BeginPlay() override;
  virtual void Destroyed() override;
  virtual void SetupInputComponent() override;
};
