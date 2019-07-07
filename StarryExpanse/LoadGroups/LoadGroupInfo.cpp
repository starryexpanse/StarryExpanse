#include "LoadGroups/LoadGroupInfo.h"
#include "ELoadGroups.h"
#include "StarryExpanse.h"

ULoadGroupInfo::ULoadGroupInfo(const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer) {

  typedef std::pair<ELoadGroups, LoadgroupInfoEntry> LgEntry;

  LoadGroups.insert(LgEntry(ELoadGroups::AAbsoluteZero,
                            LoadgroupInfoEntry(FString("AAbsoluteZero"), {})));

  /*
    [[[cog
    import cog
    import os
    from io import open
    import sys
    from yaml import load, dump, Loader, Dumper

    stream = open('Config/load_group_definitions.yaml', 'r')
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
       cog.outl('LoadGroups.insert(LgEntry(')
       cog.outl('    ELoadGroups::%s,' % loadgroup)
       cog.outl('    LoadgroupInfoEntry(FString("%s"),' % loadgroup)
       cog.outl('    {')
       for i, sublevel in enumerate(sublevels):
          is_last = i == len(sublevels) - 1
          comma = ',' if not is_last else ''
          cog.outl('        FName("%s")%s' % (sublevel, comma))
       cog.outl('    }')
       cog.outl(')));')
       cog.outl('')
    ]]] */
  LoadGroups.insert(
      LgEntry(ELoadGroups::MysteriumShowOff,
              LoadgroupInfoEntry(FString("MysteriumShowOff"),
                                 {FName("G_BubbleGarden"), FName("G_Terrain"),
                                  FName("G_SpikeGarden")})));

  LoadGroups.insert(
      LgEntry(ELoadGroups::AGeneral,
              LoadgroupInfoEntry(FString("AGeneral"), {FName("A_Journals")})));

  LoadGroups.insert(LgEntry(ELoadGroups::SRivenBase,
                            LoadgroupInfoEntry(FString("SRivenBase"),
                                               {FName("S_Lighting_Riven"),
                                                FName("S_PostProcessing_Riven"),
                                                FName("S_Ocean_Riven")})));

  LoadGroups.insert(LgEntry(
      ELoadGroups::BBase,
      LoadgroupInfoEntry(FString("BBase"),
                         {FName("A_Journals"), FName("S_Lighting_Riven"),
                          FName("S_PostProcessing_Riven"),
                          FName("S_Ocean_Riven"), FName("B_Terrain")})));

  LoadGroups.insert(
      LgEntry(ELoadGroups::BEastSide,
              LoadgroupInfoEntry(
                  FString("BEastSide"),
                  {FName("A_Journals"), FName("S_Lighting_Riven"),
                   FName("S_PostProcessing_Riven"), FName("S_Ocean_Riven"),
                   FName("B_Terrain"), FName("S_GreatBridge"),
                   FName("T_SuperDome"), FName("T_Terrain")})));

  LoadGroups.insert(
      LgEntry(ELoadGroups::BCentral,
              LoadgroupInfoEntry(
                  FString("BCentral"),
                  {FName("A_Journals"), FName("S_Lighting_Riven"),
                   FName("S_PostProcessing_Riven"), FName("S_Ocean_Riven"),
                   FName("B_Terrain"), FName("B_Balcony"),
                   FName("B_RaisedWalkway"), FName("B_YtramCave"),
                   FName("B_Lab"), FName("B_CartTunnel"), FName("B_Basin")})));

  LoadGroups.insert(LgEntry(
      ELoadGroups::BBalcony,
      LoadgroupInfoEntry(FString("BBalcony"),
                         {FName("A_Journals"), FName("S_Lighting_Riven"),
                          FName("S_PostProcessing_Riven"),
                          FName("S_Ocean_Riven"), FName("B_Terrain"),
                          FName("B_Balcony"), FName("B_RaisedWalkway"),
                          FName("B_YtramCave"), FName("B_Lab"),
                          FName("B_Basin"), FName("B_FireMarbleChamber")})));

  LoadGroups.insert(
      LgEntry(ELoadGroups::BFiremarbleDistrict,
              LoadgroupInfoEntry(
                  FString("BFiremarbleDistrict"),
                  {FName("A_Journals"), FName("S_Lighting_Riven"),
                   FName("S_PostProcessing_Riven"), FName("S_Ocean_Riven"),
                   FName("B_Terrain"), FName("B_Balcony"),
                   FName("B_RaisedWalkway"), FName("B_YtramCave"),
                   FName("B_Basin"), FName("B_FireMarbleChamber")})));

  LoadGroups.insert(LgEntry(
      ELoadGroups::BLabDistrict,
      LoadgroupInfoEntry(
          FString("BLabDistrict"),
          {FName("A_Journals"), FName("S_Lighting_Riven"),
           FName("S_PostProcessing_Riven"), FName("S_Ocean_Riven"),
           FName("B_Terrain"), FName("B_Balcony"), FName("B_RaisedWalkway"),
           FName("B_Lab"), FName("B_MaglevDock"), FName("B_Basin")})));

  LoadGroups.insert(
      LgEntry(ELoadGroups::GBase,
              LoadgroupInfoEntry(
                  FString("GBase"),
                  {FName("A_Journals"), FName("S_Lighting_Riven"),
                   FName("S_PostProcessing_Riven"), FName("S_Ocean_Riven")})));

  LoadGroups.insert(
      LgEntry(ELoadGroups::GUpsideBase,
              LoadgroupInfoEntry(FString("GUpsideBase"),
                                 {FName("G_Terrain"), FName("G_BubbleGarden"),
                                  FName("G_Connector")})));

  LoadGroups.insert(LgEntry(
      ELoadGroups::GInteriorBase,
      LoadgroupInfoEntry(FString("GInteriorBase"),
                         {FName("G_Elevator"), FName("G_Elevator_Lighting")})));

  LoadGroups.insert(LgEntry(
      ELoadGroups::GUpsideExterior,
      LoadgroupInfoEntry(FString("GUpsideExterior"),
                         {FName("A_Journals"), FName("S_Lighting_Riven"),
                          FName("S_PostProcessing_Riven"),
                          FName("S_Ocean_Riven"), FName("G_Terrain"),
                          FName("G_BubbleGarden"), FName("G_Connector"),
                          FName("G_WahrkTankUpper"), FName("G_SpikeGarden")})));

  LoadGroups.insert(
      LgEntry(ELoadGroups::GUpsideInterior,
              LoadgroupInfoEntry(
                  FString("GUpsideInterior"),
                  {FName("A_Journals"), FName("S_Lighting_Riven"),
                   FName("S_PostProcessing_Riven"), FName("S_Ocean_Riven"),
                   FName("G_Terrain"), FName("G_BubbleGarden"),
                   FName("G_Connector"), FName("G_Elevator"),
                   FName("G_Elevator_Lighting"), FName("G_MaglevDock_B")})));

  LoadGroups.insert(
      LgEntry(ELoadGroups::GDownsideInterior,
              LoadgroupInfoEntry(
                  FString("GDownsideInterior"),
                  {FName("A_Journals"), FName("S_Lighting_Riven"),
                   FName("S_PostProcessing_Riven"), FName("S_Ocean_Riven"),
                   FName("G_Elevator"), FName("G_Elevator_Lighting"),
                   FName("G_MaglevDock_J"), FName("G_WahrkTankLower")})));

  LoadGroups.insert(LgEntry(
      ELoadGroups::TBase,
      LoadgroupInfoEntry(FString("TBase"),
                         {FName("A_Journals"), FName("S_Lighting_Riven"),
                          FName("S_PostProcessing_Riven"),
                          FName("S_Ocean_Riven"), FName("T_Terrain")})));

  LoadGroups.insert(
      LgEntry(ELoadGroups::TWestSide,
              LoadgroupInfoEntry(
                  FString("TWestSide"),
                  {FName("A_Journals"), FName("S_Lighting_Riven"),
                   FName("S_PostProcessing_Riven"), FName("S_Ocean_Riven"),
                   FName("T_Terrain"), FName("B_CartTrack_Structures"),
                   FName("B_Terrain_Structures"), FName("S_GreatBridge"),
                   FName("T_SuperDome"), FName("T_GateRoom")})));

  LoadGroups.insert(
      LgEntry(ELoadGroups::TNorthSide,
              LoadgroupInfoEntry(
                  FString("TNorthSide"),
                  {FName("A_Journals"), FName("S_Lighting_Riven"),
                   FName("S_PostProcessing_Riven"), FName("S_Ocean_Riven"),
                   FName("T_Terrain"), FName("B_CartTrack_Structures"),
                   FName("B_Terrain_Structures"), FName("S_GreatBridge"),
                   FName("T_GateRoom"), FName("T_SuperDome")})));

  LoadGroups.insert(
      LgEntry(ELoadGroups::TFissureDistrict,
              LoadgroupInfoEntry(
                  FString("TFissureDistrict"),
                  {FName("A_Journals"), FName("S_Lighting_Riven"),
                   FName("S_PostProcessing_Riven"), FName("S_Ocean_Riven"),
                   FName("T_Terrain"), FName("T_GateRoom"), FName("T_Plateaus"),
                   FName("T_NewTemple"), FName("T_SuperDome")})));

  LoadGroups.insert(
      LgEntry(ELoadGroups::TSpiderTunnelDistrict,
              LoadgroupInfoEntry(
                  FString("TSpiderTunnelDistrict"),
                  {FName("A_Journals"), FName("S_Lighting_Riven"),
                   FName("S_PostProcessing_Riven"), FName("S_Ocean_Riven"),
                   FName("T_Terrain"), FName("T_GateRoom"), FName("T_Plateaus"),
                   FName("T_SpiderChairRoomInterior"), FName("T_NewTemple"),
                   FName("S_Maglev_TJ"), FName("T_SuperDome")})));

  LoadGroups.insert(
      LgEntry(ELoadGroups::TMaglevDistrict,
              LoadgroupInfoEntry(
                  FString("TMaglevDistrict"),
                  {FName("A_Journals"), FName("S_Lighting_Riven"),
                   FName("S_PostProcessing_Riven"), FName("S_Ocean_Riven"),
                   FName("T_Terrain"), FName("B_CartTrack_Structures"),
                   FName("B_Terrain_Structures"), FName("S_Maglev_TJ")})));

  // [[[end]]]
}

bool ULoadGroupInfo::IsLevelInLoadGroup(FName level, ELoadGroups lg) {
  MapType::iterator it = LoadGroups.find(lg);
  if (it == LoadGroups.end()) {
    return false;
  }

  SetType map = it->second.Levels;

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

  SetType levels = it->second.Levels;
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

TArray<FString> ULoadGroupInfo::GetLoadgroupNamesStartingWith(FString prefix) {
  TArray<FString> result;
  for (const auto &pair : LoadGroups) {
    auto name = pair.second.Name;
    if (name.StartsWith(prefix)) {
      result.Add(name);
    }
  }
  return result;
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
