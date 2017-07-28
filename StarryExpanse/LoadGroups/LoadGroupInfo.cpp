#include "LoadGroups/LoadGroupInfo.h"
#include "StarryExpanse.h"
#include "ELoadGroups.h"


ULoadGroupInfo::ULoadGroupInfo(const FObjectInitializer& ObjectInitializer)
   : Super(ObjectInitializer)
{

   typedef std::pair<ELoadGroups, std::set<FName>> Pair;

   LoadGroups.insert(Pair(
       ELoadGroups::AAbsoluteZero,
       {
       }
   ));

   /*
   [[[cog
   import cog
   import os
   from io import open
   import sys
   from yaml import load, dump, Loader, Dumper

   stream = open('LoadGroups/LgConfig.yaml', 'r')
   data = load(stream, Loader=Loader)

   def flatten(l):
      accum = []
      for item in l:
         if type(item) == list:
            accum = accum + flatten(item)
         else:
            accum.append(item)
      return accum

   for loadgroup, sublevels in data.items():
      sublevels = flatten(sublevels)
      cog.outl('LoadGroups.insert(Pair(')
      cog.outl('    ELoadGroups::%s,' % loadgroup)
      cog.outl('    {')
      for i, sublevel in enumerate(sublevels):
         is_last = i == len(sublevels) - 1
         comma = ',' if not is_last else ''
         cog.outl('        TEXT("%s")%s' % (sublevel, comma))
      cog.outl('    }')
      cog.outl('));')
      cog.outl('')
   ]]] */
   LoadGroups.insert(Pair(
       ELoadGroups::AGeneral,
       {
           TEXT("A_Journals")
       }
   ));

   LoadGroups.insert(Pair(
       ELoadGroups::SRivenBase,
       {
           TEXT("S_Lighting_Riven"),
           TEXT("S_PostProcessing_Riven"),
           TEXT("S_Ocean_Riven")
       }
   ));

   LoadGroups.insert(Pair(
       ELoadGroups::BCartTrackAboveWater,
       {
       }
   ));

   LoadGroups.insert(Pair(
       ELoadGroups::BCartCave,
       {
       }
   ));

   LoadGroups.insert(Pair(
       ELoadGroups::BTerrainOuter,
       {
       }
   ));

   LoadGroups.insert(Pair(
       ELoadGroups::BDomePipe,
       {
       }
   ));

   LoadGroups.insert(Pair(
       ELoadGroups::BTerrainInner,
       {
       }
   ));

   LoadGroups.insert(Pair(
       ELoadGroups::BLakeArea,
       {
       }
   ));

   LoadGroups.insert(Pair(
       ELoadGroups::BBoilerOutlet,
       {
       }
   ));

   LoadGroups.insert(Pair(
       ELoadGroups::BTerrainPath,
       {
       }
   ));

   LoadGroups.insert(Pair(
       ELoadGroups::BYtramCave,
       {
       }
   ));

   LoadGroups.insert(Pair(
       ELoadGroups::BFiremarbleCave,
       {
       }
   ));

   LoadGroups.insert(Pair(
       ELoadGroups::BBridgeCave,
       {
       }
   ));

   LoadGroups.insert(Pair(
       ELoadGroups::BYtramDuct,
       {
       }
   ));

   LoadGroups.insert(Pair(
       ELoadGroups::BOfficeExterior,
       {
       }
   ));

   LoadGroups.insert(Pair(
       ELoadGroups::BOfficeInterior,
       {
       }
   ));

   LoadGroups.insert(Pair(
       ELoadGroups::BMagLevDock,
       {
       }
   ));

   LoadGroups.insert(Pair(
       ELoadGroups::BBase,
       {
           TEXT("A_Journals"),
           TEXT("S_Lighting_Riven"),
           TEXT("S_PostProcessing_Riven"),
           TEXT("S_Ocean_Riven"),
           TEXT("B_Terrain")
       }
   ));

   LoadGroups.insert(Pair(
       ELoadGroups::BEastSide,
       {
           TEXT("A_Journals"),
           TEXT("S_Lighting_Riven"),
           TEXT("S_PostProcessing_Riven"),
           TEXT("S_Ocean_Riven"),
           TEXT("B_Terrain"),
           TEXT("S_GreatBridge"),
           TEXT("B_MiniLakeTunnel"),
           TEXT("T_SuperDome")
       }
   ));

   LoadGroups.insert(Pair(
       ELoadGroups::GBase,
       {
           TEXT("A_Journals"),
           TEXT("S_Lighting_Riven"),
           TEXT("S_PostProcessing_Riven"),
           TEXT("S_Ocean_Riven")
       }
   ));

   LoadGroups.insert(Pair(
       ELoadGroups::GUpsideBase,
       {
           TEXT("G_Terrain"),
           TEXT("G_WahrkTankUpper"),
           TEXT("G_BubbleGarden"),
           TEXT("G_Connector")
       }
   ));

   LoadGroups.insert(Pair(
       ELoadGroups::GUpsideExterior,
       {
           TEXT("A_Journals"),
           TEXT("S_Lighting_Riven"),
           TEXT("S_PostProcessing_Riven"),
           TEXT("S_Ocean_Riven"),
           TEXT("G_Terrain"),
           TEXT("G_WahrkTankUpper"),
           TEXT("G_BubbleGarden"),
           TEXT("G_Connector"),
           TEXT("G_SpikeGarden")
       }
   ));

   LoadGroups.insert(Pair(
       ELoadGroups::GUpsideInterior,
       {
           TEXT("A_Journals"),
           TEXT("S_Lighting_Riven"),
           TEXT("S_PostProcessing_Riven"),
           TEXT("S_Ocean_Riven"),
           TEXT("G_Terrain"),
           TEXT("G_WahrkTankUpper"),
           TEXT("G_BubbleGarden"),
           TEXT("G_Connector"),
           TEXT("G_MaglevDock_B")
       }
   ));

   LoadGroups.insert(Pair(
       ELoadGroups::GDownside,
       {
           TEXT("A_Journals"),
           TEXT("S_Lighting_Riven"),
           TEXT("S_PostProcessing_Riven"),
           TEXT("S_Ocean_Riven"),
           TEXT("G_MaglevDock_J"),
           TEXT("G_WahrkTankLower")
       }
   ));

   LoadGroups.insert(Pair(
       ELoadGroups::TBase,
       {
           TEXT("A_Journals"),
           TEXT("S_Lighting_Riven"),
           TEXT("S_PostProcessing_Riven"),
           TEXT("S_Ocean_Riven"),
           TEXT("T_Terrain")
       }
   ));

   LoadGroups.insert(Pair(
       ELoadGroups::TWestSide,
       {
           TEXT("A_Journals"),
           TEXT("S_Lighting_Riven"),
           TEXT("S_PostProcessing_Riven"),
           TEXT("S_Ocean_Riven"),
           TEXT("T_Terrain"),
           TEXT("S_GreatBridge"),
           TEXT("T_SuperDome"),
           TEXT("T_GateRoom")
       }
   ));

   LoadGroups.insert(Pair(
       ELoadGroups::TNorthSide,
       {
           TEXT("A_Journals"),
           TEXT("S_Lighting_Riven"),
           TEXT("S_PostProcessing_Riven"),
           TEXT("S_Ocean_Riven"),
           TEXT("T_Terrain"),
           TEXT("S_GreatBridge"),
           TEXT("T_Backstage"),
           TEXT("T_GateRoom"),
           TEXT("T_SuperDome")
       }
   ));

   LoadGroups.insert(Pair(
       ELoadGroups::TFissureDistrict,
       {
           TEXT("A_Journals"),
           TEXT("S_Lighting_Riven"),
           TEXT("S_PostProcessing_Riven"),
           TEXT("S_Ocean_Riven"),
           TEXT("T_Terrain"),
           TEXT("T_Backstage"),
           TEXT("T_GateRoom"),
           TEXT("T_Plateaus"),
           TEXT("T_NewTempleArea"),
           TEXT("T_SuperDome")
       }
   ));

   LoadGroups.insert(Pair(
       ELoadGroups::TSpiderTunnelDistrict,
       {
           TEXT("A_Journals"),
           TEXT("S_Lighting_Riven"),
           TEXT("S_PostProcessing_Riven"),
           TEXT("S_Ocean_Riven"),
           TEXT("T_Terrain"),
           TEXT("T_GateRoom"),
           TEXT("T_Plateaus"),
           TEXT("T_NewTempleArea"),
           TEXT("S_Maglev_TJ"),
           TEXT("T_SuperDome")
       }
   ));

   // [[[end]]]
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

SetType ULoadGroupInfo::GetLevelsInLoadGroup(ELoadGroups lg) {
   MapType::iterator it = LoadGroups.find(lg);
   if ( it == LoadGroups.end() ) {
      return SetType();
   }

   SetType levels = it->second;
   return levels;
}


SetType ULoadGroupInfo::GetLevelsToBeUnloaded(ELoadGroups lgCurrent, ELoadGroups lgNext) {
  auto currentSet = ULoadGroupInfo::GetLevelsInLoadGroup(lgCurrent);
  auto nextSet = ULoadGroupInfo::GetLevelsInLoadGroup(lgNext);
  SetType unloadingSet;
  for (const auto& levelName : currentSet) {
    if (nextSet.count(levelName) == 0) {
      unloadingSet.insert(levelName);
    }
  }
  return unloadingSet;
}


SetType ULoadGroupInfo::GetLevelsToBeLoaded(ELoadGroups lgCurrent, ELoadGroups lgNext) {
  auto currentSet = ULoadGroupInfo::GetLevelsInLoadGroup(lgCurrent);
  auto nextSet = ULoadGroupInfo::GetLevelsInLoadGroup(lgNext);
  SetType loadingSet;
  for (const auto& levelName : nextSet) {
    if (currentSet.count(levelName) == 0) {
      loadingSet.insert(levelName);
    }
  }
  return loadingSet;
}

//
//void ULoadGroupInfo::LoadGroupDifference(ELoadGroups Current, ELoadGroups Next, TArray<FName>& Unload, TArray<FName>& Load) {
//   //std::vector<FName>
//   Unload.Push(FName("Foo"));
//
//   //std::vector<FName> v;
//
//   //auto it = std::set_difference(Current, Next, Current:end, Next:end,v.begin());
//}
