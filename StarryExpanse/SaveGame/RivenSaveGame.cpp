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
  case ESaveGameField::GehnIsTrapped:
    return this->GehnIsTrapped;
  case ESaveGameField::HaveTrapBook:
    return this->HaveTrapBook;
  case ESaveGameField::CatherineIsFree:
    return this->CatherineIsFree;
  case ESaveGameField::J_SeenCreepyGirl:
    return this->J_SeenCreepyGirl;
  case ESaveGameField::O_OvenIsOn:
    return this->O_OvenIsOn;
  case ESaveGameField::O_CageIsUp:
    return this->O_CageIsUp;
  case ESaveGameField::T_NewTemple_DoorMain_Open:
    return this->T_NewTemple_DoorMain_Open;
  case ESaveGameField::T_NewTemple_DoorSide_Open:
    return this->T_NewTemple_DoorSide_Open;
  case ESaveGameField::T_FissurePlateau_CageLever_Closed:
    return this->T_FissurePlateau_CageLever_Closed;
  case ESaveGameField::T_FissurePlateau_ChoStillPassedOut:
    return this->T_FissurePlateau_ChoStillPassedOut;
  case ESaveGameField::S_SeenScribe:
    return this->S_SeenScribe;
  case ESaveGameField::B_GehnHasVisited:
    return this->B_GehnHasVisited;
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
  case ESaveGameField::GehnIsTrapped:
    this->GehnIsTrapped = nextVal;
    break;
  case ESaveGameField::HaveTrapBook:
    this->HaveTrapBook = nextVal;
    break;
  case ESaveGameField::CatherineIsFree:
    this->CatherineIsFree = nextVal;
    break;
  case ESaveGameField::J_SeenCreepyGirl:
    this->J_SeenCreepyGirl = nextVal;
    break;
  case ESaveGameField::O_OvenIsOn:
    this->O_OvenIsOn = nextVal;
    break;
  case ESaveGameField::O_CageIsUp:
    this->O_CageIsUp = nextVal;
    break;
  case ESaveGameField::T_NewTemple_DoorMain_Open:
    this->T_NewTemple_DoorMain_Open = nextVal;
    break;
  case ESaveGameField::T_NewTemple_DoorSide_Open:
    this->T_NewTemple_DoorSide_Open = nextVal;
    break;
  case ESaveGameField::T_FissurePlateau_CageLever_Closed:
    this->T_FissurePlateau_CageLever_Closed = nextVal;
    break;
  case ESaveGameField::T_FissurePlateau_ChoStillPassedOut:
    this->T_FissurePlateau_ChoStillPassedOut = nextVal;
    break;
  case ESaveGameField::S_SeenScribe:
    this->S_SeenScribe = nextVal;
    break;
  case ESaveGameField::B_GehnHasVisited:
    this->B_GehnHasVisited = nextVal;
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
  this->GehnIsTrapped = false;
  this->HaveTrapBook = true;
  this->CatherineIsFree = false;
  this->CharacterTransform = FTransform::Identity;
  this->TelescopeCodeA = -1;
  this->TelescopeCodeB = -1;
  this->TelescopeCodeC = -1;
  this->TelescopeCodeD = -1;
  this->TelescopeCodeE = -1;
  this->PrisonCodeA = -1;
  this->PrisonCodeB = -1;
  this->PrisonCodeC = -1;
  this->PrisonCodeD = -1;
  this->PrisonCodeE = -1;
  this->DomeCodeA = -1;
  this->DomeCodeB = -1;
  this->DomeCodeC = -1;
  this->DomeCodeD = -1;
  this->DomeCodeE = -1;
  this->SubPosRot = ESubPosRot::Plat_N;
  this->J_SeenCreepyGirl = false;
  this->J_WahrkElevatorPosition = 0;
  this->O_OvenIsOn = false;
  this->O_CageIsUp = true;
  this->O_TimesGehnSignaled = 0;
  this->T_NewTemple_DoorMain_Open = false;
  this->T_NewTemple_DoorSide_Open = false;
  this->T_FissurePlateau_CageLever_Closed = true;
  this->T_FissurePlateau_ChoStillPassedOut = true;
  this->S_SeenScribe = false;
  this->B_GehnHasVisited = false;
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
  vars.push_back(std::make_tuple("bool", "GehnIsTrapped"));
  vars.push_back(std::make_tuple("bool", "HaveTrapBook"));
  vars.push_back(std::make_tuple("bool", "CatherineIsFree"));
  vars.push_back(std::make_tuple("FTransform", "CharacterTransform"));
  vars.push_back(std::make_tuple("int32", "TelescopeCodeA"));
  vars.push_back(std::make_tuple("int32", "TelescopeCodeB"));
  vars.push_back(std::make_tuple("int32", "TelescopeCodeC"));
  vars.push_back(std::make_tuple("int32", "TelescopeCodeD"));
  vars.push_back(std::make_tuple("int32", "TelescopeCodeE"));
  vars.push_back(std::make_tuple("int32", "PrisonCodeA"));
  vars.push_back(std::make_tuple("int32", "PrisonCodeB"));
  vars.push_back(std::make_tuple("int32", "PrisonCodeC"));
  vars.push_back(std::make_tuple("int32", "PrisonCodeD"));
  vars.push_back(std::make_tuple("int32", "PrisonCodeE"));
  vars.push_back(std::make_tuple("int32", "DomeCodeA"));
  vars.push_back(std::make_tuple("int32", "DomeCodeB"));
  vars.push_back(std::make_tuple("int32", "DomeCodeC"));
  vars.push_back(std::make_tuple("int32", "DomeCodeD"));
  vars.push_back(std::make_tuple("int32", "DomeCodeE"));
  vars.push_back(std::make_tuple("ESubPosRot", "SubPosRot"));
  vars.push_back(std::make_tuple("bool", "J_SeenCreepyGirl"));
  vars.push_back(std::make_tuple("int32", "J_WahrkElevatorPosition"));
  vars.push_back(std::make_tuple("bool", "O_OvenIsOn"));
  vars.push_back(std::make_tuple("bool", "O_CageIsUp"));
  vars.push_back(std::make_tuple("int32", "O_TimesGehnSignaled"));
  vars.push_back(std::make_tuple("bool", "T_NewTemple_DoorMain_Open"));
  vars.push_back(std::make_tuple("bool", "T_NewTemple_DoorSide_Open"));
  vars.push_back(std::make_tuple("bool", "T_FissurePlateau_CageLever_Closed"));
  vars.push_back(std::make_tuple("bool", "T_FissurePlateau_ChoStillPassedOut"));
  vars.push_back(std::make_tuple("bool", "S_SeenScribe"));
  vars.push_back(std::make_tuple("bool", "B_GehnHasVisited"));
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
void URivenSaveGame::Set_GehnIsTrapped(bool NewVal) {
   this->GehnIsTrapped = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_GehnIsTrapped() {
   return GehnIsTrapped;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_HaveTrapBook(bool NewVal) {
   this->HaveTrapBook = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_HaveTrapBook() {
   return HaveTrapBook;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_CatherineIsFree(bool NewVal) {
   this->CatherineIsFree = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_CatherineIsFree() {
   return CatherineIsFree;
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
void URivenSaveGame::Set_TelescopeCodeA(int32 NewVal) {
   this->TelescopeCodeA = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_TelescopeCodeA() {
   return TelescopeCodeA;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_TelescopeCodeB(int32 NewVal) {
   this->TelescopeCodeB = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_TelescopeCodeB() {
   return TelescopeCodeB;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_TelescopeCodeC(int32 NewVal) {
   this->TelescopeCodeC = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_TelescopeCodeC() {
   return TelescopeCodeC;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_TelescopeCodeD(int32 NewVal) {
   this->TelescopeCodeD = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_TelescopeCodeD() {
   return TelescopeCodeD;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_TelescopeCodeE(int32 NewVal) {
   this->TelescopeCodeE = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_TelescopeCodeE() {
   return TelescopeCodeE;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_PrisonCodeA(int32 NewVal) {
   this->PrisonCodeA = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_PrisonCodeA() {
   return PrisonCodeA;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_PrisonCodeB(int32 NewVal) {
   this->PrisonCodeB = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_PrisonCodeB() {
   return PrisonCodeB;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_PrisonCodeC(int32 NewVal) {
   this->PrisonCodeC = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_PrisonCodeC() {
   return PrisonCodeC;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_PrisonCodeD(int32 NewVal) {
   this->PrisonCodeD = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_PrisonCodeD() {
   return PrisonCodeD;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_PrisonCodeE(int32 NewVal) {
   this->PrisonCodeE = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_PrisonCodeE() {
   return PrisonCodeE;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_DomeCodeA(int32 NewVal) {
   this->DomeCodeA = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_DomeCodeA() {
   return DomeCodeA;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_DomeCodeB(int32 NewVal) {
   this->DomeCodeB = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_DomeCodeB() {
   return DomeCodeB;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_DomeCodeC(int32 NewVal) {
   this->DomeCodeC = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_DomeCodeC() {
   return DomeCodeC;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_DomeCodeD(int32 NewVal) {
   this->DomeCodeD = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_DomeCodeD() {
   return DomeCodeD;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_DomeCodeE(int32 NewVal) {
   this->DomeCodeE = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_DomeCodeE() {
   return DomeCodeE;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_SubPosRot(ESubPosRot NewVal) {
   this->SubPosRot = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
ESubPosRot URivenSaveGame::Get_SubPosRot() {
   return SubPosRot;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_J_SeenCreepyGirl(bool NewVal) {
   this->J_SeenCreepyGirl = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_J_SeenCreepyGirl() {
   return J_SeenCreepyGirl;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_J_WahrkElevatorPosition(int32 NewVal) {
   this->J_WahrkElevatorPosition = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_J_WahrkElevatorPosition() {
   return J_WahrkElevatorPosition;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_O_OvenIsOn(bool NewVal) {
   this->O_OvenIsOn = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_O_OvenIsOn() {
   return O_OvenIsOn;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_O_CageIsUp(bool NewVal) {
   this->O_CageIsUp = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_O_CageIsUp() {
   return O_CageIsUp;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_O_TimesGehnSignaled(int32 NewVal) {
   this->O_TimesGehnSignaled = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_O_TimesGehnSignaled() {
   return O_TimesGehnSignaled;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_T_NewTemple_DoorMain_Open(bool NewVal) {
   this->T_NewTemple_DoorMain_Open = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_T_NewTemple_DoorMain_Open() {
   return T_NewTemple_DoorMain_Open;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_T_NewTemple_DoorSide_Open(bool NewVal) {
   this->T_NewTemple_DoorSide_Open = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_T_NewTemple_DoorSide_Open() {
   return T_NewTemple_DoorSide_Open;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_T_FissurePlateau_CageLever_Closed(bool NewVal) {
   this->T_FissurePlateau_CageLever_Closed = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_T_FissurePlateau_CageLever_Closed() {
   return T_FissurePlateau_CageLever_Closed;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_T_FissurePlateau_ChoStillPassedOut(bool NewVal) {
   this->T_FissurePlateau_ChoStillPassedOut = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_T_FissurePlateau_ChoStillPassedOut() {
   return T_FissurePlateau_ChoStillPassedOut;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_S_SeenScribe(bool NewVal) {
   this->S_SeenScribe = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_S_SeenScribe() {
   return S_SeenScribe;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_B_GehnHasVisited(bool NewVal) {
   this->B_GehnHasVisited = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_B_GehnHasVisited() {
   return B_GehnHasVisited;
}

/* [[[end]]] */
