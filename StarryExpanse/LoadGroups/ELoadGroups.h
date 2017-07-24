#pragma once

#include "Engine/UserDefinedEnum.h"
#include "ELoadGroups.generated.h"


UENUM(BlueprintType)
enum class ELoadGroups : uint8
{
   AAbsoluteZero    UMETA(DisplayName = "A: Absolute Zero (aka NONE)"),
   /*
   [[[cog
   import cog
   import os
   import re
   import sys
   from io import open
   from yaml import load, dump, Loader, Dumper

   stream = open('LoadGroups/LgConfig.yaml', 'r')
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
   AGeneral		UMETA(DisplayName = "A: General"),
   BBoilerOutlet		UMETA(DisplayName = "B: Boiler Outlet"),
   BBoilerToTempleBridge		UMETA(DisplayName = "B: Boiler To Temple Bridge"),
   BBridgeCave		UMETA(DisplayName = "B: Bridge Cave"),
   BCartCave		UMETA(DisplayName = "B: Cart Cave"),
   BCartTrackAboveWater		UMETA(DisplayName = "B: Cart Track Above Water"),
   BDomePipe		UMETA(DisplayName = "B: Dome Pipe"),
   BFiremarbleCave		UMETA(DisplayName = "B: Firemarble Cave"),
   BLakeArea		UMETA(DisplayName = "B: Lake Area"),
   BMagLevDock		UMETA(DisplayName = "B: Mag Lev Dock"),
   BOfficeExterior		UMETA(DisplayName = "B: Office Exterior"),
   BOfficeInterior		UMETA(DisplayName = "B: Office Interior"),
   BTerrainInner		UMETA(DisplayName = "B: Terrain Inner"),
   BTerrainOuter		UMETA(DisplayName = "B: Terrain Outer"),
   BTerrainPath		UMETA(DisplayName = "B: Terrain Path"),
   BYtramCave		UMETA(DisplayName = "B: Ytram Cave"),
   BYtramDuct		UMETA(DisplayName = "B: Ytram Duct"),
   GBase		UMETA(DisplayName = "G: Base"),
   GDownside		UMETA(DisplayName = "G: Downside"),
   GUpsideBase		UMETA(DisplayName = "G: Upside Base"),
   GUpsideExterior		UMETA(DisplayName = "G: Upside Exterior"),
   GUpsideInterior		UMETA(DisplayName = "G: Upside Interior"),
   SRivenBase		UMETA(DisplayName = "S: Riven Base"),
   TBase		UMETA(DisplayName = "T: Base"),
   TFissureDistrict		UMETA(DisplayName = "T: Fissure District"),
   TNorthSide		UMETA(DisplayName = "T: North Side"),
   TSpiderTunnelDistrict		UMETA(DisplayName = "T: Spider Tunnel District"),
   TWestSide		UMETA(DisplayName = "T: West Side")
   // [[[end]]]
};