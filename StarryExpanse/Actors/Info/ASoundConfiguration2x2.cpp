// Copyright, 59 Volt Entertainment, all rights reserved.

#include "ASoundConfiguration2x2.h"

ASoundConfiguration2x2::ASoundConfiguration2x2(
    const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer) {}

void ASoundConfiguration2x2::Initialize(USceneComponent *Sound1Locator,
                                        USceneComponent *Sound2Locator,
                                        USoundBase *Position1Sound1,
                                        USoundBase *Position1Sound2,
                                        USoundBase *Position2Sound1,
                                        USoundBase *Position2Sound2) {
  this->Sound1Locator = Sound1Locator;
  this->Sound2Locator = Sound2Locator;
  this->Position1Sound1 = Position1Sound1;
  this->Position1Sound2 = Position1Sound2;
  this->Position2Sound1 = Position2Sound1;
  this->Position2Sound2 = Position2Sound2;
}

bool ASoundConfiguration2x2::IsValid() const {
  return (Sound1Locator != nullptr && Sound2Locator != nullptr &&
          Position1Sound1 != nullptr && Position1Sound2 != nullptr &&
          Position2Sound1 != nullptr && Position2Sound2 != nullptr);
}
