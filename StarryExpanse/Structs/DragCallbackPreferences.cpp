//
// Copyright, 59 Volt Entertainment, all rights reserved.
//

#include "DragCallbackPreferences.h"

FDragCallbackPreferences FDragCallbackPreferences::ModerateDelay_Simple() {
  FDragCallbackPreferences response;

  response.MinimumStrobeDelay = 70;
  response.ReceiveHitInfoBeforeEveryUpdate = false;

  return response;
}

FDragCallbackPreferences FDragCallbackPreferences::NoUpdates() {
  FDragCallbackPreferences response;

  response.MinimumStrobeDelay = TNumericLimits<float>::Max();
  response.ReceiveHitInfoBeforeEveryUpdate = false;

  return response;
}