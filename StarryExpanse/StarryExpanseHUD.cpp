// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "StarryExpanseHUD.h"
#include "EverPresent/StrangerController.h"
#include "CanvasItem.h"
#include "Engine/Canvas.h"
#include "Engine/Texture2D.h"
#include "Runtime/HeadMountedDisplay/Public/HeadMountedDisplayFunctionLibrary.h"
#include "Actors/RivenInteractable.h"
#include "TextureResource.h"
#include "UObject/ConstructorHelpers.h"
#include <algorithm>

AStarryExpanseHUD::AStarryExpanseHUD() {
  // Set the crosshair texture
  static ConstructorHelpers::FObjectFinder<UTexture2D> CrosshairTexObj(
      TEXT("Texture2D'/Game/FirstPerson/Textures/"
           "FirstPersonCrosshair.FirstPersonCrosshair'"));
  CrosshairTex = CrosshairTexObj.Object;
}

FVector2D AStarryExpanseHUD::GetCrosshairDrawPosition(float crosshairHeight, FVector2D screenDims, FVector2D cursorPosition) {
  return screenDims * cursorPosition + FVector2D(0, crosshairHeight / 2.0);
}

void AStarryExpanseHUD::DrawHUD() {
  float width = Canvas->ClipX;
  float height = Canvas->ClipY;
  FVector2D screenDims(width, height);
  auto controller = Cast<AStrangerController>(this->GetOwningPlayerController());

  // Draw very simple crosshair

  FVector2D CursorPosition(FVector2D::ZeroVector);

  bool isLocked;
  if (controller != nullptr) {
    isLocked = controller->IsCursorLockedToCenter;
    if (!isLocked) {
      CursorPosition = FVector2D(controller->HorizontalMousePosition * 2 - 1, controller->VerticalMousePosition * 2 - 1);
    }
  }
  else {
    isLocked = true; // initial state of controller as of this writing
  }

  // offset by half the texture's dimensions so that the center of the texture
  // aligns with the center of the Canvas
  const FVector2D CrosshairDrawPosition = AStarryExpanseHUD::GetCrosshairDrawPosition(40.0f, screenDims, isLocked ? FVector2D(0.5f, 0.5f) : CursorPosition);

  // draw the crosshair

  if (!UHeadMountedDisplayFunctionLibrary::IsHeadMountedDisplayEnabled()) {
    FCanvasTileItem TileItem(
      CrosshairDrawPosition,
      CrosshairTex->Resource,
      FLinearColor::White
    );
    TileItem.PivotPoint = FVector2D(0.5, 0.5);
    TileItem.BlendMode = SE_BLEND_Translucent;
    Canvas->DrawItem(TileItem);
  }

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
      controller->DeprojectScreenPositionToWorld(x + kSquareWidth / 2.0f,
        y + kSquareHeight / 2.0f, worldLocation, worldDirection);
      FHitResult result = controller->CastInteractionRay(
        gotHit,
        worldLocation,
        worldDirection
      );

      if (gotHit) {
        auto actor = result.GetActor();
        if (actor != nullptr && actor->GetClass()->ImplementsInterface(URivenInteractable::StaticClass())) {
          this->DrawRect(
            kSquareColor,
            x,
            y,
            kSquareWidth,
            kSquareHeight
          );
        }
      }
    }
  }
}
