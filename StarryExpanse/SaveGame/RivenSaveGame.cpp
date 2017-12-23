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
  case ESaveGameField::CurrentZoomedLinkingBookIsOpen:
    return this->CurrentZoomedLinkingBookIsOpen;
  case ESaveGameField::IsGehnTrapped:
    return this->IsGehnTrapped;
  case ESaveGameField::HasTrapBook:
    return this->HasTrapBook;
  case ESaveGameField::IsCatherineFreed:
    return this->IsCatherineFreed;
  case ESaveGameField::IsSelectorValveTowardsPump:
    return this->IsSelectorValveTowardsPump;
  case ESaveGameField::IsLevelSelectorUp:
    return this->IsLevelSelectorUp;
  case ESaveGameField::IsHeaterOn:
    return this->IsHeaterOn;
  case ESaveGameField::IsFullOfWater:
    return this->IsFullOfWater;
  case ESaveGameField::PlatformRaised:
    return this->PlatformRaised;
  case ESaveGameField::HasSeenCreepyGirl:
    return this->HasSeenCreepyGirl;
  case ESaveGameField::IsOn:
    return this->IsOn;
  case ESaveGameField::IsInUnlockedState:
    return this->IsInUnlockedState;
  case ESaveGameField::IsInClosedPosition:
    return this->IsInClosedPosition;
  case ESaveGameField::IsStillPassedOut:
    return this->IsStillPassedOut;
  case ESaveGameField::IsOpen:
    return this->IsOpen;
  case ESaveGameField::IsOpen:
    return this->IsOpen;
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
  case ESaveGameField::CurrentZoomedLinkingBookIsOpen:
    this->CurrentZoomedLinkingBookIsOpen = nextVal;
    break;
  case ESaveGameField::IsGehnTrapped:
    this->IsGehnTrapped = nextVal;
    break;
  case ESaveGameField::HasTrapBook:
    this->HasTrapBook = nextVal;
    break;
  case ESaveGameField::IsCatherineFreed:
    this->IsCatherineFreed = nextVal;
    break;
  case ESaveGameField::IsSelectorValveTowardsPump:
    this->IsSelectorValveTowardsPump = nextVal;
    break;
  case ESaveGameField::IsLevelSelectorUp:
    this->IsLevelSelectorUp = nextVal;
    break;
  case ESaveGameField::IsHeaterOn:
    this->IsHeaterOn = nextVal;
    break;
  case ESaveGameField::IsFullOfWater:
    this->IsFullOfWater = nextVal;
    break;
  case ESaveGameField::PlatformRaised:
    this->PlatformRaised = nextVal;
    break;
  case ESaveGameField::HasSeenCreepyGirl:
    this->HasSeenCreepyGirl = nextVal;
    break;
  case ESaveGameField::IsOn:
    this->IsOn = nextVal;
    break;
  case ESaveGameField::IsInUnlockedState:
    this->IsInUnlockedState = nextVal;
    break;
  case ESaveGameField::IsInClosedPosition:
    this->IsInClosedPosition = nextVal;
    break;
  case ESaveGameField::IsStillPassedOut:
    this->IsStillPassedOut = nextVal;
    break;
  case ESaveGameField::IsOpen:
    this->IsOpen = nextVal;
    break;
  case ESaveGameField::IsOpen:
    this->IsOpen = nextVal;
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
  this->CurrentLoadGroup = ELoadGroups::TFissureDistrict;
  this->CurrentMarionettist = EMarionettist::NoMarionettist;
  this->CurrentZoomedLinkingBookIsOpen = false;
  this->IsGehnTrapped = false;
  this->HasTrapBook = true;
  this->IsCatherineFreed = false;
  this->CharacterTransform = FTransform::Identity;
  this->ValvePosition = 0;
  this->IsSelectorValveTowardsPump = false;
  this->IsLevelSelectorUp = false;
  this->IsHeaterOn = false;
  this->IsFullOfWater = true;
  this->PlatformRaised = false;
  this->PositionAndRotation = ESubPosRot::Plat_N;
  this->HasSeenCreepyGirl = false;
  this->ElevatorPosition = 1;
  this->IsOn = false;
  this->TimesPressed = 0;
  this->IsInUnlockedState = false;
  this->CodeA = -1;
  this->CodeB = -1;
  this->CodeC = -1;
  this->CodeD = -1;
  this->CodeE = -1;
  this->IsInClosedPosition = true;
  this->IsStillPassedOut = true;
  this->CodeA = -1;
  this->CodeB = -1;
  this->CodeC = -1;
  this->CodeD = -1;
  this->CodeE = -1;
  this->IsOpen = false;
  this->IsOpen = false;
  this->CodeA = -1;
  this->CodeB = -1;
  this->CodeC = -1;
  this->CodeD = -1;
  this->CodeE = -1;
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

    this->DomeCodeA = DomeCode[0];
    this->DomeCodeB = DomeCode[1];
    this->DomeCodeC = DomeCode[2];
    this->DomeCodeD = DomeCode[3];
    this->DomeCodeE = DomeCode[4];
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
  vars.push_back(std::make_tuple("ELoadGroups", "CurrentLoadGroup"));
  vars.push_back(std::make_tuple("EMarionettist", "CurrentMarionettist"));
  vars.push_back(std::make_tuple("bool", "CurrentZoomedLinkingBookIsOpen"));
  vars.push_back(std::make_tuple("bool", "IsGehnTrapped"));
  vars.push_back(std::make_tuple("bool", "HasTrapBook"));
  vars.push_back(std::make_tuple("bool", "IsCatherineFreed"));
  vars.push_back(std::make_tuple("FTransform", "CharacterTransform"));
  vars.push_back(std::make_tuple("int32", "ValvePosition"));
  vars.push_back(std::make_tuple("bool", "IsSelectorValveTowardsPump"));
  vars.push_back(std::make_tuple("bool", "IsLevelSelectorUp"));
  vars.push_back(std::make_tuple("bool", "IsHeaterOn"));
  vars.push_back(std::make_tuple("bool", "IsFullOfWater"));
  vars.push_back(std::make_tuple("bool", "PlatformRaised"));
  vars.push_back(std::make_tuple("ESubPosRot", "PositionAndRotation"));
  vars.push_back(std::make_tuple("bool", "HasSeenCreepyGirl"));
  vars.push_back(std::make_tuple("int32", "ElevatorPosition"));
  vars.push_back(std::make_tuple("bool", "IsOn"));
  vars.push_back(std::make_tuple("int32", "TimesPressed"));
  vars.push_back(std::make_tuple("bool", "IsInUnlockedState"));
  vars.push_back(std::make_tuple("int32", "CodeA"));
  vars.push_back(std::make_tuple("int32", "CodeB"));
  vars.push_back(std::make_tuple("int32", "CodeC"));
  vars.push_back(std::make_tuple("int32", "CodeD"));
  vars.push_back(std::make_tuple("int32", "CodeE"));
  vars.push_back(std::make_tuple("bool", "IsInClosedPosition"));
  vars.push_back(std::make_tuple("bool", "IsStillPassedOut"));
  vars.push_back(std::make_tuple("int32", "CodeA"));
  vars.push_back(std::make_tuple("int32", "CodeB"));
  vars.push_back(std::make_tuple("int32", "CodeC"));
  vars.push_back(std::make_tuple("int32", "CodeD"));
  vars.push_back(std::make_tuple("int32", "CodeE"));
  vars.push_back(std::make_tuple("bool", "IsOpen"));
  vars.push_back(std::make_tuple("bool", "IsOpen"));
  vars.push_back(std::make_tuple("int32", "CodeA"));
  vars.push_back(std::make_tuple("int32", "CodeB"));
  vars.push_back(std::make_tuple("int32", "CodeC"));
  vars.push_back(std::make_tuple("int32", "CodeD"));
  vars.push_back(std::make_tuple("int32", "CodeE"));
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
void URivenSaveGame::Set_CurrentLoadGroup(ELoadGroups NewVal) {
   this->CurrentLoadGroup = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
ELoadGroups URivenSaveGame::Get_CurrentLoadGroup() {
   return CurrentLoadGroup;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_CurrentMarionettist(EMarionettist NewVal) {
   this->CurrentMarionettist = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
EMarionettist URivenSaveGame::Get_CurrentMarionettist() {
   return CurrentMarionettist;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_CurrentZoomedLinkingBookIsOpen(bool NewVal) {
   this->CurrentZoomedLinkingBookIsOpen = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_CurrentZoomedLinkingBookIsOpen() {
   return CurrentZoomedLinkingBookIsOpen;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_IsGehnTrapped(bool NewVal) {
   this->IsGehnTrapped = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_IsGehnTrapped() {
   return IsGehnTrapped;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_HasTrapBook(bool NewVal) {
   this->HasTrapBook = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_HasTrapBook() {
   return HasTrapBook;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_IsCatherineFreed(bool NewVal) {
   this->IsCatherineFreed = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_IsCatherineFreed() {
   return IsCatherineFreed;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_CharacterTransform(FTransform NewVal) {
   this->CharacterTransform = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
FTransform URivenSaveGame::Get_CharacterTransform() {
   return CharacterTransform;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_ValvePosition(int32 NewVal) {
   this->ValvePosition = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_ValvePosition() {
   return ValvePosition;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_IsSelectorValveTowardsPump(bool NewVal) {
   this->IsSelectorValveTowardsPump = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_IsSelectorValveTowardsPump() {
   return IsSelectorValveTowardsPump;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_IsLevelSelectorUp(bool NewVal) {
   this->IsLevelSelectorUp = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_IsLevelSelectorUp() {
   return IsLevelSelectorUp;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_IsHeaterOn(bool NewVal) {
   this->IsHeaterOn = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_IsHeaterOn() {
   return IsHeaterOn;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_IsFullOfWater(bool NewVal) {
   this->IsFullOfWater = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_IsFullOfWater() {
   return IsFullOfWater;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_PlatformRaised(bool NewVal) {
   this->PlatformRaised = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_PlatformRaised() {
   return PlatformRaised;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_PositionAndRotation(ESubPosRot NewVal) {
   this->PositionAndRotation = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
ESubPosRot URivenSaveGame::Get_PositionAndRotation() {
   return PositionAndRotation;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_HasSeenCreepyGirl(bool NewVal) {
   this->HasSeenCreepyGirl = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_HasSeenCreepyGirl() {
   return HasSeenCreepyGirl;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_ElevatorPosition(int32 NewVal) {
   this->ElevatorPosition = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_ElevatorPosition() {
   return ElevatorPosition;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_IsOn(bool NewVal) {
   this->IsOn = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_IsOn() {
   return IsOn;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_TimesPressed(int32 NewVal) {
   this->TimesPressed = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_TimesPressed() {
   return TimesPressed;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_IsInUnlockedState(bool NewVal) {
   this->IsInUnlockedState = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_IsInUnlockedState() {
   return IsInUnlockedState;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_CodeA(int32 NewVal) {
   this->CodeA = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_CodeA() {
   return CodeA;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_CodeB(int32 NewVal) {
   this->CodeB = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_CodeB() {
   return CodeB;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_CodeC(int32 NewVal) {
   this->CodeC = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_CodeC() {
   return CodeC;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_CodeD(int32 NewVal) {
   this->CodeD = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_CodeD() {
   return CodeD;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_CodeE(int32 NewVal) {
   this->CodeE = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_CodeE() {
   return CodeE;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_IsInClosedPosition(bool NewVal) {
   this->IsInClosedPosition = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_IsInClosedPosition() {
   return IsInClosedPosition;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_IsStillPassedOut(bool NewVal) {
   this->IsStillPassedOut = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_IsStillPassedOut() {
   return IsStillPassedOut;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_CodeA(int32 NewVal) {
   this->CodeA = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_CodeA() {
   return CodeA;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_CodeB(int32 NewVal) {
   this->CodeB = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_CodeB() {
   return CodeB;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_CodeC(int32 NewVal) {
   this->CodeC = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_CodeC() {
   return CodeC;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_CodeD(int32 NewVal) {
   this->CodeD = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_CodeD() {
   return CodeD;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_CodeE(int32 NewVal) {
   this->CodeE = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_CodeE() {
   return CodeE;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_IsOpen(bool NewVal) {
   this->IsOpen = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_IsOpen() {
   return IsOpen;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_IsOpen(bool NewVal) {
   this->IsOpen = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_IsOpen() {
   return IsOpen;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_CodeA(int32 NewVal) {
   this->CodeA = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_CodeA() {
   return CodeA;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_CodeB(int32 NewVal) {
   this->CodeB = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_CodeB() {
   return CodeB;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_CodeC(int32 NewVal) {
   this->CodeC = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_CodeC() {
   return CodeC;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_CodeD(int32 NewVal) {
   this->CodeD = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_CodeD() {
   return CodeD;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_CodeE(int32 NewVal) {
   this->CodeE = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_CodeE() {
   return CodeE;
}

/* [[[end]]] */
