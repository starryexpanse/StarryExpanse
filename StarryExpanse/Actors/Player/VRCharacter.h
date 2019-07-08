// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/Character.h"
#include "VRCharacter.generated.h"

class UCameraComponent;
class USteamVRChaperoneComponent;
class AMotionControllerHand;

class AVRHand;
class AVRMotionController;
class UCapsuleComponent;

class UPawnMovementComponent;

UCLASS()
class STARRYEXPANSE_API AVRCharacter : public ACharacter {
  GENERATED_BODY()

public:
  AVRCharacter(const FObjectInitializer &ObjectInitializer);

  virtual void Tick(float DeltaTime);
  virtual void
  SetupPlayerInputComponent(class UInputComponent *PlayerInputComponent);

protected:
  virtual void BeginPlay();

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  USceneComponent *m_pVRWorldOrigin;

public:
  UPROPERTY(BlueprintReadWrite)
  AVRHand *LeftHand;

  UPROPERTY(BlueprintReadWrite)
  AVRHand *RightHand;

  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  USceneComponent *m_pVRCharacterOrigin;

  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  UCameraComponent *m_pCamera;

  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  UStaticMeshComponent *m_pHeadMesh;

  // VR setup

  UFUNCTION()
  void SetupHMD();

  UFUNCTION()
  void OnLeaveVRBounds();

  UFUNCTION()
  void OnReenterVRBounds();

  UPROPERTY()
  USteamVRChaperoneComponent *m_pChaperone;

  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  AVRHand *m_pLeftHand;

  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  AVRHand *m_pRightHand;

private:
  bool m_bHMDIsSetup = false;

  UPROPERTY(EditAnywhere)
  TSubclassOf<AVRHand> m_pVRControllerClass;

  void InitializeNewMotionController(AVRHand *pVRHand,
                                     EControllerHand trackedHand);

public:
  UFUNCTION(BlueprintCallable)
  AVRHand *GetLeftHand() { return m_pLeftHand; }

  UFUNCTION(BlueprintCallable)
  AVRHand *GetRightHand() { return m_pRightHand; }

protected:
  UPROPERTY(EditAnywhere)
  bool m_bAllowTeleporting{true};

  UFUNCTION()
  void ToggleVR();

  UFUNCTION()
  void ToggleStereo();

public:
  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  UCapsuleComponent *m_pCapsuleTrigger = nullptr;
};
