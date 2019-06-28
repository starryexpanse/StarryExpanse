// Copyright, 59 Volt Entertainment, all rights reserved.

#pragma once

#include "CoreMinimal.h"

#include "Runtime/Engine/Classes/GameFramework/Info.h"

#include "ASoundConfigurationBase.generated.h"

UCLASS(transient, config = Audio, notplaceable)
class STARRYEXPANSE_API ASoundConfigurationBase : public AInfo {
  GENERATED_UCLASS_BODY()

public:
  UFUNCTION()

  /** @return true if this data structure is valid */
  virtual bool IsValid() const;
};
