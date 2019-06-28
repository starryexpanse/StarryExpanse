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

  if (m_bIsTracking) {
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
    }
  }
}

void AVRMotionController::SetIsTracking(bool isTracking) {
  m_bIsTracking = isTracking;
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
