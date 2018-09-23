#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/GameStateBase.h"
#include "Interfaces/RivenSavegameAware.h"
#include "Enums/EGameMenuPage.h"
#include "Runtime/Core/Public/UObject/WeakObjectPtrTemplates.h"
#include "Runtime/Core/Public/GenericPlatform/GenericPlatform.h"

#include "Runtime/UMG/Public/UMG.h"
#include "Runtime/UMG/Public/UMGStyle.h"
#include "Runtime/UMG/Public/Slate/SObjectWidget.h"
#include "Runtime/UMG/Public/IUMGModule.h"
#include "Runtime/UMG/Public/Blueprint/UserWidget.h"

#include "RivenGameState.generated.h"

class URivenSaveGame;

UCLASS()
class ARivenGameState : public AGameStateBase {
  GENERATED_BODY()

public:
  ARivenGameState();

  void OnConstruction(const FTransform &Transform) override;

  DECLARE_DYNAMIC_MULTICAST_DELEGATE(FMenuStateChangedEvent);

  FMenuStateChangedEvent MenuStateChangedEvent;

  UPROPERTY(BlueprintReadOnly)
  EGameMenuPage CurrentMenuPage;

  UPROPERTY(BlueprintReadOnly)
  URivenSaveGame *Instantaneous_SaveGame;

  UPROPERTY()
  TMap<uint32, TWeakObjectPtr<AActor>> SubscribedToSavegame;

  UPROPERTY()
  UUserWidget *MenuWidget;

  TSubclassOf<UUserWidget> WidgetClass;

  UFUNCTION()
  void NotifySubscribersOfChange(URivenSaveGame *OldSaveGame);

  UFUNCTION(BlueprintCallable)
  void SetMenuPage(EGameMenuPage MenuPage);

  UFUNCTION(BlueprintCallable)
  void SubscribeActorToSavegame(AActor *Actor);

  UFUNCTION(BlueprintCallable)
  void UnsubscribeActorFromSavegame(AActor *Actor);

  // Developer flags

  UPROPERTY(BlueprintReadOnly)
  bool IsShowingDebugHitScreenOverlay = false;
};
