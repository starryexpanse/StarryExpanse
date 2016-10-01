#pragma once

#include "GameFramework/PlayerController.h"
#include "SECharacterController.generated.h"

/* Class Declaration */
UCLASS(Config = Game)
class STARRYEXPANSE_API ASECharacterController : public APlayerController
{
   GENERATED_BODY()

public:
   /* Class Contructor */
   ASECharacterController();

   /* Public Overrides */
   virtual void BeginPlay() override;
   virtual void Tick(float DeltaSeconds) override;
};
