#include "StarryExpanse.h"
#include "EverpresentLoadGroupManager.h"

/* Class constructor */
AEverpresentLoadGroupManager::AEverpresentLoadGroupManager() : Super()
{

}

/*
void AEverpresentLoadGroupManager::InferLoadedLevels() {
    const TArray<ULevelStreaming*>& StreamedLevels = GetWorld()->StreamingLevels;

    for(const ULevelStreaming* EachLevelStreaming : StreamedLevels)
    {
        if( !EachLevelStreaming)
        {
            continue;
        }

        ULevel* EachLevel =  EachLevelStreaming->GetLoadedLevel();

        // Is This Level Valid and Visible?
        if( !EachLevel || !EachLevel->bIsVisible)
        {
            continue;
        }

        //Print Name of current Level Streaming to know which level the unit is in!
        ClientMessage( EachLevelStreaming->GetWorldAssetPackageName() );
    }
}
*/

void AEverpresentLoadGroupManager::NotifyOfOverlapBegin()
{

}

void AEverpresentLoadGroupManager::NotifyOfOverlapEnd()
{

}

void AEverpresentLoadGroupManager::LoadLoadGroup(ELoadGroups LoadGroup) {
    auto world = GetWorld();


    /*
    UGameplayStatics::UnloadStreamLevel(
        world,
        FName LevelName,
        FLatentActionInfo LatentInfo
    );

    UGameplayStatics::LoadStreamLevel(
        world,
        FName LevelName,
        bool bMakeVisibleAfterLoad,
        bool bShouldBlockOnLoad,
        FLatentActionInfo LatentInfo
    );
    */
}

