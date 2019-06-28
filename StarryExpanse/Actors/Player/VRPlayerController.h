#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "VRPlayerController.generated.h"

/**
 *
 */
UCLASS()
class STARRYEXPANSE_API AVRPlayerController : public APlayerController {
  GENERATED_BODY()
public:
  AVRPlayerController();

protected:
  virtual void BeginPlayingState() override;

  virtual void SetupInputComponent() override;
};
