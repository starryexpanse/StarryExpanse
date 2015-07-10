#include "StarryExpanse.h"
#include "BaseStarryCharacter.h"
#include "StarryController.h"

ABaseStarryCharacter::ABaseStarryCharacter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Create a CameraComponent	
	FirstPersonCameraComponent = ObjectInitializer.CreateDefaultSubobject<UCameraComponent>(this, TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->AttachParent = GetCapsuleComponent();
	FirstPersonCameraComponent->RelativeLocation = FVector(0, 0, 64.f); // Position the camera
	FirstPersonCameraComponent->bUsePawnControlRotation = true;

	// Default offset from the character location for projectiles to spawn
	GunOffset = FVector(100.0f, 30.0f, 10.0f);

	// Create a mesh component that will be used when being viewed from a '1st person' view (when controlling this pawn)
	Mesh1P = ObjectInitializer.CreateDefaultSubobject<USkeletalMeshComponent>(this, TEXT("CharacterMesh1P"));
	Mesh1P->SetOnlyOwnerSee(true);			// only the owning player will see this mesh
	Mesh1P->AttachParent = FirstPersonCameraComponent;
	Mesh1P->RelativeLocation = FVector(0.f, 0.f, -150.f);
	Mesh1P->bCastDynamicShadow = false;
	Mesh1P->CastShadow = false;

	// Note: The ProjectileClass and the skeletal mesh/anim blueprints for Mesh1P are set in the
	// derived blueprint asset named MyCharacter (to avoid direct content references in C++)

}



//////////////////////////////////////////////////////////////////////////
// Input

void ABaseStarryCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	
	// set up gameplay key bindings
	check(InputComponent);


	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "Setup Input Component");

	InputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	InputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	InputComponent->BindAction("Switch Cursor Mode", IE_Pressed, this, &ABaseStarryCharacter::OnSwitchCursorMode);
	
	InputComponent->BindAction("Fire", IE_Pressed, this, &ABaseStarryCharacter::OnFire);
	InputComponent->BindTouch(EInputEvent::IE_Pressed, this, &ABaseStarryCharacter::TouchStarted);

	InputComponent->BindAxis("MoveForward", this, &ABaseStarryCharacter::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &ABaseStarryCharacter::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	InputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	InputComponent->BindAxis("TurnRate", this, &ABaseStarryCharacter::TurnAtRate);
	InputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	InputComponent->BindAxis("LookUpRate", this, &ABaseStarryCharacter::LookUpAtRate);
	
}

void ABaseStarryCharacter::OnSwitchCursorMode()
{
	if (!Controller) {
		return;
	}

	AStarryController *c = Cast<AStarryController>(Controller);

	if (!c) {
		return;
	}

	c->TrySwitchCursorMode();	
}

void ABaseStarryCharacter::OnFire()
{
	//UWorld* myworld = this->GetWorld();

	//TArray<struct FHitResult> OutHits;

	//, const FVector& Start, const FVector& End, ECollisionChannel TraceChannel, const struct FCollisionQueryParams& Params, const struct FCollisionResponseParams& ResponseParam

	//myworld->LineTraceMulti(
	//	OutHits,
	//	this->
	//);


	// try and play the sound if specified
	if (FireSound != NULL)
	{
		UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
	}

	/*
	// try and play a firing animation if specified
	if (FireAnimation != NULL)
	{
		// Get the animation object for the arms mesh
		UAnimInstance* AnimInstance = Mesh1P->GetAnimInstance();
		if (AnimInstance != NULL)
		{
			AnimInstance->Montage_Play(FireAnimation, 1.f);
		}
	}
	*/

}

void ABaseStarryCharacter::TouchStarted(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	// only fire for first finger down
	if (FingerIndex == 0)
	{
		OnFire();
	}
}

void ABaseStarryCharacter::MoveForward(float Value)
{
	if (Value != 0.0f)
	{
		// add movement in that direction
		AddMovementInput(GetActorForwardVector(), Value);
	}
}

void ABaseStarryCharacter::MoveRight(float Value)
{
	if (Value != 0.0f)
	{
		// add movement in that direction
		AddMovementInput(GetActorRightVector(), Value);
	}
}

void ABaseStarryCharacter::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void ABaseStarryCharacter::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void ABaseStarryCharacter::FellOutOfWorld(const class UDamageType& dmgType) {
	this->CustomFellOutOfWorld();
}
//
//void ABaseStarryCharacter::CustomFellOutOfWorld() const {
//}
//
void ABaseStarryCharacter::CustomFellOutOfWorld_Implementation() {
}