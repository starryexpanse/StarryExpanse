#include "VRCharacter.h"
#include "Animation/AnimInstance.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/InputSettings.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "MotionControllerComponent.h"
#include "XRMotionControllerBase.h" // for FXRMotionControllerBase::RightHandSourceId

//////////////////////////////////////////////////////////////////////////
// AVRCharacter

AVRCharacter::AVRCharacter() {
  // Set size for collision capsule
  GetCapsuleComponent()->InitCapsuleSize(55.f, 96.0f);

  // set our turn rates for input
  BaseTurnRate = 45.f;
  BaseLookUpRate = 45.f;

  // Create a CameraComponent
  FirstPersonCameraComponent =
      CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
  FirstPersonCameraComponent->SetupAttachment(GetCapsuleComponent());
  FirstPersonCameraComponent->RelativeLocation =
      FVector(-39.56f, 1.75f, 64.f); // Position the camera
  FirstPersonCameraComponent->bUsePawnControlRotation = false;

  // Create a mesh component that will be used when being viewed from a '1st
  // person' view (when controlling this pawn)
  Mesh1P =
      CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh1P"));
  Mesh1P->SetOnlyOwnerSee(true);
  Mesh1P->SetupAttachment(FirstPersonCameraComponent);
  Mesh1P->bCastDynamicShadow = false;
  Mesh1P->CastShadow = false;
  Mesh1P->RelativeRotation = FRotator(1.9f, -19.19f, 5.2f);
  Mesh1P->RelativeLocation = FVector(-0.5f, -4.4f, -155.7f);

  // Create VR Controllers.
  R_MotionController = CreateDefaultSubobject<UMotionControllerComponent>(
      TEXT("R_MotionController"));
  R_MotionController->MotionSource = FXRMotionControllerBase::RightHandSourceId;
  R_MotionController->SetupAttachment(RootComponent);
  L_MotionController = CreateDefaultSubobject<UMotionControllerComponent>(
      TEXT("L_MotionController"));
  L_MotionController->SetupAttachment(RootComponent);

  // Create a gun and attach it to the right-hand VR controller.
  // Create a gun mesh component
  VR_Gun = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("VR_Gun"));
  VR_Gun->SetOnlyOwnerSee(true); // only the owning player will see this mesh
  VR_Gun->bCastDynamicShadow = false;
  VR_Gun->CastShadow = false;
  VR_Gun->SetupAttachment(R_MotionController);
  VR_Gun->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));

  // Uncomment the following line to turn motion controllers on by default:
  // bUsingMotionControllers = true;

  PrimaryActorTick.bCanEverTick = true;
}

void AVRCharacter::Tick(float DeltaTime) {
  Super::Tick(DeltaTime);

  if (!IsHMDSetUp) {
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

      bool bInVR =
          pHMD != nullptr && pHMD->IsHMDEnabled() && pStereo->IsStereoEnabled();
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
          }
        }
        IsHMDSetUp = true;

      } else {
        if (GEngine)
          GEngine->AddOnScreenDebugMessage(
              1, 0.1f, FColor::White,
              TEXT("AOldVRCharacter::AOldVRCharacter() > XRSystem did not find "
                   "HMD. "
                   "Pawn set "
                   "to PC-Mode"));
      }
    } else {
      if (GEngine)
        GEngine->AddOnScreenDebugMessage(
            1, 0.1f, FColor::White,
            TEXT("AOldVRCharacter::AOldVRCharacter() > XRSystem was nullptr. "
                 "Pawn "
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
               "AOldVRCharacter::SetupHMD()"));
  }
}

FVector2D AVRCharacter::FindCentroidOfPolygon(TArray<FVector2D> RingPoints) {
  FVector2D centroid = FVector2D::ZeroVector;

  double netArea = 0.0;
  int length = RingPoints.Num();
  int i = 0;

  for (i = 0; i < length; i++) {
    double x0 = RingPoints[i % length].X;
    double y0 = RingPoints[i % length].Y;
    double x1 = RingPoints[(i + 1) % length].X;
    double y1 = RingPoints[(i + 1) % length].Y;

    double signedArea = x0 * y1 - x1 * y0;
    netArea += signedArea;
    centroid.X += (x0 + x1) * signedArea;
    centroid.Y += (y0 + y1) * signedArea;
  }

  netArea *= 0.5;

  centroid.X /= (6.0 * netArea);
  centroid.Y /= (6.0 * netArea);

  return centroid;
}

void AVRCharacter::BeginPlay() {
  // Call the base class
  Super::BeginPlay();

  // Show or hide the two versions of the gun based on whether or not we're
  // using motion controllers.
  if (bUsingMotionControllers) {
    VR_Gun->SetHiddenInGame(false, true);
    Mesh1P->SetHiddenInGame(true, true);
  } else {
    VR_Gun->SetHiddenInGame(true, true);
    Mesh1P->SetHiddenInGame(false, true);
  }

  SetupHMD();
}

//////////////////////////////////////////////////////////////////////////
// Input

void AVRCharacter::SetupPlayerInputComponent(
    class UInputComponent *PlayerInputComponent) {
  // set up gameplay key bindings
  check(PlayerInputComponent);

  // Bind jump events
  PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
  PlayerInputComponent->BindAction("Jump", IE_Released, this,
                                   &ACharacter::StopJumping);

  // Bind fire event
  PlayerInputComponent->BindAction("Fire", IE_Pressed, this,
                                   &AVRCharacter::OnFire);

  // Enable touchscreen input
  EnableTouchscreenMovement(PlayerInputComponent);

  PlayerInputComponent->BindAction("ResetVR", IE_Pressed, this,
                                   &AVRCharacter::OnResetVR);

  // We have 2 versions of the rotation bindings to handle different kinds of
  // devices differently "turn" handles devices that provide an absolute delta,
  // such as a mouse. "turnrate" is for devices that we choose to treat as a
  // rate of change, such as an analog joystick
}

void AVRCharacter::OnFire() {}

void AVRCharacter::OnResetVR() {
  UHeadMountedDisplayFunctionLibrary::ResetOrientationAndPosition();
}

void AVRCharacter::BeginTouch(const ETouchIndex::Type FingerIndex,
                              const FVector Location) {
  if (TouchItem.bIsPressed == true) {
    return;
  }
  if ((FingerIndex == TouchItem.FingerIndex) && (TouchItem.bMoved == false)) {
    OnFire();
  }
  TouchItem.bIsPressed = true;
  TouchItem.FingerIndex = FingerIndex;
  TouchItem.Location = Location;
  TouchItem.bMoved = false;
}

void AVRCharacter::EndTouch(const ETouchIndex::Type FingerIndex,
                            const FVector Location) {
  if (TouchItem.bIsPressed == false) {
    return;
  }
  TouchItem.bIsPressed = false;
}

void AVRCharacter::OnTurn_Implementation(float Amount) {}

bool AVRCharacter::EnableTouchscreenMovement(
    class UInputComponent *PlayerInputComponent) {
  if (FPlatformMisc::SupportsTouchInput() ||
      GetDefault<UInputSettings>()->bUseMouseForTouch) {
    PlayerInputComponent->BindTouch(EInputEvent::IE_Pressed, this,
                                    &AVRCharacter::BeginTouch);
    PlayerInputComponent->BindTouch(EInputEvent::IE_Released, this,
                                    &AVRCharacter::EndTouch);

    // Commenting this out to be more consistent with FPS BP template.
    // PlayerInputComponent->BindTouch(EInputEvent::IE_Repeat, this,
    // &AVRCharacter::TouchUpdate);
    return true;
  }

  return false;
}
