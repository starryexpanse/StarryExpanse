// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LoadGroupManager.generated.h"

UCLASS()
class STARRYEXPANSE_API ALoadGroupManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALoadGroupManager();

   FCriticalSection mutex; 

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
};
