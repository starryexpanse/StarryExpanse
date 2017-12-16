#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "SaveGame/RivenSaveGame.h"
#include "RivenGameState.generated.h"

UCLASS()
class ARivenGameState : public AGameStateBase {
  GENERATED_BODY()

public:
  ARivenGameState();

  void OnConstruction(const FTransform &Transform) override;

  UPROPERTY(BlueprintReadOnly)
  URivenSaveGame *Instantaneous_SaveGame;
};
