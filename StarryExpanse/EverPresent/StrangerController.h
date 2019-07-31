//
// Copyright, 59 Volt Entertainment, all rights reserved.
//

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Enums/EGameMenuPage.h"
#include "Templates/SharedPointer.h"
#include "Interfaces/RivenInteractable.h"
#include "Runtime/Engine/Public/CollisionQueryParams.h"
#include "StrangerController.generated.h"

UCLASS()
class STARRYEXPANSE_API AStrangerController : public APlayerController {
  GENERATED_BODY()

public:
  AStrangerController();

  virtual void Tick(float DeltaTime) override;

  UPROPERTY(BlueprintReadOnly)
  bool IsCursorLockedToCenter;

  UPROPERTY()
  AActor *PreviouslyLookingAtInteractable;

  UFUNCTION()
  void PossiblyFreezeOrUnfreeze();

  UFUNCTION()
  void Interact();

  UFUNCTION()
  void RequestSwitchCursorMode();

  UFUNCTION()
  void EnterCursorMode(bool fixed);

  FHitResult CastInteractionRay(bool &gotHit, FVector worldLocation,
                                FVector worldDirection,
                                FCollisionQueryParams collisionParams);

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
