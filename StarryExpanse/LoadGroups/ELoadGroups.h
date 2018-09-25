#pragma once

#include "Engine/UserDefinedEnum.h"
#include "ELoadGroups.generated.h"

UENUM(BlueprintType)
enum class ELoadGroups : uint8 {
  AAbsoluteZero UMETA(DisplayName = "A: Absolute Zero (aka NONE)"),
  /*
  [[[cog
  import cog
  import os
  import re
  import sys
  from io import open
  from yaml import load, dump, Loader, Dumper

  stream = open('Config/load_group_definitions.yaml', 'r')
  data = load(stream, Loader=Loader)

  def flatten(l):
     accum = []
     for item in l:
        if type(item) == list:
           accum = accum + item
        else:
           accum.append(item)
     return accum

  groupnames = list(data.keys())
  groupnames.sort()

  for i, loadgroup in enumerate(groupnames):
     display = re.findall('[A-Z][^A-Z]*', loadgroup)
     display = display[0] + ': ' + ' '.join(w for w in display[1:])
     comma = '' if i == len(data.keys()) - 1 else ','
     cog.outl('%s\t\tUMETA(DisplayName = "%s")%s' % (loadgroup, display, comma))
  ]]] */
  AGeneral UMETA(DisplayName = "A: General"),
  BBalcony UMETA(DisplayName = "B: Balcony"),
  BBase UMETA(DisplayName = "B: Base"),
  BCentral UMETA(DisplayName = "B: Central"),
  BEastSide UMETA(DisplayName = "B: East Side"),
  BFiremarbleDistrict UMETA(DisplayName = "B: Firemarble District"),
  BLabDistrict UMETA(DisplayName = "B: Lab District"),
  GBase UMETA(DisplayName = "G: Base"),
  GDownside UMETA(DisplayName = "G: Downside"),
  GUpsideBase UMETA(DisplayName = "G: Upside Base"),
  GUpsideExterior UMETA(DisplayName = "G: Upside Exterior"),
  GUpsideInterior UMETA(DisplayName = "G: Upside Interior"),
  MysteriumShowOff UMETA(DisplayName = "Mysterium: Show Off"),
  SRivenBase UMETA(DisplayName = "S: Riven Base"),
  TBase UMETA(DisplayName = "T: Base"),
  TFissureDistrict UMETA(DisplayName = "T: Fissure District"),
  TMaglevDistrict UMETA(DisplayName = "T: Maglev District"),
  TNorthSide UMETA(DisplayName = "T: North Side"),
  TSpiderTunnelDistrict UMETA(DisplayName = "T: Spider Tunnel District"),
  TWestSide UMETA(DisplayName = "T: West Side")
  // [[[end]]]
};
