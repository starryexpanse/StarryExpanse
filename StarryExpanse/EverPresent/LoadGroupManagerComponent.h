#pragma once
#include "LoadGroupManagerComponent.generated.h"
#include "LoadGroups/ELoadGroups.h"

UCLASS(Blueprintable, Config = Game)
class ULoadGroupManagerComponent : public UActorComponent {
public:
  GENERATED_BODY()
  // Class Constructor
  ULoadGroupManagerComponent();

  UFUNCTION(Category = "Callbacks")
  void LevelLoaded();

  void LoadLoadGroup();
};
