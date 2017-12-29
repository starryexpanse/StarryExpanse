#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "SaveGame/RivenSaveGame.h"
#include "Interfaces/RivenSavegameAware.h"
#include "Runtime/Core/Public/Templates/SharedPointer.h"
#include "RivenGameState.generated.h"

UCLASS()
class ARivenGameState : public AGameStateBase {
  GENERATED_BODY()

public:
  ARivenGameState();

  void OnConstruction(const FTransform &Transform) override;

  UPROPERTY(BlueprintReadOnly)
  URivenSaveGame *Instantaneous_SaveGame;

  //TSet<TWeakPtr<AActor>> SubscribedToSavegame;

  UFUNCTION()
  void NotifySubscribersOfChange(URivenSaveGame *OldSaveGame);

  //UFUNCTION(BlueprintCallable)
  //void SubscribeActorToSavegame(IRivenSavegameAware* Actor);

  //UFUNCTION(BlueprintCallable)
  //void UnsubscribeActorFromSavegame(IRivenSavegameAware* Actor);
};
