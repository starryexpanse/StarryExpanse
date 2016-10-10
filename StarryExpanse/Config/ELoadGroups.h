#pragma once

#include "Engine/UserDefinedEnum.h"
#include "ELoadGroups.generated.h"


UENUM(BlueprintType)
enum class ELoadGroups : uint8
{
    // B
    BCartTrackAboveWater  UMETA(DisplayName = "B: Cart Track Above Water"            ),
    BCartCave             UMETA(DisplayName = "B: Cart Cave"                         ),
    BTerrainOuter         UMETA(DisplayName = "B: Terrain Outer"                     ),
    BDomePipe             UMETA(DisplayName = "B: Dome Pipe"                         ),
    BTerrainInner         UMETA(DisplayName = "B: Terrain Inner"                     ),
    BLakeArea             UMETA(DisplayName = "B: Lake Area"                         ),
    BBoilerOutlet         UMETA(DisplayName = "B: Boiler Outlet"                     ),
    BTerrainPath          UMETA(DisplayName = "B: Terrain Path (Outlet to Walkway)"  ),
    BYtramCave            UMETA(DisplayName = "B: Ytram Cave"                        ),
    BFiremarbleCave       UMETA(DisplayName = "B: Firemarble Cave"                   ),
    BBridgeCave           UMETA(DisplayName = "B: Bridge Cave"                       ),
    BBoilerToTempleBridge UMETA(DisplayName = "B: Boiler to Temple Bridge"           ),
    BYtramDuct            UMETA(DisplayName = "B: Ytram Duct"                        ),
    BOfficeExterior       UMETA(DisplayName = "B: Office Exterior"                   ),
    BOfficeInterior       UMETA(DisplayName = "B: Office Interior"                   ),
    BMagLevDock           UMETA(DisplayName = "B: MagLev Dock"                       )
};
