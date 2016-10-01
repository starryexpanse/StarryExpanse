#include "StarryExpanse.h"
#include "SECharacterEventStates.h"
#include "SECharacterState.h"
#include "SECharacterController.h"

ASECharacterController::ASECharacterController() : Super()
{
   #if WITH_EDITOR
       this->bShowMouseCursor = true;
    #else
       this->bShowMouseCursor = false;
    #endif
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
      case ECharacterCursorState::Uncontrolled:
         this->bShowMouseCursor = true;
         Viewport->LockMouseToViewport(false);
         Viewport->CaptureMouse(false);
         break;
      case ECharacterCursorState::Free:
          this->bShowMouseCursor = false;
         Viewport->LockMouseToViewport(true);
         Viewport->CaptureMouse(false);
         break;
      case ECharacterCursorState::Locked:
          this->bShowMouseCursor = false;
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
