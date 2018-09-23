// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "StarryExpanseHUD.h"
#include "EverPresent/StrangerController.h"
#include "CanvasItem.h"
#include "Engine/Canvas.h"
#include "Engine/Texture2D.h"
#include "Runtime/HeadMountedDisplay/Public/HeadMountedDisplayFunctionLibrary.h"
#include "Interfaces/RivenInteractable.h"
#include "TextureResource.h"
#include "UObject/ConstructorHelpers.h"
#include "RivenGameState.h"
#include <algorithm>

AStarryExpanseHUD::AStarryExpanseHUD() {
  // Resolve textures
  static ConstructorHelpers::FObjectFinder<UTexture2D> TexHollowRingObj(
      TEXT("Texture2D'/Game/StarryExpanse/Interface/Cursors/"
           "T_Cursor_Empty_Ring.T_Cursor_Empty_Ring'"));
  TexHollowRing = TexHollowRingObj.Object;

  static ConstructorHelpers::FObjectFinder<UTexture2D> TexDotObject(
      TEXT("Texture2D'/Game/StarryExpanse/Interface/Cursors/"
           "T_Cursor_Dot.T_Cursor_Dot'"));
  TexDot = TexDotObject.Object;

  static ConstructorHelpers::FObjectFinder<UTexture2D> TexZoomOutObject(
      TEXT("Texture2D'/Game/StarryExpanse/Interface/Cursors/"
           "T_Cursor_Zoom_Out.T_Cursor_Zoom_Out'"));
  TexZoomOut = TexZoomOutObject.Object;
}

FVector2D AStarryExpanseHUD::GetCrosshairDrawPosition(
    FVector2D crosshairDims, FVector2D screenDims, FVector2D cursorPosition) {
  return screenDims * cursorPosition - crosshairDims / 2.0;
}

UTexture2D *AStarryExpanseHUD::GetCursorTexture(FVector2D screenDims,
                                                FVector2D cursorPosition) {
  // Test if cursor hit object and inspect properties for determining which
  // cursor texture to display
  bool gotHit;

  const FLinearColor kSquareColor(1.0f, 1.0f, 0.0f, 0.3f);
  auto controller =
      Cast<AStrangerController>(this->GetOwningPlayerController());

  FVector worldLocation;
  FVector worldDirection;
  controller->DeprojectScreenPositionToWorld(screenDims.X * cursorPosition.X,
                                             screenDims.Y * cursorPosition.Y,
                                             worldLocation, worldDirection);
  FHitResult result =
      controller->CastInteractionRay(gotHit, worldLocation, worldDirection);

  if (gotHit) {
    auto actor = result.GetActor();
    if (actor != nullptr && actor->GetClass()->ImplementsInterface(
                                URivenInteractable::StaticClass())) {
      auto probeResult =
          IRivenInteractable::Execute_ProbeInteractability(actor);
      if (probeResult.ZoomCue == EZoomCue::ZoomingOut) {
        return TexZoomOut;
      } else {
        if (probeResult.CanBeTapped) {
          return TexDot;
        } else {
          return TexHollowRing;
        }
      }
    }
  }

  return TexHollowRing;
}

void AStarryExpanseHUD::DrawHUD() {
  float width = Canvas->ClipX;
  float height = Canvas->ClipY;
  FVector2D screenDims(width, height);
  auto controller =
      Cast<AStrangerController>(this->GetOwningPlayerController());

  // Draw very simple crosshair

  FVector2D cursorPosition(FVector2D(0.5, 0.5f));

  bool isLocked;
  if (controller != nullptr) {
    isLocked = controller->IsCursorLockedToCenter;
    if (!isLocked) {
      cursorPosition = FVector2D(controller->HorizontalMousePosition,
                                 controller->VerticalMousePosition);
    }
  } else {
    isLocked = true; // initial state of controller as of this writing
  }

  auto cursorTex = this->GetCursorTexture(screenDims, cursorPosition);
  auto actualPixelDims = FVector2D(64, 64);

  // offset by half the texture's dimensions so that the center of the texture
  // aligns with the center of the Canvas
  const FVector2D CrosshairDrawPosition =
      AStarryExpanseHUD::GetCrosshairDrawPosition(
          actualPixelDims, screenDims,
          isLocked ? FVector2D(0.5, 0.5f) : cursorPosition);

  // draw the crosshair

  if (!UHeadMountedDisplayFunctionLibrary::IsHeadMountedDisplayEnabled()) {
    FCanvasTileItem TileItem(CrosshairDrawPosition, cursorTex->Resource,
                             FLinearColor::White);
    TileItem.PivotPoint = FVector2D(0.5, 0.5);
    TileItem.BlendMode = SE_BLEND_Translucent;
    TileItem.Size = actualPixelDims;
    TileItem.Z = 1000;
    Canvas->DrawItem(TileItem);
  }

  // Draw grid of colored tiles for debugging whether hits were reached

  auto gs = Cast<ARivenGameState>(GetWorld()->GetGameState());
  if (!gs) {
    return;
  }

  if (gs->IsShowingDebugHitScreenOverlay) {
    const float kNumXDivisions = 100.0f;
    const float kNumYDivisions = 100.0f;
    const float kSquareWidth = width / kNumXDivisions;
    const float kSquareHeight = height / kNumYDivisions;

    bool gotHit;

    const FLinearColor kSquareColor(1.0f, 1.0f, 0.0f, 0.3f);

    for (float x = 0.0f; x < width; x += kSquareWidth) {
      for (float y = 0.0f; y < height; y += kSquareHeight) {
        FVector worldLocation;
        FVector worldDirection;
        controller->DeprojectScreenPositionToWorld(
            x + kSquareWidth / 2.0f, y + kSquareHeight / 2.0f, worldLocation,
            worldDirection);
        FHitResult result = controller->CastInteractionRay(
            gotHit, worldLocation, worldDirection);

        if (gotHit) {
          auto actor = result.GetActor();
          if (actor != nullptr && actor->GetClass()->ImplementsInterface(
                                      URivenInteractable::StaticClass())) {
            auto probeResponse =
                IRivenInteractable::Execute_ProbeInteractability(actor);
            if (probeResponse.CanBeTapped) {
              this->DrawRect(kSquareColor, x, y, kSquareWidth, kSquareHeight);
            }
          }
        }
      }
    }
  }
}
