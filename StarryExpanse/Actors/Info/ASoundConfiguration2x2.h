// Copyright, 59 Volt Entertainment, all rights reserved.

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/Actor.h"
#include "Runtime/Engine/Classes/Components/SceneComponent.h"
#include "Runtime/Engine/Classes/GameFramework/Info.h"
#include "Runtime/Engine/Classes/Sound/SoundBase.h"
#include "Actors//Info/ASoundConfigurationBase.h"

#include "ASoundConfiguration2x2.generated.h"

UCLASS(transient, config = Audio, notplaceable)
class STARRYEXPANSE_API ASoundConfiguration2x2
    : public ASoundConfigurationBase {
  GENERATED_UCLASS_BODY()

public:
  UFUNCTION()
  void Initialize(USceneComponent *Sound1Locator,
                  USceneComponent *Sound2Locator, USoundBase *Position1Sound1,
                  USoundBase *Position1Sound2, USoundBase *Position2Sound1,
                  USoundBase *Position2Sound2);

  UPROPERTY(BlueprintReadWrite)
  USceneComponent *Sound1Locator;

  UPROPERTY(BlueprintReadWrite)
  USceneComponent *Sound2Locator;

  UPROPERTY(BlueprintReadWrite)
  USoundBase *Position1Sound1;

  UPROPERTY(BlueprintReadWrite)
  USoundBase *Position1Sound2;

  UPROPERTY(BlueprintReadWrite)
  USoundBase *Position2Sound1;

  UPROPERTY(BlueprintReadWrite)
  USoundBase *Position2Sound2;

  /** @return true if this data structure is valid */
  virtual bool IsValid() const override;
};
