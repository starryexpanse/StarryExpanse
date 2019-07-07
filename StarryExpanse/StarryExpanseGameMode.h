#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "StarryExpanseGameMode.generated.h"

UCLASS()
class AStarryExpanseGameMode : public AGameModeBase {
  GENERATED_BODY()

public:
  AStarryExpanseGameMode();

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Classes)
  TSubclassOf<APawn> VrPawnClass;
};
