// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Classes/Components/BoxComponent.h"
#include "LevelLoadingTwoWayBox.generated.h"

UCLASS()
class STARRYEXPANSE_API ALevelLoadingTwoWayBox : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALevelLoadingTwoWayBox(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(BlueprintReadWrite)
	UBoxComponent* BoxA;

	UPROPERTY(BlueprintReadWrite)
	UBoxComponent* BoxB;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float Separation;

	void EnterATowardsB();

	// Delegates
	TScriptDelegate<FWeakObjectPtr> BLoaded_AfterIntersectATowardB;
	TScriptDelegate<FWeakObjectPtr> ALoaded_AfterBLoaded_AfterIntersectATowardB;
	TScriptDelegate<FWeakObjectPtr> ALoaded_AfterIntersectAAwayFromB;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void OnConstruction(const FTransform & Transform) override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	
};
