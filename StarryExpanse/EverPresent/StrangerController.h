//
// Copyright 2018 59 Volt Entertainment, all rights reserved.
//

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "StrangerController.generated.h"

UCLASS()
class STARRYEXPANSE_API AStrangerController : public APlayerController {
  GENERATED_BODY()

public:
  AStrangerController();

  UFUNCTION()
  void PossiblyFreezeOrUnfreeze();
    
  UFUNCTION()
  void Interact();
  
  UFUNCTION()
  FHitResult CastInteractionRay(bool &gotHit, FVector worldLocation, FVector worldDirection);

protected:
  virtual void BeginPlay() override;
  virtual void Destroyed() override;
  virtual void SetupInputComponent() override;
};
