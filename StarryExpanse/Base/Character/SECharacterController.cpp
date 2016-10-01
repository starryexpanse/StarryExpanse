#include "StarryExpanse.h"
#include "SECharacterEventStates.h"
#include "SECharacterState.h"
#include "SECharacterController.h"

ASECharacterController::ASECharacterController() : Super()
{
}

void ASECharacterController::BeginPlay()
{
	Super::BeginPlay();

	FSlateApplication::Get().SetUserFocusToGameViewport(0);
}

void ASECharacterController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (auto PS = CastChecked<ASECharacterState>(PlayerState))
	{
		auto LocalPlayer = CastChecked<ULocalPlayer>(this->Player);
		auto ViewportClient = LocalPlayer->ViewportClient;
		FViewport* Viewport = ViewportClient->Viewport;
		FVector2D ViewportSize;

		switch (PS->CursorState)
		{
		case ECharacterCursorState::Free:
			Viewport->LockMouseToViewport(true);
			Viewport->CaptureMouse(false);
			break;
		case ECharacterCursorState::Locked:
			Viewport->LockMouseToViewport(true);
			Viewport->CaptureMouse(true);
			ViewportClient->GetViewportSize(ViewportSize);
			const int32 X = static_cast<int32>(ViewportSize.X * 0.5f);
			const int32 Y = static_cast<int32>(ViewportSize.Y * 0.5f);

			Viewport->SetMouse(X, Y);
			break;
		}
	}
}