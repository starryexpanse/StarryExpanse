#include "RivenGameState.h"
#include "SaveGame/RivenSaveGame.h"
#include "Interfaces/RivenSaveGameAware.h"
#include "Engine/Engine.h"
#include "Kismet/GameplayStatics.h"
#include "RivenGameInstance.h"
#include "StarryExpanse.h"
#include "Runtime/Core/Public/UObject/WeakObjectPtrTemplates.h"
#include "Runtime/Core/Public/GenericPlatform/GenericPlatform.h"
#include "UObject/ConstructorHelpers.h"

ARivenGameState::ARivenGameState() : Super() {}

void ARivenGameState::OnConstruction(const FTransform &Transform) {
  auto initialSavegame = NewObject<URivenSaveGame>();
  initialSavegame->SetSubscriber(this);
  this->Instantaneous_SaveGame = initialSavegame;
  auto gameInstance = GetWorld()->GetGameInstance<URivenGameInstance>();
  gameInstance->Last_Savable_SaveGame = initialSavegame;
}

void ARivenGameState::SubscribeActorToSavegame(AActor* actor) {
  check(actor);
  if (actor->GetClass()->ImplementsInterface(URivenSavegameAware::StaticClass())) {
    uint32 uuid = actor->GetUniqueID();
    SubscribedToSavegame.Add(uuid, TWeakObjectPtr<AActor>(actor));
  }
}

void ARivenGameState::UnsubscribeActorFromSavegame(AActor* actor) {
  check(actor);
  uint32 uuid = actor->GetUniqueID();
  SubscribedToSavegame.FindAndRemoveChecked(uuid);
}

void ARivenGameState::NotifySubscribersOfChange(URivenSaveGame *OldSaveGame) {
  TArray<uint32> IdsToRemove;
  for (auto& Elem : SubscribedToSavegame) {
    TWeakObjectPtr<AActor> subscriberPointer = Elem.Value;
    if (
      subscriberPointer.IsValid() &&
      subscriberPointer->GetClass()->ImplementsInterface(URivenSavegameAware::StaticClass())
    ) {
      AActor* subscriber = subscriberPointer.Get(/* bEvenIfPendingKill = */ true);
      // NOTE(philip) not totally sure on the bEvenIfPendingKill option.

      IRivenSavegameAware::Execute_SavegameUpdateNotify(subscriber, OldSaveGame, Instantaneous_SaveGame);
    } else {
      IdsToRemove.Add(Elem.Key);
    }
  }

  for (auto& Id : IdsToRemove) {
    SubscribedToSavegame.FindAndRemoveChecked(Id);
  }
}
