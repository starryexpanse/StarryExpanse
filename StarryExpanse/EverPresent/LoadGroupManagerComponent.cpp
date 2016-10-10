#include "StarryExpanse.h"
#include "LoadGroupManagerComponent.h"

/* Class constructor */
ULoadGroupManagerComponent::ULoadGroupManagerComponent() : Super()
{

}

void ULoadGroupManagerComponent::LevelLoaded() {
    UE_LOG(StarryDebug,Warning,TEXT("I loaded it!"));
}

void ULoadGroupManagerComponent::LoadLoadGroup() {
    UE_LOG(StarryDebug,Warning,TEXT("About to load..."));
    FLatentActionInfo LatentInfo;
    LatentInfo.Linkage = 0;
    LatentInfo.CallbackTarget = this;
    LatentInfo.ExecutionFunction = FName("LevelLoaded");

    UGameplayStatics::LoadStreamLevel(this, FName("S_BubbleGarden"), true, false, LatentInfo);
}
