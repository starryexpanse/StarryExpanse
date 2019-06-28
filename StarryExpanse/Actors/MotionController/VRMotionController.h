// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "VRMotionController.generated.h"

class IMotionController;
class UStaticMeshComponent;

/**
 *
 */
UCLASS()
class STARRYEXPANSE_API AVRMotionController : public AActor {
  GENERATED_BODY()

public:
  // Sets default values for this actor's properties
  AVRMotionController();
  // Called every frame
  virtual void Tick(float DeltaTime) override;

  void SetIsTracking(bool isTracking);
  void SetTrackingHand(EControllerHand hand);
  UFUNCTION(BlueprintCallable)
  EControllerHand GetTrackingHand() { return m_ControllerHand; }

protected:
  // Called when the game starts or when spawned
  virtual void BeginPlay() override;

  UPROPERTY(BlueprintReadOnly)
  USceneComponent *m_pHandOrigin;
  UPROPERTY(VisibleAnywhere)
  USkeletalMeshComponent *m_pControllerMesh;

private:
  void RetrieveMotionControllerDevice();

  IMotionController *m_pController;

  bool m_bIsTracking = false;
  EControllerHand m_ControllerHand{EControllerHand::Left};
};
