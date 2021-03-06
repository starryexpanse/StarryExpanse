// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

// Logs
DECLARE_LOG_CATEGORY_EXTERN(StarryDebug, Log, All);

#define STARRY_CRITICAL(msg, ...)                                              \
  UE_LOG(StarryDebug, Error, TEXT(msg), ##__VA_ARGS__)
#define STARRY_WARNING(msg, ...)                                               \
  UE_LOG(StarryDebug, Warning, TEXT(msg), ##__VA_ARGS__)
