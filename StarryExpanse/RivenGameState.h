#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/GameStateBase.h"
#include "SaveGame/RivenSaveGame.h"
#include "Interfaces/RivenSavegameAware.h"
#include "Runtime/Core/Public/UObject/WeakObjectPtrTemplates.h"
#include "Runtime/Core/Public/GenericPlatform/GenericPlatform.h"
#include "RivenGameState.generated.h"

UCLASS()
class ARivenGameState : public AGameStateBase {
  GENERATED_BODY()

public:
  ARivenGameState();

  void OnConstruction(const FTransform &Transform) override;

  UPROPERTY(BlueprintReadOnly)
  URivenSaveGame *Instantaneous_SaveGame;

  UPROPERTY()
  TMap<uint32, TWeakObjectPtr<AActor>> SubscribedToSavegame;

  UFUNCTION()
  void NotifySubscribersOfChange(URivenSaveGame *OldSaveGame);

  UFUNCTION(BlueprintCallable)
  void SubscribeActorToSavegame(AActor* Actor);

  UFUNCTION(BlueprintCallable)
  void UnsubscribeActorFromSavegame(AActor* Actor);
};
