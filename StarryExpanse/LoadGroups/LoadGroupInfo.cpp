#include "LoadGroups/LoadGroupInfo.h"
#include "ELoadGroups.h"
#include "StarryExpanse.h"

ULoadGroupInfo::ULoadGroupInfo(const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer) {

  typedef std::pair<ELoadGroups, std::set<FName>> Pair;

  LoadGroups.insert(Pair(ELoadGroups::AAbsoluteZero, {}));

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
      ELoadGroups::MysteriumShowOff,
      {
          TEXT("G_BubbleGarden"),
          TEXT("G_Terrain"),
          TEXT("G_SpikeGarden")
      }
  ));

  LoadGroups.insert(Pair(
      ELoadGroups::AGeneral,
      {
          TEXT("A_Journals"),
          TEXT("G_BubbleGarden"),
          TEXT("G_Terrain"),
          TEXT("G_SpikeGarden")
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
      ELoadGroups::BBase,
      {
          TEXT("A_Journals"),
          TEXT("G_BubbleGarden"),
          TEXT("G_Terrain"),
          TEXT("G_SpikeGarden"),
          TEXT("S_Lighting_Riven"),
          TEXT("S_PostProcessing_Riven"),
          TEXT("S_Ocean_Riven"),
          TEXT("B_Terrain_Structures")
      }
  ));

  LoadGroups.insert(Pair(
      ELoadGroups::BEastSide,
      {
          TEXT("A_Journals"),
          TEXT("G_BubbleGarden"),
          TEXT("G_Terrain"),
          TEXT("G_SpikeGarden"),
          TEXT("S_Lighting_Riven"),
          TEXT("S_PostProcessing_Riven"),
          TEXT("S_Ocean_Riven"),
          TEXT("B_Terrain_Structures"),
          TEXT("S_GreatBridge"),
          TEXT("T_SuperDome"),
          TEXT("T_Terrain"),
          TEXT("B_UpperWalkwayTunnel"),
          TEXT("B_CartTrack_Structures"),
          TEXT("B_GehnLab")
      }
  ));

  LoadGroups.insert(Pair(
      ELoadGroups::GBase,
      {
          TEXT("A_Journals"),
          TEXT("G_BubbleGarden"),
          TEXT("G_Terrain"),
          TEXT("G_SpikeGarden"),
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
          TEXT("G_BubbleGarden"),
          TEXT("G_Terrain"),
          TEXT("G_SpikeGarden"),
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
          TEXT("G_BubbleGarden"),
          TEXT("G_Terrain"),
          TEXT("G_SpikeGarden"),
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
          TEXT("G_BubbleGarden"),
          TEXT("G_Terrain"),
          TEXT("G_SpikeGarden"),
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
          TEXT("G_BubbleGarden"),
          TEXT("G_Terrain"),
          TEXT("G_SpikeGarden"),
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
          TEXT("G_BubbleGarden"),
          TEXT("G_Terrain"),
          TEXT("G_SpikeGarden"),
          TEXT("S_Lighting_Riven"),
          TEXT("S_PostProcessing_Riven"),
          TEXT("S_Ocean_Riven"),
          TEXT("T_Terrain"),
          TEXT("B_CartTrack_Structures"),
          TEXT("B_Terrain_Structures"),
          TEXT("S_GreatBridge"),
          TEXT("T_SuperDome"),
          TEXT("T_GateRoom")
      }
  ));

  LoadGroups.insert(Pair(
      ELoadGroups::TNorthSide,
      {
          TEXT("A_Journals"),
          TEXT("G_BubbleGarden"),
          TEXT("G_Terrain"),
          TEXT("G_SpikeGarden"),
          TEXT("S_Lighting_Riven"),
          TEXT("S_PostProcessing_Riven"),
          TEXT("S_Ocean_Riven"),
          TEXT("T_Terrain"),
          TEXT("B_CartTrack_Structures"),
          TEXT("B_Terrain_Structures"),
          TEXT("S_GreatBridge"),
          TEXT("T_GateRoom"),
          TEXT("T_SuperDome")
      }
  ));

  LoadGroups.insert(Pair(
      ELoadGroups::TFissureDistrict,
      {
          TEXT("A_Journals"),
          TEXT("G_BubbleGarden"),
          TEXT("G_Terrain"),
          TEXT("G_SpikeGarden"),
          TEXT("S_Lighting_Riven"),
          TEXT("S_PostProcessing_Riven"),
          TEXT("S_Ocean_Riven"),
          TEXT("T_Terrain"),
          TEXT("T_GateRoom"),
          TEXT("T_Plateaus"),
          TEXT("T_NewTemple"),
          TEXT("T_SuperDome")
      }
  ));

  LoadGroups.insert(Pair(
      ELoadGroups::TSpiderTunnelDistrict,
      {
          TEXT("A_Journals"),
          TEXT("G_BubbleGarden"),
          TEXT("G_Terrain"),
          TEXT("G_SpikeGarden"),
          TEXT("S_Lighting_Riven"),
          TEXT("S_PostProcessing_Riven"),
          TEXT("S_Ocean_Riven"),
          TEXT("T_Terrain"),
          TEXT("T_GateRoom"),
          TEXT("T_Plateaus"),
          TEXT("T_SpiderChairRoomInterior"),
          TEXT("T_NewTemple"),
          TEXT("S_Maglev_TJ"),
          TEXT("T_SuperDome")
      }
  ));

  LoadGroups.insert(Pair(
      ELoadGroups::TMaglevDistrict,
      {
          TEXT("A_Journals"),
          TEXT("G_BubbleGarden"),
          TEXT("G_Terrain"),
          TEXT("G_SpikeGarden"),
          TEXT("S_Lighting_Riven"),
          TEXT("S_PostProcessing_Riven"),
          TEXT("S_Ocean_Riven"),
          TEXT("T_Terrain"),
          TEXT("B_CartTrack_Structures"),
          TEXT("B_Terrain_Structures"),
          TEXT("S_Maglev_TJ")
      }
  ));

  // [[[end]]]
}

bool ULoadGroupInfo::IsLevelInLoadGroup(FName level, ELoadGroups lg) {
  MapType::iterator it = LoadGroups.find(lg);
  if (it == LoadGroups.end()) {
    return false;
  }

  SetType map = it->second;

  SetType::iterator it2 = map.find(level);
  if (it2 == map.end()) {
    return false;
  }
  return true;
}

SetType ULoadGroupInfo::GetLevelsInLoadGroup(ELoadGroups lg) {
  MapType::iterator it = LoadGroups.find(lg);
  if (it == LoadGroups.end()) {
    return SetType();
  }

  SetType levels = it->second;
  return levels;
}

SetType ULoadGroupInfo::GetLevelsToBeUnloaded(ELoadGroups lgCurrent,
                                              ELoadGroups lgNext) {
  auto currentSet = ULoadGroupInfo::GetLevelsInLoadGroup(lgCurrent);
  auto nextSet = ULoadGroupInfo::GetLevelsInLoadGroup(lgNext);
  SetType unloadingSet;
  for (const auto &levelName : currentSet) {
    if (nextSet.count(levelName) == 0) {
      unloadingSet.insert(levelName);
    }
  }
  return unloadingSet;
}

SetType ULoadGroupInfo::GetLevelsToBeLoaded(ELoadGroups lgCurrent,
                                            ELoadGroups lgNext) {
  auto currentSet = ULoadGroupInfo::GetLevelsInLoadGroup(lgCurrent);
  auto nextSet = ULoadGroupInfo::GetLevelsInLoadGroup(lgNext);
  SetType loadingSet;
  for (const auto &levelName : nextSet) {
    if (currentSet.count(levelName) == 0) {
      loadingSet.insert(levelName);
    }
  }
  return loadingSet;
}

//
// void ULoadGroupInfo::LoadGroupDifference(ELoadGroups Current, ELoadGroups
// Next, TArray<FName>& Unload, TArray<FName>& Load) {
//   //std::vector<FName>
//   Unload.Push(FName("Foo"));
//
//   //std::vector<FName> v;
//
//   //auto it = std::set_difference(Current, Next, Current:end,
//   Next:end,v.begin());
//}
