#include "StarryExpanse.h"
#include "Engine/Canvas.h"
#include "TextureResource.h"
#include "CanvasItem.h"
#include "Base/Character/SECharacter.h"
#include "SEHUD.h"

ASEHUD::ASEHUD()
{
	// Set the crosshair texture
	static ConstructorHelpers::FObjectFinder<UTexture2D> CursorTextureFinder(TEXT("/Game/A/UI/Cursors/T_CursorPick_D.T_CursorPick_D"));
	CursorTexture.Texture = CursorTextureFinder.Object;
	CursorTexture.HotSpot = FVector2D(4.f, 15.f);
	CursorOpacity = 1.f;
}

void ASEHUD::DrawHUD()
{
	Super::DrawHUD();

	/*
	if (IsValid(CursorTexture.Texture))
	{
		// Find center of the Canvas
		const FVector2D Center(Canvas->ClipX * 0.5f, Canvas->ClipY * 0.5f);

		auto Character = CastChecked<ASECharacter>(GetOwningPawn());
		auto aspect = Character->GetCameraComponent()->AspectRatio;
		auto MousePosition = FVector2D::ZeroVector;
		if (!GetOwningPlayerController()->GetMousePosition(MousePosition.X, MousePosition.Y))
			MousePosition = Center;

		// This is a hardcoded hack to use when the passepartout effect is active (for now, it's unused by default)
		auto CursorOffset = FVector2D(0.f, 0.f); //FVector2D(-2.f , -50.f);

		// Offset by half the texture's dimensions so that the center of the texture aligns with the actual mouse cursor
		const FVector2D CrosshairDrawPosition(
			(MousePosition.X - (CursorTexture.Texture->GetSurfaceWidth() * 0.5) + CursorOffset.X) + CursorTexture.HotSpot.X,
			(MousePosition.Y - (CursorTexture.Texture->GetSurfaceHeight() * 0.5f) + CursorOffset.Y) + CursorTexture.HotSpot.Y
		);

		// Draw the cursor
		FCanvasTileItem TileItem(CrosshairDrawPosition, CursorTexture.Texture->Resource, FLinearColor::White);
		TileItem.BlendMode = SE_BLEND_Translucent;
		TileItem.SetColor(FLinearColor::FromSRGBColor(FColor::White.WithAlpha(uint8(CursorOpacity * float(255)))));
		Canvas->DrawItem(TileItem);
	}
	*/
}

UTexture2D *ASEHUD::GetCursorTexture() {
	return CursorTexture.Texture;
}

void ASEHUD::SetCursorTexture(UTexture2D *Texture)
{
	CursorTexture.Texture = Texture;
}

void ASEHUD::SetCursorOpacity(float Opacity) {
	CursorOpacity = FMath::Clamp<float>(Opacity, 0.f, 1.f);
}
