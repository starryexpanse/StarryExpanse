#include "Logging.h"
#include "StarryExpanse.h"

ULogging::ULogging(const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer) {
}

void ULogging::LogWarning(FString text) {
  STARRY_WARNING("%s", *text)
}

void ULogging::LogCritical(FString text) {
  STARRY_CRITICAL("%s", *text)
}
