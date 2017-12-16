// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Classes/Components/BoxComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LevelLoadingTwoWayBox.generated.h"
#include "LoadGroups/ELoadGroups.h"
#include "RivenGameInstance.h"

UCLASS()
class STARRYEXPANSE_API ALevelLoadingTwoWayBox : public AActor {
  GENERATED_BODY()

public:
  // Sets default values for this actor's properties
  ALevelLoadingTwoWayBox(const FObjectInitializer &ObjectInitializer);

  UPROPERTY(BlueprintReadWrite)
  UBoxComponent *BoxA;

  UPROPERTY(BlueprintReadWrite)
  UBoxComponent *BoxB;

  UPROPERTY(BlueprintReadWrite)
  UBoxComponent *MainBox;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  float Separation;

  void IntersectFromB();
  void IntersectFromA();
  void LeaveToA();
  void LeaveToB();

  bool bShouldRecycle = false;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  ELoadGroups BSideLoadGroup;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  ELoadGroups ASideLoadGroup;

  // Delegates
  TScriptDelegate<FWeakObjectPtr> BLoaded_AfterIntersectFromA;
  TScriptDelegate<FWeakObjectPtr> ALoaded_AfterBLoaded_AfterIntersectFromA;
  TScriptDelegate<FWeakObjectPtr> ALoaded_AfterLeaveToA;
  TScriptDelegate<FWeakObjectPtr> ALoaded_AfterIntersectFromB;
  TScriptDelegate<FWeakObjectPtr> BLoaded_AfterALoaded_AfterIntersectFromB;
  TScriptDelegate<FWeakObjectPtr> BLoaded_AfterLeaveToB;

  // Callbacks
  UFUNCTION()
  void Cbk_Intersect(UPrimitiveComponent *OverlappedComponent,
                     AActor *OtherActor, UPrimitiveComponent *OtherComp,
                     int32 OtherBodyIndex, bool bFromSweep,
                     const FHitResult &SweepResult);

  UFUNCTION()
  void Cbk_Leave(UPrimitiveComponent *OverlappedComponent, AActor *OtherActor,
                 UPrimitiveComponent *OtherComp, int32 OtherBodyIndex);

  UFUNCTION()
  void Cbk_BLoaded_AfterIntersectFromA();

  UFUNCTION()
  void Cbk_ALoaded_AfterBLoaded_AfterIntersectFromA();

  UFUNCTION()
  void Cbk_ALoaded_AfterIntersectFromB();

  UFUNCTION()
  void Cbk_BLoaded_AfterALoaded_AfterIntersectFromB();

  UFUNCTION()
  void Cbk_BLoaded_AfterLeaveToB();

  UFUNCTION()
  void Cbk_ALoaded_AfterLeaveToA();

protected:
  // Called when the game starts or when spawned
  virtual void BeginPlay() override;
  virtual void OnConstruction(const FTransform &Transform) override;
  virtual void PostInitializeComponents();
};
