// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/Engine.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Runtime/Engine/Classes/Camera/CameraComponent.h"
#include "Runtime/HeadMountedDisplay/Public/IHeadMountedDisplay.h"
#include "Runtime/HeadMountedDisplay/Public/IXRTrackingSystem.h" // XRSystem
#include "Runtime/HeadMountedDisplay/Public/HeadMountedDisplayFunctionLibrary.h"
#include "SteamVRChaperoneComponent.h"

#include "VRCharacter.generated.h"

class UInputComponent;

UCLASS(config = Game)
class AVRCharacter : public ACharacter {
  GENERATED_BODY()

  /** Pawn mesh: 1st person view (arms; seen only by self) */
  UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
  class USkeletalMeshComponent *Mesh1P;

  /** Gun mesh: VR view (attached to the VR controller directly, no arm, just
   * the actual gun) */
  UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
  class USkeletalMeshComponent *VR_Gun;

  /** Location on VR gun mesh where projectiles should spawn. */
  UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
  class USceneComponent *VR_MuzzleLocation;

  /** First person camera */
  UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera,
            meta = (AllowPrivateAccess = "true"))
  class UCameraComponent *FirstPersonCameraComponent;

  /** Motion controller (right hand) */
  UPROPERTY(VisibleAnywhere, BlueprintReadOnly,
            meta = (AllowPrivateAccess = "true"))
  class UMotionControllerComponent *R_MotionController;

  /** Motion controller (left hand) */
  UPROPERTY(VisibleAnywhere, BlueprintReadOnly,
            meta = (AllowPrivateAccess = "true"))
  class UMotionControllerComponent *L_MotionController;

public:
  AVRCharacter();

  virtual void Tick(float DeltaTime);

protected:
  virtual void BeginPlay();

public:
  /** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
  UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Camera)
  float BaseTurnRate;

  UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
  bool IsHMDSetUp;

  /** Base look up/down rate, in deg/sec. Other scaling may affect final rate.
   */
  UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Camera)
  float BaseLookUpRate;

  /** Sound to play each time we fire */
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
  class USoundBase *FireSound;

  /** AnimMontage to play each time we fire */
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
  class UAnimMontage *FireAnimation;

  /** Whether to use motion controller location for aiming. */
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
  uint32 bUsingMotionControllers : 1;

  UFUNCTION()
  void SetupHMD();

  UFUNCTION(BlueprintPure, BlueprintCallable)
  FVector2D FindCentroidOfPolygon(TArray<FVector2D> RingPoints);

  UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
  void OnTurn(float Amount);

  UFUNCTION()
  FTransform GetPointerHandTransform();

protected:
  /** Fires a projectile. */
  void OnFire();

  /** Resets HMD orientation and position in VR. */
  void OnResetVR();

  struct TouchData {
    TouchData() {
      bIsPressed = false;
      Location = FVector::ZeroVector;
    }
    bool bIsPressed;
    ETouchIndex::Type FingerIndex;
    FVector Location;
    bool bMoved;
  };
  void BeginTouch(const ETouchIndex::Type FingerIndex, const FVector Location);
  void EndTouch(const ETouchIndex::Type FingerIndex, const FVector Location);
  void TouchUpdate(const ETouchIndex::Type FingerIndex, const FVector Location);
  TouchData TouchItem;

protected:
  // APawn interface
  virtual void
  SetupPlayerInputComponent(UInputComponent *InputComponent) override;
  // End of APawn interface

  /*
   * Configures input for touchscreen devices if there is a valid touch
   * interface for doing so
   *
   * @param	InputComponent	The input component pointer to bind controls to
   * @returns true if touch controls were enabled.
   */
  bool EnableTouchscreenMovement(UInputComponent *InputComponent);

public:
  /** Returns Mesh1P subobject **/
  FORCEINLINE class USkeletalMeshComponent *GetMesh1P() const { return Mesh1P; }
  /** Returns FirstPersonCameraComponent subobject **/
  FORCEINLINE class UCameraComponent *GetFirstPersonCameraComponent() const {
    return FirstPersonCameraComponent;
  }
};
