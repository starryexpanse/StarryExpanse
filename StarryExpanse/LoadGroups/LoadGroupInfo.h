#pragma once

#include <iterator>
#include <map>
#include <set>
#include <vector>

#include "ELoadGroups.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "LoadGroupInfo.generated.h"

typedef std::set<FName> SetType;

struct LoadgroupInfoEntry {
  SetType Levels;
  FString Name;

  LoadgroupInfoEntry(FString Name, SetType Levels) {
    this->Levels = Levels;
    this->Name = Name;
  }
};

typedef std::map<ELoadGroups, LoadgroupInfoEntry> MapType;

static MapType LoadGroups;

UCLASS()
class STARRYEXPANSE_API ULoadGroupInfo : public UBlueprintFunctionLibrary {
  GENERATED_UCLASS_BODY()

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = "Load Groups")
  static bool IsLevelInLoadGroup(FName level, ELoadGroups lg);

  UFUNCTION(BlueprintPure, BlueprintCallable, Category = "Load Groups")
  static TArray<FString> GetLoadgroupNamesStartingWith(FString prefix);

  static SetType GetLevelsInLoadGroup(ELoadGroups lg);
  static SetType GetLevelsToBeUnloaded(ELoadGroups lgCurrent,
                                       ELoadGroups lgNext);
  static SetType GetLevelsToBeLoaded(ELoadGroups currentSet,
                                     ELoadGroups futureSet);

  // UFUNCTION(BlueprintPure, BlueprintCallable, Category = "Load Groups")
  ///   static void LoadGroupDifference(ELoadGroups Current, ELoadGroups Next,
  ///   TArray<FName>& Unload, TArray<FName>& Load);
};
