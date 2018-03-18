//
// Copyright, 59 Volt Entertainment, all rights reserved.
//

// Description: Represents capability of being zoomed in on or off of something

#pragma once

#include "Engine/UserDefinedEnum.h"
#include "EZoomCue.generated.h"

UENUM(BlueprintType)
enum class EZoomCue : uint8 {
  NoZoom UMETA(DisplayName = "No Zoom"),
  ZoomingOut UMETA(DisplayName = "Zooming Out"),
  ZoomingIn UMETA(DisplayName = "Zooming In")
};
