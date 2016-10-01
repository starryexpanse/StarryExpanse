#include "StarryExpanse.h"
#include "SEMouseVolumeComponent.h"

USEMouseVolumeComponent::USEMouseVolumeComponent() : Super()
{
   OnBeginCursorOver.AddUniqueDynamic(this, &USEMouseVolumeComponent::OnBeginCursorOver_Callback);
   OnEndCursorOver.AddUniqueDynamic(this, &USEMouseVolumeComponent::OnEndCursorOver_Callback);
}

void USEMouseVolumeComponent::OnBeginCursorOver_Callback(UPrimitiveComponent *TouchedComponent)
{
   bHasCursorOver = true;
   GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Cyan, TEXT("Volume Begin Hover"));
}

void USEMouseVolumeComponent::OnEndCursorOver_Callback(UPrimitiveComponent *TouchedComponent)
{
   bHasCursorOver = false;
   GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Cyan, TEXT("Volume End Hover"));
}
