// Fill out your copyright notice in the Description page of Project Settings.

#include "VRMotionController.h"
#include "Engine/Engine.h"
#include "DrawDebugHelpers.h"
#include "Features/IModularFeatures.h"
#include "DrawDebugHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "UnrealNetwork.h"
#include "IMotionController.h"
#include "VRHand.h"

// Sets default values
AVRMotionController::AVRMotionController() {
  PrimaryActorTick.bCanEverTick = true;

  m_pHandOrigin = CreateDefaultSubobject<USceneComponent>(TEXT("HandOrigin"));
  RootComponent = m_pHandOrigin;

  m_pControllerMesh =
      CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SK_Hand"));
  m_pControllerMesh->SetupAttachment(m_pHandOrigin);
  m_pControllerMesh->SetCollisionProfileName("NoCollision");
}

void AVRMotionController::BeginPlay() {
  if (GEngine)
    GEngine->AddOnScreenDebugMessage(
        -1, 3.f, FColor::Blue,
        FString::Printf(TEXT(
            "VRMotionController.cpp::BeginPlay --> The beginPlay is called!")));
  if (GEngine && !m_pControllerMesh)
    GEngine->AddOnScreenDebugMessage(
        -1, 10.f, FColor::Red,
        FString::Printf(TEXT("VRMotionController.cpp::BeginPlay --> The "
                             "m_pControllerMesh Is null")));

  Super::BeginPlay();
  if (GEngine)
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan,
                                     TEXT("Spawned MotionController"));

  // Initial transform target is its own transform
  m_RepTransformTarget = GetActorTransform();
}

// ===================================================
void AVRMotionController::RetrieveMotionControllerDevice() {
  TArray<IMotionController *> tControllers{
      IModularFeatures::Get()
          .GetModularFeatureImplementations<IMotionController>(
              IMotionController::GetModularFeatureName())};

  if (tControllers.Num() > 0) {
    m_pController = tControllers[0];
  } else {
    if (GEngine)
      GEngine->AddOnScreenDebugMessage(
          -1, 5.f, FColor::Red,
          TEXT("Failed to retrieve Motion Controller Device Interface. << "
               "AVRMotionController::BeginPlay()"));
  }
}

// Called every frame
void AVRMotionController::Tick(float DeltaTime) {
  Super::Tick(DeltaTime);

  switch (m_TrackingMode) {

    // ---- NONE ----
  case ETrackingMode::None:
    break;

    // ---- TRACKED ----
  case ETrackingMode::Tracked: {
    // 1. Tracking can be (temporarily) disabled
    if (m_bTrackingEnabled) {

      // 2. Controller device is needed to track MoCon
      if (!m_pController) {
        // Try to retrieve before using motion controller device
        RetrieveMotionControllerDevice();
      }

      if (m_pController) {
        FVector trackedLoc;
        FRotator trackedRot;
        const float meterInUnrealUnits{100.f};

        // Motion Source enum to FName
        FName motionSourceName{};
        if (m_ControllerHand == EControllerHand::Left) {
          motionSourceName = "Left";
        } else if (m_ControllerHand == EControllerHand::Right) {
          motionSourceName = "Right";
        } else {
          motionSourceName = "Left";
        }

        // POLL LOCATION and ROTATION
        m_pController->GetControllerOrientationAndPosition(
            0, motionSourceName, trackedRot, trackedLoc, meterInUnrealUnits);

        // SET polled LOCATION and ROTATION
        if (GetAttachParentActor()) {
          SetActorRelativeRotation(trackedRot);
          SetActorRelativeLocation(trackedLoc);
        } else {
          SetActorLocationAndRotation(trackedLoc, trackedRot);
        }

        // Send relative transform
        FTransform toBroadcast = GetActorTransform();
        toBroadcast.SetLocation(trackedLoc);
        toBroadcast.SetRotation(trackedRot.Quaternion());

        Server_BroadcastTransform(toBroadcast);
      }
    }

    break;
  }

  // ---- REPLICATED ---- TODO REMOVE ME
  case ETrackingMode::Replicated: {
    // Debug show replicated target location and current location
    if (false && m_ControllerHand == EControllerHand::Left) {
      // Purple = Where actor currently is
      // Green = Where actor is moving towards
      DrawDebugSphere(GetWorld(), m_pHandOrigin->GetComponentLocation(), 15.f,
                      32, FColor::Purple, false, -1.f,
                      ESceneDepthPriorityGroup::SDPG_Foreground);

      FVector targetLocation{};
      USceneComponent *pParentCmp = m_pHandOrigin->GetAttachParent();
      if (pParentCmp) {
        targetLocation = {pParentCmp->GetComponentTransform().TransformPosition(
            m_RepTransformTarget.GetLocation())};
      } else {
        targetLocation = m_RepTransformTarget.GetLocation();
      }

      DrawDebugSphere(GetWorld(), targetLocation, 15.f, 32, FColor::Green);
    }

    // DoReplication();
    // return;

    // Not tracked, should lerp to replicated transform
    const float lerpSpeed{10.f};
    float alpha = FMath::Clamp<float>(DeltaTime * lerpSpeed, 0.f, 1.f);

    USceneComponent *pAttachScnCmp{RootComponent->GetAttachParent()};
    if (pAttachScnCmp) {
      // FTransform originTransform = pAttachScnCmp->GetComponentTransform();
      //
      // FTransform currentRelativeTransform = originTransform.Inverse() *
      // GetActorTransform();

      FTransform currentTransform = GetActorTransform();
      FTransform originTransform = pAttachScnCmp->GetComponentTransform();
      FTransform targetTransform{m_RepTransformTarget * originTransform};

      FVector lerpedLocation{FMath::Lerp(currentTransform.GetLocation(),
                                         targetTransform.GetLocation(), alpha)};
      FQuat lerpedRotation{FMath::Lerp(currentTransform.GetRotation(),
                                       targetTransform.GetRotation(), alpha)};
      FVector lerpedScale{FMath::Lerp(currentTransform.GetScale3D(),
                                      targetTransform.GetScale3D(), alpha)};

      SetActorTransform(FTransform(lerpedRotation, lerpedLocation, lerpedScale),
                        false, nullptr, ETeleportType::ResetPhysics);
    }

    break;
  }
  }
}

void AVRMotionController::SetTrackingMode(ETrackingMode trackingMode) {
  m_TrackingMode = trackingMode;
}

void AVRMotionController::SetTrackingHand(EControllerHand hand) {
  m_ControllerHand = hand;

  // Flip hand mesh if right hand
  if (m_ControllerHand == EControllerHand::Right) {
    m_pControllerMesh->SetRelativeScale3D(
        FVector(m_pControllerMesh->RelativeScale3D.X,
                m_pControllerMesh->RelativeScale3D.Y,
                m_pControllerMesh->RelativeScale3D.Z * -1));
  }
}

void AVRMotionController::DoReplication_Implementation() {}

#pragma region Replication
// ===================================================
void AVRMotionController::Server_BroadcastTransform_Implementation(
    FTransform replicatedTransform) {
  Multicast_ReplicateTransform(replicatedTransform);
}

bool AVRMotionController::Server_BroadcastTransform_Validate(
    FTransform replicatedTransform) {
  return true;
}

// ===================================================
void AVRMotionController::Multicast_ReplicateTransform_Implementation(
    FTransform replicatedTransform) {
  // Only for non-owning clients/server
  if (m_TrackingMode == ETrackingMode::Replicated) {
    m_RepTransformTarget = replicatedTransform;
  }
}

// ===================================================
bool AVRMotionController::Multicast_ReplicateTransform_Validate(
    FTransform replicatedTransform) {
  return true;
}
