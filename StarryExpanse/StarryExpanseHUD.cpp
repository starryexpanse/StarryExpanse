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

  int numDivisions = 50;
  float squareSize = std::min(width / numDivisions, height / numDivisions);

  auto controller = Cast<AStrangerController>(this->GetOwningPlayerController());

  bool gotHit, hadError;
  FHitResult result;

  for (int i = 0; i < numDivisions; i++) {
    for (int j = 0; j < numDivisions; j++) {
      result = controller->CastInteractionRay(
        gotHit,
        hadError,
        i / float(numDivisions) * 2 - 1,
        - (j / float(numDivisions) * 2 - 1)
      );

      if (gotHit) {
        auto actor = result.GetActor();
        if (actor->GetClass()->ImplementsInterface(URivenInteractable::StaticClass())) {
          this->DrawRect(
            FLinearColor(1.0f, 1.0f, 0.0f, 0.3f),
            width * i / numDivisions,
            height * j / numDivisions,
            squareSize,
            squareSize
          );
        }
      }
    }
  }
}
