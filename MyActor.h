// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

/**
 * 
 */
UCLASS()
class STARRYEXPANSE_API AMyActor : public AActor
{
	GENERATED_UCLASS_BODY()

protected:

	virtual void BeginPlay() override;
	
};
