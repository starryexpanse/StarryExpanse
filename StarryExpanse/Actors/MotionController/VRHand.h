// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/MotionController/VRMotionController.h"
#include "VRHand.generated.h"

class USphereComponent;
class UInteractAgentComponent;
class USkeletalMesh;

/**
 * Represents a hand in VR
 */
UCLASS()
class STARRYEXPANSE_API AVRHand : public AVRMotionController {
  GENERATED_BODY()

public:
  AVRHand();
  virtual void Tick(float DeltaTime) override;
};
