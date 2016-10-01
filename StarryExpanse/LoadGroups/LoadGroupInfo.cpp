#include "StarryExpanse.h"
#include "LoadGroups/LoadGroupInfo.h"
#include "Config/ELoadGroups.h"


ULoadGroupInfo::ULoadGroupInfo(const FObjectInitializer& ObjectInitializer)
   : Super(ObjectInitializer)
{

   typedef std::pair<ELoadGroups, std::set<FName>> Pair;


   LoadGroups.insert(Pair(
      ELoadGroups::BLakeArea,
      {
         TEXT("J_Basin")
      }
   ));

   // Every load group should contain A_Journals because they're always visible.
   for ( auto it = LoadGroups.begin(); it != LoadGroups.end(); it++ ) {
      it->second.insert(FName(TEXT("A_Journals")));
   }

}

bool ULoadGroupInfo::IsLevelInLoadGroup(FName level, ELoadGroups lg) {
   MapType::iterator it = LoadGroups.find(lg);
   if ( it == LoadGroups.end() ) {
      return false;
   }

   SetType map = it->second;

   SetType::iterator it2 = map.find(level);
   if ( it2 == map.end() ) {
      return false;
   }
   return true;
}
///*
//SetType ULoadGroupInfo::GetLevelsForLoadGroup(ELoadGroups lg) {
//   MapType::iterator it = LoadGroups.find(lg);
//   if ( it == LoadGroups.end() ) {
//      return SetType();
//   }
//
//   SetType map = it->second;
//   return map;
//}*/
//
//void ULoadGroupInfo::LoadGroupDifference(ELoadGroups Current, ELoadGroups Next, TArray<FName>& Unload, TArray<FName>& Load) {
//   //std::vector<FName>
//   Unload.Push(FName("Foo"));
//
//   //std::vector<FName> v;
//
//   //auto it = std::set_difference(Current, Next, Current:end, Next:end,v.begin());
//}
