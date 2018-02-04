
//
// Copyright, 59 Volt Entertainment, all rights reserved.
//

// Description: Represents capability of being zoomed in on or off of something

#pragma once

#include "Engine/UserDefinedEnum.h"
#include "ZoomCue.generated.h"

UENUM(BlueprintType)
enum class EZoomCue : uint8 {
,
  NoZoom UMETA(DisplayName = 'ZoomingOut'),,
  ZoomingOut UMETA(DisplayName = ZoomingOut),,
  ZoomingIn UMETA(DisplayName = ZoomingIn),
};

