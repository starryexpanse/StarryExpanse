// Fill out your copyright notice in the Description page of Project Settings.

#include "StrangerPawn.h"
#include "StarryExpanse.h"
#include "Components/CapsuleComponent.h"

FName AStrangerPawn::MeshComponentName(TEXT("CharacterMesh0"));
FName AStrangerPawn::CharacterMovementComponentName(TEXT("CharMoveComp"));
FName AStrangerPawn::CapsuleComponentName(TEXT("CollisionCylinder"));

// Sets default values
AStrangerPawn::AStrangerPawn() {
  // Set this pawn to call Tick() every frame.  You can turn this off to improve
  // performance if you don't need it.
  PrimaryActorTick.bCanEverTick = true;

  CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(
      AStrangerPawn::CapsuleComponentName);
  CapsuleComponent->InitCapsuleSize(34.0f, 88.0f);
  CapsuleComponent->SetCollisionProfileName(
      UCollisionProfile::Pawn_ProfileName);

  CapsuleComponent->CanCharacterStepUpOn = ECB_No;
  CapsuleComponent->SetShouldUpdatePhysicsVolume(true);
  CapsuleComponent->bCheckAsyncSceneOnMove = false;
  CapsuleComponent->SetCanEverAffectNavigation(false);
  CapsuleComponent->bDynamicObstacle = true;
  RootComponent = CapsuleComponent;

  CharacterMovement = CreateDefaultSubobject<UCharacterMovementComponent>(
      AStrangerPawn::CharacterMovementComponentName);
  if (CharacterMovement) {
    CharacterMovement->UpdatedComponent = CapsuleComponent;
  }
}

float AStrangerPawn::GetDefaultHalfHeight() const {
  UCapsuleComponent *DefaultCapsule =
      GetClass()->GetDefaultObject<AStrangerPawn>()->CapsuleComponent;
  if (DefaultCapsule) {
    return DefaultCapsule->GetScaledCapsuleHalfHeight();
  } else {
    return Super::GetDefaultHalfHeight();
  }
}

// Called when the game starts or when spawned
void AStrangerPawn::BeginPlay() { Super::BeginPlay(); }

// Called every frame
void AStrangerPawn::Tick(float DeltaTime) { Super::Tick(DeltaTime); }

// Called to bind functionality to input
void AStrangerPawn::SetupPlayerInputComponent(
    UInputComponent *PlayerInputComponent) {
  Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AStrangerPawn::Destroyed() { STARRY_WARNING("Starry Pawn destroyed"); }
