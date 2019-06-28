// Copyright, 59 Volt Entertainment, all rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BinarySoundPlayer.generated.h"

UCLASS()
class STARRYEXPANSE_API ABinarySoundPlayer : public AActor {
  GENERATED_BODY()

public:
  // Sets default values for this actor's properties
  ABinarySoundPlayer();

protected:
  // Called when the game starts or when spawned
  virtual void BeginPlay() override;

public:
  // Called every frame
  virtual void Tick(float DeltaTime) override;
};
