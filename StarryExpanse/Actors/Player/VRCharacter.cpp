#include "VRCharacter.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Runtime/Engine/Classes/Camera/CameraComponent.h"
#include "Runtime/HeadMountedDisplay/Public/IHeadMountedDisplay.h"
#include "Runtime/HeadMountedDisplay/Public/IXRTrackingSystem.h" // XRSystem
#include "Runtime/HeadMountedDisplay/Public/HeadMountedDisplayFunctionLibrary.h"
#include "SteamVRChaperoneComponent.h"
#include "Runtime/Engine/Classes/Kismet/KismetMathLibrary.h" // MinimumAreaRectangle
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"

#include "Components/StaticMeshComponent.h"

#include "UnrealNetwork.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/Engine.h"

#include "Actors/MotionController/VRHand.h"
#include "Runtime/HeadMountedDisplay/Public/MotionControllerComponent.h"

#include "Components/CapsuleComponent.h"

AVRCharacter::AVRCharacter(const FObjectInitializer &ObjectInitializer)
    : ACharacter(ObjectInitializer) {
  // Look into Instanced Stereo Rendering for perf
  // https://forum.unity.com/threads/instanced-stereo-rendering-vr-implemented-already.468815/

  PrimaryActorTick.bCanEverTick = true;

  m_pVRWorldOrigin =
      CreateDefaultSubobject<USceneComponent>(TEXT("VRWorldOrigin"));
  m_pVRWorldOrigin->SetupAttachment(GetCapsuleComponent());

  // VR Player Origin scene cmp
  m_pVRCharacterOrigin =
      CreateDefaultSubobject<USceneComponent>(TEXT("VRCharacterOrigin"));
  m_pVRCharacterOrigin->SetupAttachment(m_pVRWorldOrigin);

  // Camera child of root
  m_pCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
  m_pCamera->SetupAttachment(m_pVRCharacterOrigin);

  // Head mesh
  m_pHeadMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SM_Head"));
  m_pHeadMesh->SetupAttachment(m_pCamera);

  // Chaperone
  m_pChaperone =
      CreateDefaultSubobject<USteamVRChaperoneComponent>(TEXT("Chaperone"));
  m_pChaperone->OnLeaveBounds.AddDynamic(this, &AVRCharacter::OnLeaveVRBounds);
  m_pChaperone->OnReturnToBounds.AddDynamic(this,
                                            &AVRCharacter::OnReenterVRBounds);
}

void AVRCharacter::BeginPlay() {
  // spawn hands

  auto pWorld = GetWorld();
  FTransform spawnTransform;
  spawnTransform.SetLocation(m_pCamera->GetComponentLocation() +
                             FVector(0.f, 0.f, 200.f));
  spawnTransform.SetRotation(FQuat(90, 0, 0, 0));

  if (!m_pVRControllerClass) {
    m_pVRControllerClass = AVRHand::StaticClass();
  }

  if (LeftHand) {
    InitializeNewMotionController(LeftHand, EControllerHand::Left);
  }

  if (RightHand) {
    InitializeNewMotionController(RightHand, EControllerHand::Right);
  }

  // End

  SetupHMD();

  Super::BeginPlay();
}

void AVRCharacter::SetupPlayerInputComponent(
    UInputComponent *PlayerInputComponent) {
  Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AVRCharacter::Tick(float DeltaTime) {
  Super::Tick(DeltaTime);

  if (!m_bHMDIsSetup) {
    SetupHMD();
  }
}

void AVRCharacter::SetupHMD() {
  // Sets correct eye height or defaults to PC-Mode if no VR device detected
  if (GEngine) {
    // Check if XRSystem is ok before continuing
    TSharedPtr<IXRTrackingSystem, ESPMode::ThreadSafe> pXRSystem{
        GEngine->XRSystem};

    if (pXRSystem) {
      IHeadMountedDisplay *pHMD{GEngine->XRSystem->GetHMDDevice()};
      TSharedPtr<IStereoRendering, ESPMode::ThreadSafe> pStereo{
          GEngine->XRSystem->GetStereoRenderingDevice()};

      bool bHMDEnabled{pHMD->IsHMDEnabled()};
      bool bStereoEnabled{pStereo->IsStereoEnabled()};

      if (!bHMDEnabled) {
        pHMD->EnableHMD(true);
      }
      if (!pStereo->IsStereoEnabled()) {
        pStereo->EnableStereo(true);
      }

      bool bInVR{pHMD != nullptr && pHMD->IsHMDEnabled() &&
                 pStereo->IsStereoEnabled()};
      if (bInVR) {
        // Set Eye height depending on Vive, Oculus, PSVR (Most likely Vive)
        {
          FName vrDeviceName = GEngine->XRSystem->GetSystemName();
          const FName oculusName{"OculusHMD"};
          const FName viveName{"SteamVR"};
          const FName psvrName{"PSVR"};

          if (vrDeviceName == viveName || vrDeviceName == oculusName) {
            // VROrigin is at floor level
            UHeadMountedDisplayFunctionLibrary::SetTrackingOrigin(
                EHMDTrackingOrigin::Floor);
            if (GEngine)
              GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Cyan,
                                               TEXT("HMD set to floor"));
          } else if (vrDeviceName == psvrName) {
            // VROrigin is at eye level
            UHeadMountedDisplayFunctionLibrary::SetTrackingOrigin(
                EHMDTrackingOrigin::Eye);

            // Match VROrigin to eye level
            const float defaultPlayerHeight{180.f};
            FVector psvrEyeOffset{0.f, 0.f, defaultPlayerHeight};
            m_pVRCharacterOrigin->AddLocalOffset(psvrEyeOffset);
          }
        }
        m_bHMDIsSetup = true;

      } else {
        if (GEngine)
          GEngine->AddOnScreenDebugMessage(
              1, 0.1f, FColor::White,
              TEXT("AVRCharacter::AVRCharacter() > XRSystem did not find HMD. "
                   "Pawn set "
                   "to PC-Mode"));
      }
    } else {
      if (GEngine)
        GEngine->AddOnScreenDebugMessage(
            1, 0.1f, FColor::White,
            TEXT("AVRCharacter::AVRCharacter() > XRSystem was nullptr. Pawn "
                 "set to "
                 "PC-Mode"));
    }
  } else {
    // If ue4 auto possesses HMD, then it is possible
    // that GEngine == nullptr AND player will use HMD >>> PC-Mode wrongfully
    // selected.
    if (GEngine)
      GEngine->AddOnScreenDebugMessage(
          1, 0.1f, FColor::Red,
          TEXT("[ERROR] GEngine was nullptr. Fix this << "
               "AVRCharacter::SetupHMD()"));
  }
}

#pragma region VRBounds

void AVRCharacter::OnLeaveVRBounds() {
  if (GEngine)
    GEngine->AddOnScreenDebugMessage(
        -1, 5.f, FColor::Cyan,
        TEXT("[AVRCharacter] Player has left VR bounds"));
}

void AVRCharacter::OnReenterVRBounds() {
  if (GEngine)
    GEngine->AddOnScreenDebugMessage(
        -1, 5.f, FColor::Cyan,
        TEXT("[AVRCharacter] Player has reentered VR bounds"));
}
#pragma endregion VRBounds

// void AVRCharacter::GetLifetimeReplicatedProps(
//     TArray<FLifetimeProperty> &OutLifetimeProps) const {
//   Super::GetLifetimeReplicatedProps(OutLifetimeProps);

//   DOREPLIFETIME(AVRCharacter, m_pLeftHand);
//   DOREPLIFETIME(AVRCharacter, m_pRightHand);
//   DOREPLIFETIME(AVRCharacter, m_pCapsuleTrigger);
// }

void AVRCharacter::ToggleVR() {
  TSharedPtr<IXRTrackingSystem, ESPMode::ThreadSafe> pXRSystem{
      GEngine->XRSystem};
  if (pXRSystem) {
    IHeadMountedDisplay *pHMD{GEngine->XRSystem->GetHMDDevice()};
    bool bHMDEnabled{pHMD->IsHMDEnabled()};
    pHMD->EnableHMD(!pHMD->IsHMDEnabled());
    if (bHMDEnabled) {
      if (GEngine)
        GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Cyan,
                                         ("HMD WAS ON"));
    } else {
      if (GEngine)
        GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Cyan,
                                         ("HMD WAS OFF"));
    }
  }
}

void AVRCharacter::ToggleStereo() {
  TSharedPtr<IXRTrackingSystem, ESPMode::ThreadSafe> pXRSystem{
      GEngine->XRSystem};
  if (pXRSystem) {
    TSharedPtr<IStereoRendering, ESPMode::ThreadSafe> pStereo{
        pXRSystem->GetStereoRenderingDevice()};
    pStereo->EnableStereo(!pStereo->IsStereoEnabled());
    if (GEngine)
      GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Cyan,
                                       TEXT("Toggle Stereo VR"));
  }
}

void AVRCharacter::InitializeNewMotionController(AVRHand *pVRHand,
                                                 EControllerHand trackedHand) {
  if (!pVRHand) {
    if (GEngine)
      GEngine->AddOnScreenDebugMessage(
          -1, 15.f, FColor::Red,
          TEXT(
              "VRCharacter could not initilaize motion controller. pVRHand was "
              "nullptr. Exited function. << "
              "AVRCharacter::InitializeNewMotionController()"));
    return;
  }

  FAttachmentTransformRules attachRules{EAttachmentRule::SnapToTarget,
                                        EAttachmentRule::SnapToTarget,
                                        EAttachmentRule::KeepWorld, false};
  pVRHand->AttachToComponent(m_pVRCharacterOrigin, attachRules);

  pVRHand->SetTrackingHand(trackedHand);
  pVRHand->SetIsTracking(true);
}
