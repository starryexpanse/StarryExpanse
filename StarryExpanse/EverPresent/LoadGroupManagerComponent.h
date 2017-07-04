#pragma once
#include "LoadGroups/ELoadGroups.h"
#include "LoadGroupManagerComponent.generated.h"

UCLASS(Blueprintable, Config = Game)
class ULoadGroupManagerComponent : public UActorComponent
{
public:
   GENERATED_BODY()
      // Class Constructor
    ULoadGroupManagerComponent();

    UFUNCTION(Category = "Callbacks")
    void LevelLoaded();

    void LoadLoadGroup();
};
