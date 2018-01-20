//
// Copyright 2018 59 Volt Entertainment, all rights reserved.
//

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "StrangerController.generated.h"

UCLASS()
class STARRYEXPANSE_API AStrangerController : public APlayerController {
  GENERATED_BODY()

public:
  AStrangerController();

  UPROPERTY(BlueprintReadOnly)
  bool IsCursorLockedToCenter;

  UPROPERTY()
  float InputMouseVertScale;
  UPROPERTY()
  float InputMouseHorizScale;

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
  void AddHorizontalMouse(float amount);

  UFUNCTION(BlueprintCallable)
  void AddVerticalMouse(float amount);

  UPROPERTY()
  float HorizontalMousePosition = 0.5;

  UPROPERTY()
  float VerticalMousePosition = 0.5;

  // Override defaults

  UFUNCTION()
  virtual void PostInitializeComponents() override;

  UFUNCTION()
  virtual void SetIgnoreMoveInput(bool bNewMoveInput) override;

  UFUNCTION()
  virtual void SetIgnoreLookInput(bool bNewLookInput) override;

protected:
  virtual void BeginPlay() override;
  virtual void Destroyed() override;
  virtual void SetupInputComponent() override;
};
