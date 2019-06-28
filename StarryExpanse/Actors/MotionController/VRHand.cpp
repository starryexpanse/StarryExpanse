// Fill out your copyright notice in the Description page of Project Settings.

#include "VRHand.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "DrawDebugHelpers.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "Engine/Engine.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

// TEMP
#include "Actors//Player/VRPawn.h"
#include "Runtime/Engine/Classes/Camera/CameraComponent.h"

AVRHand::AVRHand() {}

void AVRHand::Tick(float DeltaTime) { Super::Tick(DeltaTime); }
