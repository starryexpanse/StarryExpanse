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

void AStarryExpanseHUD::DrawHUD() {
  float width = Canvas->ClipX;
  float height = Canvas->ClipY;

  // Draw very simple crosshair

  // find center of the Canvas
  const FVector2D Center(width * 0.5f, height * 0.5f);

  // offset by half the texture's dimensions so that the center of the texture
  // aligns with the center of the Canvas
  const FVector2D CrosshairDrawPosition((Center.X), (Center.Y + 20.0f));

  // draw the crosshair

  if (!UHeadMountedDisplayFunctionLibrary::IsHeadMountedDisplayEnabled()) {
    FCanvasTileItem TileItem(
      CrosshairDrawPosition,
      CrosshairTex->Resource,
      FLinearColor::White
    );
    TileItem.BlendMode = SE_BLEND_Translucent;
    Canvas->DrawItem(TileItem);
  }

  const float kNumXDivisions = 100.0f;
  const float kNumYDivisions = 100.0f;
  const float kSquareWidth = width / kNumXDivisions;
  const float kSquareHeight = height / kNumYDivisions;

  auto controller = Cast<AStrangerController>(this->GetOwningPlayerController());

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
