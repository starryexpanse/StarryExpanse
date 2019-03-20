// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/CharacterMovementComponent.h"
#include "UObject/ObjectMacros.h"
#include "Components/CapsuleComponent.h"
#include "Engine/CollisionProfile.h"
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "StrangerPawn.generated.h"

/** MovementBaseUtility provides utilities for working with movement bases, for
 * which we may need relative positioning info. */
namespace StrangerPawnMovementBaseUtility {
/** Determine whether MovementBase can possibly move. */
ENGINE_API bool IsDynamicBase(const UPrimitiveComponent *MovementBase);

/** Determine if we should use relative positioning when based on a component
 * (because it may move). */
FORCEINLINE bool UseRelativeLocation(const UPrimitiveComponent *MovementBase) {
  return IsDynamicBase(MovementBase);
}

/** Ensure that BasedObjectTick ticks after NewBase */
ENGINE_API void AddTickDependency(FTickFunction &BasedObjectTick,
                                  UPrimitiveComponent *NewBase);

/** Remove tick dependency of BasedObjectTick on OldBase */
ENGINE_API void RemoveTickDependency(FTickFunction &BasedObjectTick,
                                     UPrimitiveComponent *OldBase);

/** Get the velocity of the given component, first checking the
 * ComponentVelocity and falling back to the physics velocity if necessary. */
ENGINE_API FVector GetMovementBaseVelocity(
    const UPrimitiveComponent *MovementBase, const FName BoneName);

/** Get the tangential velocity at WorldLocation for the given component. */
ENGINE_API FVector GetMovementBaseTangentialVelocity(
    const UPrimitiveComponent *MovementBase, const FName BoneName,
    const FVector &WorldLocation);

/** Get the transforms for the given MovementBase, optionally at the location of
 * a bone. Returns false if MovementBase is nullptr, or if BoneName is not a
 * valid bone. */
ENGINE_API bool
GetMovementBaseTransform(const UPrimitiveComponent *MovementBase,
                         const FName BoneName, FVector &OutLocation,
                         FQuat &OutQuat);
} // namespace StrangerPawnMovementBaseUtility

USTRUCT()
struct FStrangerPawnBasedMovementInfo {
  GENERATED_USTRUCT_BODY()

  /** Component we are based on */
  UPROPERTY()
  UPrimitiveComponent *MovementBase;

  /** Bone name on component, for skeletal meshes. NAME_None if not a skeletal
   * mesh or if bone is invalid. */
  UPROPERTY()
  FName BoneName;

  /** Location relative to MovementBase. Only valid if HasRelativeLocation() is
   * true. */
  UPROPERTY()
  FVector_NetQuantize100 Location;

  /** Rotation: relative to MovementBase if HasRelativeRotation() is true,
   * absolute otherwise. */
  UPROPERTY()
  FRotator Rotation;

  /** Whether the server says that there is a base. On clients, the component
   * may not have resolved yet. */
  UPROPERTY()
  bool bServerHasBaseComponent;

  /** Whether rotation is relative to the base or absolute. It can only be
   * relative if location is also relative. */
  UPROPERTY()
  bool bRelativeRotation;

  /** Whether there is a velocity on the server. Used for forcing replication
   * when velocity goes to zero. */
  UPROPERTY()
  bool bServerHasVelocity;

  /** Is location relative? */
  FORCEINLINE bool HasRelativeLocation() const {
    return StrangerPawnMovementBaseUtility::UseRelativeLocation(MovementBase);
  }

  /** Is rotation relative or absolute? It can only be relative if location is
   * also relative. */
  FORCEINLINE bool HasRelativeRotation() const {
    return bRelativeRotation && HasRelativeLocation();
  }

  /** Return true if the client should have MovementBase, but it hasn't
   * replicated (possibly component has not streamed in). */
  FORCEINLINE bool IsBaseUnresolved() const {
    return (MovementBase == nullptr) && bServerHasBaseComponent;
  }
};

UCLASS()
class STARRYEXPANSE_API AStrangerPawn : public APawn {
  GENERATED_BODY()

public:
  // Sets default values for this pawn's properties
  AStrangerPawn();
  static FName MeshComponentName;
  static FName CharacterMovementComponentName;
  static FName CapsuleComponentName;

  /** The CapsuleComponent being used for movement collision (by
   * CharacterMovement). Always treated as being vertically aligned in simple
   * collision check functions. */
  UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly)
  UCapsuleComponent *CapsuleComponent;

protected:
  // Called when the game starts or when spawned
  virtual void BeginPlay() override;
  virtual void Destroyed() override;

private:
  UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly,
            meta = (AllowPrivateAccess = "true"))
  UCharacterMovementComponent *CharacterMovement;

public:
  // Called every frame
  virtual void Tick(float DeltaTime) override;

  UPROPERTY()
  struct FStrangerPawnBasedMovementInfo BasedMovement;

  //~ Begin APawn Interface.
  virtual void PostInitializeComponents() override;
  virtual UPawnMovementComponent *GetMovementComponent() const override;
  virtual UPrimitiveComponent *GetMovementBase() const override final {
    return BasedMovement.MovementBase;
  }
  virtual float GetDefaultHalfHeight() const override;
  virtual void TurnOff() override;
  virtual void Restart() override;
  virtual void PawnClientRestart() override;
  virtual void PossessedBy(AController *NewController) override;
  virtual void UnPossessed() override;
  // Called to bind functionality to input
  virtual void SetupPlayerInputComponent(
      class UInputComponent *PlayerInputComponent) override;
  virtual void DisplayDebug(class UCanvas *Canvas,
                            const FDebugDisplayInfo &DebugDisplay, float &YL,
                            float &YPos) override;
  virtual void RecalculateBaseEyeHeight() override;
  virtual void UpdateNavigationRelevance() override;
  //~ End APawn Interface
};
