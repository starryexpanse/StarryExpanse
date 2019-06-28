// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "VRMotionController.generated.h"

class IMotionController;
class UStaticMeshComponent;

UENUM(Blueprintable)
enum class ETrackingMode : uint8 { None, Tracked, Replicated };

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

  void EnableTracking(bool bEnabled) {
    m_bTrackingEnabled = bEnabled;
  } // Possibility to (temporarily) disable tracking tracking while it should be
    // tracked on this client
  void SetTrackingMode(ETrackingMode trackingMode);
  void SetTrackingHand(EControllerHand hand);
  UFUNCTION(BlueprintCallable)
  EControllerHand GetTrackingHand() { return m_ControllerHand; }

  UFUNCTION(BlueprintCallable)
  bool GetIsTrackedOnClient() {
    return m_TrackingMode == ETrackingMode::Tracked;
  }

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

  ETrackingMode m_TrackingMode{ETrackingMode::None};
  EControllerHand m_ControllerHand{EControllerHand::Left};
  bool m_bTrackingEnabled{true};

  // ======================
  // ---- Replication -----
  UFUNCTION(Server, Unreliable, WithValidation)
  void Server_BroadcastTransform(FTransform replicatedTransform);
  UFUNCTION(NetMulticast, Unreliable, WithValidation)
  void Multicast_ReplicateTransform(FTransform replicatedTransform);

protected:
  UFUNCTION(BlueprintNativeEvent)
  void DoReplication();

  UPROPERTY(BlueprintReadOnly)
  FTransform m_RepTransformTarget{};
};
