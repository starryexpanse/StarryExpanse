#include "RivenGameState.h"
#include "SaveGame/RivenSaveGame.h"
#include "Interfaces/RivenSaveGameAware.h"
#include "Engine/Engine.h"
#include "RivenGameInstance.h"
#include "StarryExpanse.h"
#include "Runtime/Core/Public/UObject/WeakObjectPtrTemplates.h"
#include "Runtime/Core/Public/GenericPlatform/GenericPlatform.h"
#include "Runtime/UMG/Public/Blueprint/WidgetBlueprintLibrary.h"
#include "Kismet/GameplayStatics.h"

#include "UObject/ConstructorHelpers.h"

ARivenGameState::ARivenGameState() : Super() {
  // static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(
  // TEXT("/Game/FirstPersonBP/Blueprints/FirstPersonCharacter"));

  CurrentMenuPage = EGameMenuPage::MainMenu;

  static ConstructorHelpers::FClassFinder<UUserWidget> WidgetClassFinder(
      TEXT("/Game/StarryExpanse/Interface/Widgets/BP_MainMenu.BP_MainMenu_C"));

  WidgetClass = WidgetClassFinder.Class;

  bListedInSceneOutliner = true;
}

void ARivenGameState::PostInitializeComponents() {
  Super::PostInitializeComponents();
  FActorSpawnParameters params;
  params.Name = FName("LoadgroupQueen");
  params.Owner = this;
  this->LoadgroupQueen = this->GetWorld()->SpawnActor<ALoadgroupActor>(
      FVector::ZeroVector, FRotator::ZeroRotator, params);
}

void ARivenGameState::SetNewCurrentSavegame(URivenSaveGame *nextSavegame) {
  if (this->Instantaneous_SaveGame) {
    this->Instantaneous_SaveGame->SetSubscriber(nullptr);
  }

  if (nextSavegame) {
    nextSavegame->SetSubscriber(this);
  }
  this->Instantaneous_SaveGame = nextSavegame;
}

void ARivenGameState::OnConstruction(const FTransform &Transform) {
  // Set savegame to just a stub, so that PIE works.
  SetNewCurrentSavegame(NewObject<URivenSaveGame>());

  // Initialize controller with main menu screen

  auto controller = UGameplayStatics::GetPlayerController(GetWorld(), 0);

  MenuWidget = UWidgetBlueprintLibrary::Create(this, WidgetClass, controller);
  check(MenuWidget);
  MenuWidget->AddToViewport(0);
  MenuWidget->SetRenderOpacity(0);

  CurrentMenuPage = EGameMenuPage::NoPage;
}

void ARivenGameState::SubscribeActorToSavegame(AActor *actor) {
  check(actor);
  if (actor->GetClass()->ImplementsInterface(
          URivenSavegameAware::StaticClass())) {
    uint32 uuid = actor->GetUniqueID();
    if (SubscribedToSavegame.Contains(uuid)) {
      checkf(false, TEXT("Actor subscribing was already subscribed"));
    } else {
      SubscribedToSavegame.Add(uuid, TWeakObjectPtr<AActor>(actor));
      IRivenSavegameAware::Execute_SavegameInitialNotify(
          actor, Instantaneous_SaveGame);
    }
  } else {
    checkf(false, TEXT("Actor subscribing does not implement "
                       "IRivenSavegameAware interface"));
  }
}

void ARivenGameState::UnsubscribeActorFromSavegame(AActor *actor) {
  check(actor);
  uint32 uuid = actor->GetUniqueID();
  SubscribedToSavegame.FindAndRemoveChecked(uuid);
}

void ARivenGameState::NotifySubscribersOfChange(URivenSaveGame *OldSaveGame) {
  TArray<uint32> IdsToRemove;
  for (auto &Elem : SubscribedToSavegame) {
    TWeakObjectPtr<AActor> subscriberPointer = Elem.Value;
    if (subscriberPointer.IsValid() &&
        subscriberPointer->GetClass()->ImplementsInterface(
            URivenSavegameAware::StaticClass())) {
      AActor *subscriber =
          subscriberPointer.Get(/* bEvenIfPendingKill = */ true);
      // NOTE(philip) not totally sure on the bEvenIfPendingKill option.

      IRivenSavegameAware::Execute_SavegameUpdateNotify(subscriber, OldSaveGame,
                                                        Instantaneous_SaveGame);
    } else {
      IdsToRemove.Add(Elem.Key);
    }
  }

  for (auto &Id : IdsToRemove) {
    SubscribedToSavegame.FindAndRemoveChecked(Id);
  }
}

void ARivenGameState::SetMenuPage(EGameMenuPage MenuPage) {
  this->CurrentMenuPage = MenuPage;
  if (MenuPage == EGameMenuPage::NoPage) {
    MenuWidget->SetRenderOpacity(0);
  } else {
    MenuWidget->SetRenderOpacity(1);
  }
  MenuStateChangedEvent.Broadcast();
}
