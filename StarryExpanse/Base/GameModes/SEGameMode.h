#pragma once
#include "GameFramework/GameMode.h"
#include "EverPresent/LoadGroupManagerComponent.h"
#include "SEGameMode.generated.h"

UCLASS(MinimalAPI)
class ASEGameMode : public AGameMode
{
   GENERATED_BODY()

public:
    ASEGameMode();

    virtual void BeginPlay() override;

    UPROPERTY(BlueprintReadOnly)
    ULoadGroupManagerComponent* LoadGroupManagerComponent;
};
