#include "StarryExpanse.h"
#include "SECharacter.h"
#include "GameFramework/InputSettings.h"
#include "SECharacterState.h"

DEFINE_LOG_CATEGORY_STATIC(LogFPChar, Warning, All);

//////////////////////////////////////////////////////////////////////////
// ASECharacter

ASECharacter::ASECharacter() : Super()
{
   // Set size for collision capsule
   GetCapsuleComponent()->InitCapsuleSize(5.421325f, 44.f);

   // Set our turn rates for input
   BaseTurnRate = 45.f;
   BaseLookUpRate = 45.f;
   auto movement = CastChecked<UCharacterMovementComponent>(GetMovementComponent());
   movement->MaxWalkSpeed = 100.f;

   // Create a CameraComponent
   CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
   CameraComponent->AttachToComponent(GetCapsuleComponent(), FAttachmentTransformRules::KeepWorldTransform);
   CameraComponent->RelativeLocation = FVector(0.f, 0.f, GetCapsuleComponent()->GetUnscaledCapsuleHalfHeight()); // Position the camera
   CameraComponent->bUsePawnControlRotation = true;
}

void ASECharacter::FreeCursor()
{
   auto PS = CastChecked<ASECharacterState>(PlayerState);
   if (PS != nullptr) {
      PS->CursorState = ECharacterCursorState::Uncontrolled;
   }
}

void ASECharacter::BeginPlay()
{
   Super::BeginPlay();

   auto PC = Cast<APlayerController>(Controller);
   if (PC) {
      PC->bShowMouseCursor = false;
      PC->bEnableClickEvents = true;
      PC->bEnableMouseOverEvents = true;
   }
}

//////////////////////////////////////////////////////////////////////////
// Input

void ASECharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
   Super::SetupPlayerInputComponent(PlayerInputComponent);

   // set up gameplay key bindings
   check(PlayerInputComponent);

   PlayerInputComponent->BindAction("Toggle Cursor Mode", EInputEvent::IE_Pressed, this, &ASECharacter::ToggleCursorMode);
   PlayerInputComponent->BindAction("Debug_ToggleZoomMode", EInputEvent::IE_Pressed, this, &ASECharacter::ToggleZoomMode);
   PlayerInputComponent->BindAxis("MoveForward", this, &ASECharacter::MoveForward);
   PlayerInputComponent->BindAxis("MoveRight", this, &ASECharacter::MoveRight);

   // We have 2 versions of the rotation bindings to handle different kinds of devices differently
   // "turn" handles devices that provide an absolute delta, such as a mouse.
   // "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
   PlayerInputComponent->BindAxis("Turn", this, &ASECharacter::Turn);
   PlayerInputComponent->BindAxis("TurnRate", this, &ASECharacter::TurnAtRate);
   PlayerInputComponent->BindAxis("LookUp", this, &ASECharacter::LookUp);
   PlayerInputComponent->BindAxis("LookUpRate", this, &ASECharacter::LookUpAtRate);
}

void ASECharacter::ToggleCursorMode()
{
   if (auto PS = CastChecked<ASECharacterState>(PlayerState))
   {
      switch (PS->CursorState)
      {
      case ECharacterCursorState::Locked:
         PS->CursorState = ECharacterCursorState::Free;
         break;
      case ECharacterCursorState::Free:
      default:
         PS->CursorState = ECharacterCursorState::Locked;
         break;
      }
   }
}

void ASECharacter::ToggleZoomMode()
{
   auto ZoomStateString = FString();
   switch (ZoomState)
   {
   case ECharacterZoomState::Outward:
      ZoomStateString = TEXT("None");
      ZoomState = ECharacterZoomState::None;
      break;
   case ECharacterZoomState::Inward:
      ZoomStateString = TEXT("Outward");
      ZoomState = ECharacterZoomState::Outward;
      break;
   case ECharacterZoomState::None:
   default:
      ZoomStateString = TEXT("Inward");
      ZoomState = ECharacterZoomState::Inward;
      break;
   }

   auto Message = FString(TEXT("ZoomState set to: ")).Append(ZoomStateString);
   GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Cyan, Message);
}

void ASECharacter::MoveForward(float Value)
{
   if (State != ECharacterState::Idle || ZoomState != ECharacterZoomState::None)
      return;

   auto PS = CastChecked<ASECharacterState>(PlayerState);
   if (!PS) return;

   if (PS->CursorState == ECharacterCursorState::Locked && Value != 0.0f)
      AddMovementInput(GetActorForwardVector(), Value);
}

void ASECharacter::MoveRight(float Value)
{
   if (State != ECharacterState::Idle || ZoomState != ECharacterZoomState::None)
      return;

   auto PS = CastChecked<ASECharacterState>(PlayerState);
   if (!PS) return;

   if (PS->CursorState == ECharacterCursorState::Locked && Value != 0.0f)
      AddMovementInput(GetActorRightVector(), Value);
}

void ASECharacter::Turn(float Val)
{
   if (State != ECharacterState::Idle || ZoomState != ECharacterZoomState::None)
      return;

   auto PS = CastChecked<ASECharacterState>(PlayerState);
   if (!PS) return;

   if (PS->CursorState == ECharacterCursorState::Locked)
      AddControllerYawInput(Val);
}

void ASECharacter::LookUp(float Val)
{
   if (State != ECharacterState::Idle || ZoomState != ECharacterZoomState::None)
      return;

   auto PS = CastChecked<ASECharacterState>(PlayerState);
   if (!PS) return;

   if (PS->CursorState == ECharacterCursorState::Locked)
      AddControllerPitchInput(Val);
}

void ASECharacter::TurnAtRate(float Rate)
{
   Turn(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void ASECharacter::LookUpAtRate(float Rate)
{
   LookUp(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}
