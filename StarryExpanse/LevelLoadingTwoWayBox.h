// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Classes/Components/BoxComponent.h"
#include "LoadGroups/ELoadGroups.h"
#include "RivenGameInstance.h"
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

	void IntersectATowardB();
	void IntersectAAwayFromB();
	void IntersectBTowardA();
	void IntersectBAwayFromA();

	bool bShouldRecycle = false;

	UPROPERTY(BlueprintReadWrite)
	ELoadGroups BSideLoadGroup;

	UPROPERTY(BlueprintReadWrite)
	ELoadGroups ASideLoadGroup;

	// Delegates
	TScriptDelegate<FWeakObjectPtr> BLoaded_AfterIntersectATowardB;
	TScriptDelegate<FWeakObjectPtr> ALoaded_AfterBLoaded_AfterIntersectATowardB;
	TScriptDelegate<FWeakObjectPtr> ALoaded_AfterIntersectAAwayFromB;

	// Callbacks
	void Cbk_IntersectA(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	void Cbk_IntersectB(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	void Cbk_BLoaded_AfterIntersectATowardB();
	void Cbk_ALoaded_AfterBLoaded_AfterIntersectATowardB();
	void Cbk_ALoaded_AfterIntersectAAwayFromB();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void OnConstruction(const FTransform & Transform) override;
	virtual void PostInitializeComponents();
		
};
