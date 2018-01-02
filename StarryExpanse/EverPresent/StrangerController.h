//
// Copyright 2018 59 Volt Entertainment, all rights reserved.
//

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "RivenGameInstance.h"
#include "StrangerController.generated.h"

UCLASS()
class STARRYEXPANSE_API AStrangerController : public APlayerController {
  GENERATED_BODY()

public:
  AStrangerController();

  UFUNCTION()
  void PossiblyFreezeOrUnfreeze();

protected:
  virtual void BeginPlay() override;
  virtual void Destroyed() override;
};
