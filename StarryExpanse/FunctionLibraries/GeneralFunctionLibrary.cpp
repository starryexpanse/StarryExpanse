// Copyright, 59 Volt Entertainment, all rights reserved.

#include "GeneralFunctionLibrary.h"
#include "Runtime/Core/Public/Misc/ConfigCacheIni.h"

FVector UGeneralFunctionLibrary::GetInitialSpawnPosition() {
  FConfigFile config;
  FConfigCacheIni::LoadLocalIniFile(config, TEXT("StarryExpanse"), false,
                                    nullptr, true);

  auto initialSpawn = config.Find("InitialSpawn");

  float x = 0;
  float y = 0;
  float z = 0;

  if (initialSpawn) {
    auto xUnchecked = initialSpawn->Find("LocationX");
    auto yUnchecked = initialSpawn->Find("LocationY");
    auto zUnchecked = initialSpawn->Find("LocationZ");
    x = xUnchecked ? FCString::Atof(*xUnchecked->GetValue()) : 0;
    y = yUnchecked ? FCString::Atof(*yUnchecked->GetValue()) : 0;
    z = zUnchecked ? FCString::Atof(*zUnchecked->GetValue()) : 0;
  }

  return FVector(x, y, z);
}

bool UGeneralFunctionLibrary::GetShouldPlayMusic() {
  FConfigFile config;
  FConfigCacheIni::LoadLocalIniFile(config, TEXT("StarryExpanse"), false,
                                    nullptr, true);

  auto entry = config.Find("Music");
  auto valueUnchecked = entry->Find("ShouldPlay");
  bool value =
      valueUnchecked ? valueUnchecked->GetValue().ToLower() != "false" : true;

  return value;
}

bool UGeneralFunctionLibrary::GetIsVrGame() {
  FConfigFile config;
  FConfigCacheIni::LoadLocalIniFile(config, TEXT("StarryExpanse"), false,
                                    nullptr, true);

  auto entry = config.Find("Game");
  auto valueUnchecked = entry->Find("IsVrGame");
  bool value =
      valueUnchecked ? valueUnchecked->GetValue().ToLower() == "true" : false;

  return value;
}

bool UGeneralFunctionLibrary::GetIsVrTeleportGame() {
  if (!GetIsVrGame()) {
    return false;
  }

  FConfigFile config;
  FConfigCacheIni::LoadLocalIniFile(config, TEXT("StarryExpanse"), false,
                                    nullptr, true);

  auto entry = config.Find("Game");
  auto valueUnchecked = entry->Find("IsUsingTeleport");
  bool value =
      valueUnchecked ? valueUnchecked->GetValue().ToLower() == "true" : false;

  return value;
}