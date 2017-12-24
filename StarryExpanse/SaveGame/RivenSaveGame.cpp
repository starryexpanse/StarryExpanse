//
// Copyright 2017 59 Volt Entertainment, all rights reserved.
//

#include "SaveGame/RivenSaveGame.h"
#include "SaveGame/ESaveGameField.h"
#include "StarryExpanse.h"

/* [[[cog
import cog
from rivensavegame_generator import vars as allvars, p

def vars(type):
  vars_of_type = [var for var in allvars if var[0] == type]
  return (vars_of_type, len(vars_of_type))

def wrap(ident):
  return "ESaveGameField::" + ident

def if_check(type):
  vars_of_type, n = vars(type)
  p('if (')
  for i, b in enumerate(vars_of_type):
    last = i == n - 1
    p('fieldName == %s%s' % (wrap(b[1]), ' ||' if not last else ''))
  p(') {')

]]] */
// [[[end]]]

URivenSaveGame::URivenSaveGame(const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer) {
  this->RestoreNewGameDefaults();
}

bool URivenSaveGame::GetBooleanBySaveGameField(ESaveGameField fieldName) {
  switch (fieldName) {
  /*
  [[[cog
      vars_of_type, n = vars('bool')
      for i, b in enumerate(vars_of_type):
        p('  case %s:' % wrap(b[1]))
        p('    return this->%s;' % (b[1],))
  ]]] */
  case ESaveGameField::A_Books_CurrentZoomedLinkingBookIsOpen:
    return this->A_Books_CurrentZoomedLinkingBookIsOpen;
  case ESaveGameField::A_Books_IsGehnTrapped:
    return this->A_Books_IsGehnTrapped;
  case ESaveGameField::A_Books_HasTrapBook:
    return this->A_Books_HasTrapBook;
  case ESaveGameField::A_Books_IsCatherineFreed:
    return this->A_Books_IsCatherineFreed;
  case ESaveGameField::B_BoilerExterior_IsSelectorValveTowardsPump:
    return this->B_BoilerExterior_IsSelectorValveTowardsPump;
  case ESaveGameField::B_BoilerExterior_IsLevelSelectorUp:
    return this->B_BoilerExterior_IsLevelSelectorUp;
  case ESaveGameField::B_BoilerExterior_IsHeaterOn:
    return this->B_BoilerExterior_IsHeaterOn;
  case ESaveGameField::B_BoilerInterior_IsFullOfWater:
    return this->B_BoilerInterior_IsFullOfWater;
  case ESaveGameField::B_BoilerInterior_PlatformRaised:
    return this->B_BoilerInterior_PlatformRaised;
  case ESaveGameField::J_TunnelBranch_HasSeenCreepyGirl:
    return this->J_TunnelBranch_HasSeenCreepyGirl;
  case ESaveGameField::O_Stove_IsOn:
    return this->O_Stove_IsOn;
  case ESaveGameField::O_CageLever_IsInUnlockedState:
    return this->O_CageLever_IsInUnlockedState;
  case ESaveGameField::T_FissurePlateau_CageLever_IsInClosedPosition:
    return this->T_FissurePlateau_CageLever_IsInClosedPosition;
  case ESaveGameField::T_FissurePlateau_Cho_IsStillPassedOut:
    return this->T_FissurePlateau_Cho_IsStillPassedOut;
  case ESaveGameField::T_NewTemple_DoorMain_IsOpen:
    return this->T_NewTemple_DoorMain_IsOpen;
  case ESaveGameField::T_NewTemple_DoorSide_IsOpen:
    return this->T_NewTemple_DoorSide_IsOpen;
  // [[[end]]]
  default:
    UE_LOG(StarryDebug, Error, TEXT("%s is not a boolean."),
           *GetSaveGameFieldAsString(fieldName));
    return false;
  }
}

void URivenSaveGame::SetBooleanBySaveGameField(ESaveGameField fieldName,
                                               bool nextVal) {
  switch (fieldName) {
  /*
  [[[cog

  vars_of_type, n = vars('bool')
  for i, b in enumerate(vars_of_type):
    p('    case %s:' % wrap(b[1]))
    p('      this->%s = nextVal;' % b[1])
    p('      break;')

  ]]] */
  case ESaveGameField::A_Books_CurrentZoomedLinkingBookIsOpen:
    this->A_Books_CurrentZoomedLinkingBookIsOpen = nextVal;
    break;
  case ESaveGameField::A_Books_IsGehnTrapped:
    this->A_Books_IsGehnTrapped = nextVal;
    break;
  case ESaveGameField::A_Books_HasTrapBook:
    this->A_Books_HasTrapBook = nextVal;
    break;
  case ESaveGameField::A_Books_IsCatherineFreed:
    this->A_Books_IsCatherineFreed = nextVal;
    break;
  case ESaveGameField::B_BoilerExterior_IsSelectorValveTowardsPump:
    this->B_BoilerExterior_IsSelectorValveTowardsPump = nextVal;
    break;
  case ESaveGameField::B_BoilerExterior_IsLevelSelectorUp:
    this->B_BoilerExterior_IsLevelSelectorUp = nextVal;
    break;
  case ESaveGameField::B_BoilerExterior_IsHeaterOn:
    this->B_BoilerExterior_IsHeaterOn = nextVal;
    break;
  case ESaveGameField::B_BoilerInterior_IsFullOfWater:
    this->B_BoilerInterior_IsFullOfWater = nextVal;
    break;
  case ESaveGameField::B_BoilerInterior_PlatformRaised:
    this->B_BoilerInterior_PlatformRaised = nextVal;
    break;
  case ESaveGameField::J_TunnelBranch_HasSeenCreepyGirl:
    this->J_TunnelBranch_HasSeenCreepyGirl = nextVal;
    break;
  case ESaveGameField::O_Stove_IsOn:
    this->O_Stove_IsOn = nextVal;
    break;
  case ESaveGameField::O_CageLever_IsInUnlockedState:
    this->O_CageLever_IsInUnlockedState = nextVal;
    break;
  case ESaveGameField::T_FissurePlateau_CageLever_IsInClosedPosition:
    this->T_FissurePlateau_CageLever_IsInClosedPosition = nextVal;
    break;
  case ESaveGameField::T_FissurePlateau_Cho_IsStillPassedOut:
    this->T_FissurePlateau_Cho_IsStillPassedOut = nextVal;
    break;
  case ESaveGameField::T_NewTemple_DoorMain_IsOpen:
    this->T_NewTemple_DoorMain_IsOpen = nextVal;
    break;
  case ESaveGameField::T_NewTemple_DoorSide_IsOpen:
    this->T_NewTemple_DoorSide_IsOpen = nextVal;
    break;
  // [[[end]]]
  default:
    UE_LOG(StarryDebug, Error, TEXT("%s is not a boolean."),
           *GetSaveGameFieldAsString(fieldName));
  }
}

void URivenSaveGame::RestoreNewGameDefaults() {
  /*
  [[[cog
     import cog
     from rivensavegame_generator import vars, p

     for var in vars:
        p('this->%s = %s;' % (var[1], var[2]))
  ]]] */
  this->A_LoadGroups_CurrentLoadGroup = ELoadGroups::TFissureDistrict;
  this->A_Marionettist_CurrentMarionettist = EMarionettist::NoMarionettist;
  this->A_Books_CurrentZoomedLinkingBookIsOpen = false;
  this->A_Books_IsGehnTrapped = false;
  this->A_Books_HasTrapBook = true;
  this->A_Books_IsCatherineFreed = false;
  this->A_RivenCharacter_CharacterTransform = FTransform::Identity;
  this->B_Shore_ValvePosition = 0;
  this->B_BoilerExterior_IsSelectorValveTowardsPump = false;
  this->B_BoilerExterior_IsLevelSelectorUp = false;
  this->B_BoilerExterior_IsHeaterOn = false;
  this->B_BoilerInterior_IsFullOfWater = true;
  this->B_BoilerInterior_PlatformRaised = false;
  this->J_Submarine_PositionAndRotation = ESubPosRot::Plat_N;
  this->J_TunnelBranch_HasSeenCreepyGirl = false;
  this->J_IdolInterior_ElevatorPosition = 1;
  this->O_Stove_IsOn = false;
  this->O_CageButton_TimesPressed = 0;
  this->O_CageLever_IsInUnlockedState = false;
  this->S_Dome_CodeA = -1;
  this->S_Dome_CodeB = -1;
  this->S_Dome_CodeC = -1;
  this->S_Dome_CodeD = -1;
  this->S_Dome_CodeE = -1;
  this->T_FissurePlateau_CageLever_IsInClosedPosition = true;
  this->T_FissurePlateau_Cho_IsStillPassedOut = true;
  this->T_FissurePlateau_Telescope_CodeA = -1;
  this->T_FissurePlateau_Telescope_CodeB = -1;
  this->T_FissurePlateau_Telescope_CodeC = -1;
  this->T_FissurePlateau_Telescope_CodeD = -1;
  this->T_FissurePlateau_Telescope_CodeE = -1;
  this->T_NewTemple_DoorMain_IsOpen = false;
  this->T_NewTemple_DoorSide_IsOpen = false;
  this->P_Exterior_Lock_CodeA = -1;
  this->P_Exterior_Lock_CodeB = -1;
  this->P_Exterior_Lock_CodeC = -1;
  this->P_Exterior_Lock_CodeD = -1;
  this->P_Exterior_Lock_CodeE = -1;
  /* [[[end]]]*/

  this->TelescopeCodeA = FMath::RandRange(0, 4);
  this->TelescopeCodeB = FMath::RandRange(0, 4);
  this->TelescopeCodeC = FMath::RandRange(0, 4);
  this->TelescopeCodeD = FMath::RandRange(0, 4);
  this->TelescopeCodeE = FMath::RandRange(0, 4);

  // Generate dome code. I tried a more constant-time way but it had pretty
  // uneven distributions. There's another way to accomplish the same task in
  // constant time, but this is simple.
  {
    TArray<int> DomeCode;

    bool slots[25];
    for (int i = 0; i < 25; i++) {
      slots[i] = 0;
    }

    int hits = 0;
    while (hits < 5) {
      int dartShot = FMath::RandRange(0, 25);
      if (!slots[dartShot]) {
        slots[dartShot] = true;
        DomeCode.Add(dartShot);
        hits++;
      }
    }

    DomeCode.Sort();

    this->S_Dome_CodeA = DomeCode[0];
    this->S_Dome_CodeB = DomeCode[1];
    this->S_Dome_CodeC = DomeCode[2];
    this->S_Dome_CodeD = DomeCode[3];
    this->S_Dome_CodeE = DomeCode[4];
  }
}

std::vector<std::tuple<std::string, std::string>>
URivenSaveGame::GetSavegameFields() {
  std::vector<std::tuple<std::string, std::string>> vars;

  /*[[[cog
    def wrap(text):
      return '"%s"' % text.replace("\"", "\\\"")

    for var in vars:
      p('vars.push_back(std::make_tuple(%s, %s));' % (
        wrap(var[0]),
        wrap(var[1])
      ))
  ]]] */
  vars.push_back(
      std::make_tuple("ELoadGroups", "A_LoadGroups_CurrentLoadGroup"));
  vars.push_back(
      std::make_tuple("EMarionettist", "A_Marionettist_CurrentMarionettist"));
  vars.push_back(
      std::make_tuple("bool", "A_Books_CurrentZoomedLinkingBookIsOpen"));
  vars.push_back(std::make_tuple("bool", "A_Books_IsGehnTrapped"));
  vars.push_back(std::make_tuple("bool", "A_Books_HasTrapBook"));
  vars.push_back(std::make_tuple("bool", "A_Books_IsCatherineFreed"));
  vars.push_back(
      std::make_tuple("FTransform", "A_RivenCharacter_CharacterTransform"));
  vars.push_back(std::make_tuple("int32", "B_Shore_ValvePosition"));
  vars.push_back(
      std::make_tuple("bool", "B_BoilerExterior_IsSelectorValveTowardsPump"));
  vars.push_back(std::make_tuple("bool", "B_BoilerExterior_IsLevelSelectorUp"));
  vars.push_back(std::make_tuple("bool", "B_BoilerExterior_IsHeaterOn"));
  vars.push_back(std::make_tuple("bool", "B_BoilerInterior_IsFullOfWater"));
  vars.push_back(std::make_tuple("bool", "B_BoilerInterior_PlatformRaised"));
  vars.push_back(
      std::make_tuple("ESubPosRot", "J_Submarine_PositionAndRotation"));
  vars.push_back(std::make_tuple("bool", "J_TunnelBranch_HasSeenCreepyGirl"));
  vars.push_back(std::make_tuple("int32", "J_IdolInterior_ElevatorPosition"));
  vars.push_back(std::make_tuple("bool", "O_Stove_IsOn"));
  vars.push_back(std::make_tuple("int32", "O_CageButton_TimesPressed"));
  vars.push_back(std::make_tuple("bool", "O_CageLever_IsInUnlockedState"));
  vars.push_back(std::make_tuple("int32", "S_Dome_CodeA"));
  vars.push_back(std::make_tuple("int32", "S_Dome_CodeB"));
  vars.push_back(std::make_tuple("int32", "S_Dome_CodeC"));
  vars.push_back(std::make_tuple("int32", "S_Dome_CodeD"));
  vars.push_back(std::make_tuple("int32", "S_Dome_CodeE"));
  vars.push_back(
      std::make_tuple("bool", "T_FissurePlateau_CageLever_IsInClosedPosition"));
  vars.push_back(
      std::make_tuple("bool", "T_FissurePlateau_Cho_IsStillPassedOut"));
  vars.push_back(std::make_tuple("int32", "T_FissurePlateau_Telescope_CodeA"));
  vars.push_back(std::make_tuple("int32", "T_FissurePlateau_Telescope_CodeB"));
  vars.push_back(std::make_tuple("int32", "T_FissurePlateau_Telescope_CodeC"));
  vars.push_back(std::make_tuple("int32", "T_FissurePlateau_Telescope_CodeD"));
  vars.push_back(std::make_tuple("int32", "T_FissurePlateau_Telescope_CodeE"));
  vars.push_back(std::make_tuple("bool", "T_NewTemple_DoorMain_IsOpen"));
  vars.push_back(std::make_tuple("bool", "T_NewTemple_DoorSide_IsOpen"));
  vars.push_back(std::make_tuple("int32", "P_Exterior_Lock_CodeA"));
  vars.push_back(std::make_tuple("int32", "P_Exterior_Lock_CodeB"));
  vars.push_back(std::make_tuple("int32", "P_Exterior_Lock_CodeC"));
  vars.push_back(std::make_tuple("int32", "P_Exterior_Lock_CodeD"));
  vars.push_back(std::make_tuple("int32", "P_Exterior_Lock_CodeE"));
  /* [[[end]]]*/

  return vars;
}

/*
 * [[[cog
   import cog
   from rivensavegame_generator import vars, p

   for var in vars:
      # Setters
      p("UFUNCTION(BlueprintCallable, Category = SaveGame)")
      p("void URivenSaveGame::Set_%s(%s NewVal) {" % (var[1], var[0]))
      p("   this->%s = NewVal;" % var[1])
      p("}")
      p("")
      p("")

      # Getters
      p("UFUNCTION(BlueprintCallable, Category = SaveGame)")
      p("%s URivenSaveGame::Get_%s() {" % (var[0], var[1]))
      p("   return %s;" % var[1])
      p("}")
      p("")

]]] */
UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_A_LoadGroups_CurrentLoadGroup(ELoadGroups NewVal) {
  this->A_LoadGroups_CurrentLoadGroup = NewVal;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
ELoadGroups URivenSaveGame::Get_A_LoadGroups_CurrentLoadGroup() {
  return A_LoadGroups_CurrentLoadGroup;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_A_Marionettist_CurrentMarionettist(
    EMarionettist NewVal) {
  this->A_Marionettist_CurrentMarionettist = NewVal;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
EMarionettist URivenSaveGame::Get_A_Marionettist_CurrentMarionettist() {
  return A_Marionettist_CurrentMarionettist;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_A_Books_CurrentZoomedLinkingBookIsOpen(bool NewVal) {
  this->A_Books_CurrentZoomedLinkingBookIsOpen = NewVal;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_A_Books_CurrentZoomedLinkingBookIsOpen() {
  return A_Books_CurrentZoomedLinkingBookIsOpen;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_A_Books_IsGehnTrapped(bool NewVal) {
  this->A_Books_IsGehnTrapped = NewVal;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_A_Books_IsGehnTrapped() {
  return A_Books_IsGehnTrapped;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_A_Books_HasTrapBook(bool NewVal) {
  this->A_Books_HasTrapBook = NewVal;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_A_Books_HasTrapBook() { return A_Books_HasTrapBook; }

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_A_Books_IsCatherineFreed(bool NewVal) {
  this->A_Books_IsCatherineFreed = NewVal;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_A_Books_IsCatherineFreed() {
  return A_Books_IsCatherineFreed;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_A_RivenCharacter_CharacterTransform(
    FTransform NewVal) {
  this->A_RivenCharacter_CharacterTransform = NewVal;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
FTransform URivenSaveGame::Get_A_RivenCharacter_CharacterTransform() {
  return A_RivenCharacter_CharacterTransform;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_B_Shore_ValvePosition(int32 NewVal) {
  this->B_Shore_ValvePosition = NewVal;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_B_Shore_ValvePosition() {
  return B_Shore_ValvePosition;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_B_BoilerExterior_IsSelectorValveTowardsPump(
    bool NewVal) {
  this->B_BoilerExterior_IsSelectorValveTowardsPump = NewVal;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_B_BoilerExterior_IsSelectorValveTowardsPump() {
  return B_BoilerExterior_IsSelectorValveTowardsPump;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_B_BoilerExterior_IsLevelSelectorUp(bool NewVal) {
  this->B_BoilerExterior_IsLevelSelectorUp = NewVal;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_B_BoilerExterior_IsLevelSelectorUp() {
  return B_BoilerExterior_IsLevelSelectorUp;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_B_BoilerExterior_IsHeaterOn(bool NewVal) {
  this->B_BoilerExterior_IsHeaterOn = NewVal;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_B_BoilerExterior_IsHeaterOn() {
  return B_BoilerExterior_IsHeaterOn;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_B_BoilerInterior_IsFullOfWater(bool NewVal) {
  this->B_BoilerInterior_IsFullOfWater = NewVal;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_B_BoilerInterior_IsFullOfWater() {
  return B_BoilerInterior_IsFullOfWater;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_B_BoilerInterior_PlatformRaised(bool NewVal) {
  this->B_BoilerInterior_PlatformRaised = NewVal;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_B_BoilerInterior_PlatformRaised() {
  return B_BoilerInterior_PlatformRaised;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_J_Submarine_PositionAndRotation(ESubPosRot NewVal) {
  this->J_Submarine_PositionAndRotation = NewVal;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
ESubPosRot URivenSaveGame::Get_J_Submarine_PositionAndRotation() {
  return J_Submarine_PositionAndRotation;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_J_TunnelBranch_HasSeenCreepyGirl(bool NewVal) {
  this->J_TunnelBranch_HasSeenCreepyGirl = NewVal;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_J_TunnelBranch_HasSeenCreepyGirl() {
  return J_TunnelBranch_HasSeenCreepyGirl;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_J_IdolInterior_ElevatorPosition(int32 NewVal) {
  this->J_IdolInterior_ElevatorPosition = NewVal;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_J_IdolInterior_ElevatorPosition() {
  return J_IdolInterior_ElevatorPosition;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_O_Stove_IsOn(bool NewVal) {
  this->O_Stove_IsOn = NewVal;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_O_Stove_IsOn() { return O_Stove_IsOn; }

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_O_CageButton_TimesPressed(int32 NewVal) {
  this->O_CageButton_TimesPressed = NewVal;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_O_CageButton_TimesPressed() {
  return O_CageButton_TimesPressed;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_O_CageLever_IsInUnlockedState(bool NewVal) {
  this->O_CageLever_IsInUnlockedState = NewVal;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_O_CageLever_IsInUnlockedState() {
  return O_CageLever_IsInUnlockedState;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_S_Dome_CodeA(int32 NewVal) {
  this->S_Dome_CodeA = NewVal;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_S_Dome_CodeA() { return S_Dome_CodeA; }

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_S_Dome_CodeB(int32 NewVal) {
  this->S_Dome_CodeB = NewVal;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_S_Dome_CodeB() { return S_Dome_CodeB; }

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_S_Dome_CodeC(int32 NewVal) {
  this->S_Dome_CodeC = NewVal;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_S_Dome_CodeC() { return S_Dome_CodeC; }

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_S_Dome_CodeD(int32 NewVal) {
  this->S_Dome_CodeD = NewVal;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_S_Dome_CodeD() { return S_Dome_CodeD; }

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_S_Dome_CodeE(int32 NewVal) {
  this->S_Dome_CodeE = NewVal;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_S_Dome_CodeE() { return S_Dome_CodeE; }

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_T_FissurePlateau_CageLever_IsInClosedPosition(
    bool NewVal) {
  this->T_FissurePlateau_CageLever_IsInClosedPosition = NewVal;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_T_FissurePlateau_CageLever_IsInClosedPosition() {
  return T_FissurePlateau_CageLever_IsInClosedPosition;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_T_FissurePlateau_Cho_IsStillPassedOut(bool NewVal) {
  this->T_FissurePlateau_Cho_IsStillPassedOut = NewVal;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_T_FissurePlateau_Cho_IsStillPassedOut() {
  return T_FissurePlateau_Cho_IsStillPassedOut;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_T_FissurePlateau_Telescope_CodeA(int32 NewVal) {
  this->T_FissurePlateau_Telescope_CodeA = NewVal;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_T_FissurePlateau_Telescope_CodeA() {
  return T_FissurePlateau_Telescope_CodeA;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_T_FissurePlateau_Telescope_CodeB(int32 NewVal) {
  this->T_FissurePlateau_Telescope_CodeB = NewVal;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_T_FissurePlateau_Telescope_CodeB() {
  return T_FissurePlateau_Telescope_CodeB;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_T_FissurePlateau_Telescope_CodeC(int32 NewVal) {
  this->T_FissurePlateau_Telescope_CodeC = NewVal;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_T_FissurePlateau_Telescope_CodeC() {
  return T_FissurePlateau_Telescope_CodeC;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_T_FissurePlateau_Telescope_CodeD(int32 NewVal) {
  this->T_FissurePlateau_Telescope_CodeD = NewVal;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_T_FissurePlateau_Telescope_CodeD() {
  return T_FissurePlateau_Telescope_CodeD;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_T_FissurePlateau_Telescope_CodeE(int32 NewVal) {
  this->T_FissurePlateau_Telescope_CodeE = NewVal;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_T_FissurePlateau_Telescope_CodeE() {
  return T_FissurePlateau_Telescope_CodeE;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_T_NewTemple_DoorMain_IsOpen(bool NewVal) {
  this->T_NewTemple_DoorMain_IsOpen = NewVal;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_T_NewTemple_DoorMain_IsOpen() {
  return T_NewTemple_DoorMain_IsOpen;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_T_NewTemple_DoorSide_IsOpen(bool NewVal) {
  this->T_NewTemple_DoorSide_IsOpen = NewVal;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_T_NewTemple_DoorSide_IsOpen() {
  return T_NewTemple_DoorSide_IsOpen;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_P_Exterior_Lock_CodeA(int32 NewVal) {
  this->P_Exterior_Lock_CodeA = NewVal;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_P_Exterior_Lock_CodeA() {
  return P_Exterior_Lock_CodeA;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_P_Exterior_Lock_CodeB(int32 NewVal) {
  this->P_Exterior_Lock_CodeB = NewVal;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_P_Exterior_Lock_CodeB() {
  return P_Exterior_Lock_CodeB;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_P_Exterior_Lock_CodeC(int32 NewVal) {
  this->P_Exterior_Lock_CodeC = NewVal;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_P_Exterior_Lock_CodeC() {
  return P_Exterior_Lock_CodeC;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_P_Exterior_Lock_CodeD(int32 NewVal) {
  this->P_Exterior_Lock_CodeD = NewVal;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_P_Exterior_Lock_CodeD() {
  return P_Exterior_Lock_CodeD;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_P_Exterior_Lock_CodeE(int32 NewVal) {
  this->P_Exterior_Lock_CodeE = NewVal;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_P_Exterior_Lock_CodeE() {
  return P_Exterior_Lock_CodeE;
}

/* [[[end]]] */
