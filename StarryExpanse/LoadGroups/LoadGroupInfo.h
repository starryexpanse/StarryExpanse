#pragma once

#include <map>
#include <set>
#include <iterator>
#include <vector>

#include "Kismet/BlueprintFunctionLibrary.h"
#include "Config/ELoadGroups.h"
#include "LoadGroupInfo.generated.h"

typedef std::set<FName> SetType;
typedef std::map<ELoadGroups, SetType> MapType;

static MapType LoadGroups;

UCLASS()
class STARRYEXPANSE_API ULoadGroupInfo : public UBlueprintFunctionLibrary
{
   GENERATED_UCLASS_BODY()

   UFUNCTION(BlueprintPure, BlueprintCallable, Category = "Load Groups")
   static bool IsLevelInLoadGroup(FName level, ELoadGroups lg);

   //UFUNCTION(BlueprintPure, BlueprintCallable, Category = "Load Groups")
   ///   static void LoadGroupDifference(ELoadGroups Current, ELoadGroups Next, TArray<FName>& Unload, TArray<FName>& Load);

};
