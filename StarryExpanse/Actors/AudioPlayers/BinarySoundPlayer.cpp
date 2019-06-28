// Copyright, 59 Volt Entertainment, all rights reserved.

#include "BinarySoundPlayer.h"

// Sets default values
ABinarySoundPlayer::ABinarySoundPlayer() {
  // Set this actor to call Tick() every frame.  You can turn this off to
  // improve performance if you don't need it.
  PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ABinarySoundPlayer::BeginPlay() { Super::BeginPlay(); }

// Called every frame
void ABinarySoundPlayer::Tick(float DeltaTime) { Super::Tick(DeltaTime); }
