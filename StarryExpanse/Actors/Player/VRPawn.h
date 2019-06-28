// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "VRPawn.generated.h"

class UCameraComponent;
class USteamVRChaperoneComponent;
class AMotionControllerHand;

class AVRHand;
class AVRMotionController;
class UCapsuleComponent;

UCLASS()
class STARRYEXPANSE_API AVRPawn : public APawn {
  GENERATED_BODY()

public:
  AVRPawn();

  virtual void Tick(float DeltaTime) override;
  virtual void SetupPlayerInputComponent(
      class UInputComponent *PlayerInputComponent) override;

protected:
  virtual void BeginPlay() override;
  bool m_bVirtualRealityMode = false; // True if HMD is detected.
                                      // do vr mode first > than pc mode

private:
  // Init default components
  void SetupVRComponents();
  // Moves with ship
  UPROPERTY()
  USceneComponent *m_pVRWorldOrigin;

public:
  UPROPERTY(BlueprintReadOnly)
  USceneComponent *m_pVRPawnOrigin;

private:
  UPROPERTY()
  UCameraComponent *m_pCamera;

private:
  UPROPERTY(VisibleAnywhere)
  UStaticMeshComponent *m_pHeadMesh;

  // VR setup

  bool m_bHMDIsSetup = false;

  UFUNCTION()
  void SetupHMD();

  UFUNCTION()
  void OnLeaveVRBounds();
  UFUNCTION()
  void OnReenterVRBounds();

  UPROPERTY()
  USteamVRChaperoneComponent *m_pChaperone;

  // ---- Hands/MotionControllers ----
protected:
  UPROPERTY(BlueprintReadOnly)
  AVRHand *m_pLeftHand;

  UPROPERTY(BlueprintReadOnly)
  AVRHand *m_pRightHand;

private:
  UPROPERTY(EditAnywhere)
  TSubclassOf<AVRHand> m_pVRControllerClass;

  void InitializeNewMotionController(AVRHand *pVRHand,
                                     EControllerHand trackedHand);

  UFUNCTION()
  void OnRep_LeftHandController();
  UFUNCTION()
  void OnRep_RightHandController();

public:
  UFUNCTION(BlueprintCallable)
  AVRHand *GetLeftHand() { return m_pLeftHand; }
  UFUNCTION(BlueprintCallable)
  AVRHand *GetRightHand() { return m_pRightHand; }

private:
protected:
  UPROPERTY(EditAnywhere)
  bool m_bAllowTeleporting{true};

  UFUNCTION()
  void ToggleVR();
  UFUNCTION()
  void ToggleStereo();

  // =====================
  // ---- Replication ----
  // For replicated properties
  // virtual void GetLifetimeReplicatedProps(
  //     TArray<FLifetimeProperty> &OutLifetimeProps) const override;

public:
  UPROPERTY(Replicated, EditAnywhere, BlueprintReadWrite)
  UCapsuleComponent *m_pCapsuleTrigger = nullptr;

  bool m_ToldTheGameModeIAmReady = false;
};
