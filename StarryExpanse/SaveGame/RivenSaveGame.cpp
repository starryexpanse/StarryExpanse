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
  case ESaveGameField::A_LoadGroupsMarionettistBooks:
    return this->A_LoadGroupsMarionettistBooks;
  case ESaveGameField::A_LoadGroupsMarionettistBooks:
    return this->A_LoadGroupsMarionettistBooks;
  case ESaveGameField::A_LoadGroupsMarionettistBooks:
    return this->A_LoadGroupsMarionettistBooks;
  case ESaveGameField::A_LoadGroupsMarionettistBooks:
    return this->A_LoadGroupsMarionettistBooks;
  case ESaveGameField::B_ShoreBoilerExterior:
    return this->B_ShoreBoilerExterior;
  case ESaveGameField::B_ShoreBoilerExterior:
    return this->B_ShoreBoilerExterior;
  case ESaveGameField::B_ShoreBoilerExterior:
    return this->B_ShoreBoilerExterior;
  case ESaveGameField::B_ShoreBoilerExteriorBoilerInterior:
    return this->B_ShoreBoilerExteriorBoilerInterior;
  case ESaveGameField::B_ShoreBoilerExteriorBoilerInterior:
    return this->B_ShoreBoilerExteriorBoilerInterior;
  case ESaveGameField::J_SubmarineTunnelBranch:
    return this->J_SubmarineTunnelBranch;
  case ESaveGameField::O_Stove:
    return this->O_Stove;
  case ESaveGameField::O_StoveCageButtonCageLever:
    return this->O_StoveCageButtonCageLever;
  case ESaveGameField::T_FissurePlateau_CageLever:
    return this->T_FissurePlateau_CageLever;
  case ESaveGameField::T_FissurePlateau_CageLever_Cho:
    return this->T_FissurePlateau_CageLever_Cho;
  case ESaveGameField::T_NewTemple_DoorMain:
    return this->T_NewTemple_DoorMain;
  case ESaveGameField::T_NewTemple_DoorMain_DoorSide:
    return this->T_NewTemple_DoorMain_DoorSide;
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
  case ESaveGameField::A_LoadGroupsMarionettistBooks:
    this->A_LoadGroupsMarionettistBooks = nextVal;
    break;
  case ESaveGameField::A_LoadGroupsMarionettistBooks:
    this->A_LoadGroupsMarionettistBooks = nextVal;
    break;
  case ESaveGameField::A_LoadGroupsMarionettistBooks:
    this->A_LoadGroupsMarionettistBooks = nextVal;
    break;
  case ESaveGameField::A_LoadGroupsMarionettistBooks:
    this->A_LoadGroupsMarionettistBooks = nextVal;
    break;
  case ESaveGameField::B_ShoreBoilerExterior:
    this->B_ShoreBoilerExterior = nextVal;
    break;
  case ESaveGameField::B_ShoreBoilerExterior:
    this->B_ShoreBoilerExterior = nextVal;
    break;
  case ESaveGameField::B_ShoreBoilerExterior:
    this->B_ShoreBoilerExterior = nextVal;
    break;
  case ESaveGameField::B_ShoreBoilerExteriorBoilerInterior:
    this->B_ShoreBoilerExteriorBoilerInterior = nextVal;
    break;
  case ESaveGameField::B_ShoreBoilerExteriorBoilerInterior:
    this->B_ShoreBoilerExteriorBoilerInterior = nextVal;
    break;
  case ESaveGameField::J_SubmarineTunnelBranch:
    this->J_SubmarineTunnelBranch = nextVal;
    break;
  case ESaveGameField::O_Stove:
    this->O_Stove = nextVal;
    break;
  case ESaveGameField::O_StoveCageButtonCageLever:
    this->O_StoveCageButtonCageLever = nextVal;
    break;
  case ESaveGameField::T_FissurePlateau_CageLever:
    this->T_FissurePlateau_CageLever = nextVal;
    break;
  case ESaveGameField::T_FissurePlateau_CageLever_Cho:
    this->T_FissurePlateau_CageLever_Cho = nextVal;
    break;
  case ESaveGameField::T_NewTemple_DoorMain:
    this->T_NewTemple_DoorMain = nextVal;
    break;
  case ESaveGameField::T_NewTemple_DoorMain_DoorSide:
    this->T_NewTemple_DoorMain_DoorSide = nextVal;
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
  this->A_LoadGroups = ELoadGroups::TFissureDistrict;
  this->A_LoadGroupsMarionettist = EMarionettist::NoMarionettist;
  this->A_LoadGroupsMarionettistBooks = false;
  this->A_LoadGroupsMarionettistBooks = false;
  this->A_LoadGroupsMarionettistBooks = true;
  this->A_LoadGroupsMarionettistBooks = false;
  this->A_LoadGroupsMarionettistBooksRivenCharacter = FTransform::Identity;
  this->B_Shore = 0;
  this->B_ShoreBoilerExterior = false;
  this->B_ShoreBoilerExterior = false;
  this->B_ShoreBoilerExterior = false;
  this->B_ShoreBoilerExteriorBoilerInterior = true;
  this->B_ShoreBoilerExteriorBoilerInterior = false;
  this->J_Submarine = ESubPosRot::Plat_N;
  this->J_SubmarineTunnelBranch = false;
  this->J_SubmarineTunnelBranchIdolInterior = 1;
  this->O_Stove = false;
  this->O_StoveCageButton = 0;
  this->O_StoveCageButtonCageLever = false;
  this->S_Dome = -1;
  this->S_Dome = -1;
  this->S_Dome = -1;
  this->S_Dome = -1;
  this->S_Dome = -1;
  this->T_FissurePlateau_CageLever = true;
  this->T_FissurePlateau_CageLever_Cho = true;
  this->T_FissurePlateau_CageLever_Cho_Telescope = -1;
  this->T_FissurePlateau_CageLever_Cho_Telescope = -1;
  this->T_FissurePlateau_CageLever_Cho_Telescope = -1;
  this->T_FissurePlateau_CageLever_Cho_Telescope = -1;
  this->T_FissurePlateau_CageLever_Cho_Telescope = -1;
  this->T_NewTemple_DoorMain = false;
  this->T_NewTemple_DoorMain_DoorSide = false;
  this->P_Exterior_Lock = -1;
  this->P_Exterior_Lock = -1;
  this->P_Exterior_Lock = -1;
  this->P_Exterior_Lock = -1;
  this->P_Exterior_Lock = -1;
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
  vars.push_back(std::make_tuple("ELoadGroups", "A_LoadGroups"));
  vars.push_back(std::make_tuple("EMarionettist", "A_LoadGroupsMarionettist"));
  vars.push_back(std::make_tuple("bool", "A_LoadGroupsMarionettistBooks"));
  vars.push_back(std::make_tuple("bool", "A_LoadGroupsMarionettistBooks"));
  vars.push_back(std::make_tuple("bool", "A_LoadGroupsMarionettistBooks"));
  vars.push_back(std::make_tuple("bool", "A_LoadGroupsMarionettistBooks"));
  vars.push_back(std::make_tuple("FTransform", "A_LoadGroupsMarionettistBooksRivenCharacter"));
  vars.push_back(std::make_tuple("int32", "B_Shore"));
  vars.push_back(std::make_tuple("bool", "B_ShoreBoilerExterior"));
  vars.push_back(std::make_tuple("bool", "B_ShoreBoilerExterior"));
  vars.push_back(std::make_tuple("bool", "B_ShoreBoilerExterior"));
  vars.push_back(std::make_tuple("bool", "B_ShoreBoilerExteriorBoilerInterior"));
  vars.push_back(std::make_tuple("bool", "B_ShoreBoilerExteriorBoilerInterior"));
  vars.push_back(std::make_tuple("ESubPosRot", "J_Submarine"));
  vars.push_back(std::make_tuple("bool", "J_SubmarineTunnelBranch"));
  vars.push_back(std::make_tuple("int32", "J_SubmarineTunnelBranchIdolInterior"));
  vars.push_back(std::make_tuple("bool", "O_Stove"));
  vars.push_back(std::make_tuple("int32", "O_StoveCageButton"));
  vars.push_back(std::make_tuple("bool", "O_StoveCageButtonCageLever"));
  vars.push_back(std::make_tuple("int32", "S_Dome"));
  vars.push_back(std::make_tuple("int32", "S_Dome"));
  vars.push_back(std::make_tuple("int32", "S_Dome"));
  vars.push_back(std::make_tuple("int32", "S_Dome"));
  vars.push_back(std::make_tuple("int32", "S_Dome"));
  vars.push_back(std::make_tuple("bool", "T_FissurePlateau_CageLever"));
  vars.push_back(std::make_tuple("bool", "T_FissurePlateau_CageLever_Cho"));
  vars.push_back(std::make_tuple("int32", "T_FissurePlateau_CageLever_Cho_Telescope"));
  vars.push_back(std::make_tuple("int32", "T_FissurePlateau_CageLever_Cho_Telescope"));
  vars.push_back(std::make_tuple("int32", "T_FissurePlateau_CageLever_Cho_Telescope"));
  vars.push_back(std::make_tuple("int32", "T_FissurePlateau_CageLever_Cho_Telescope"));
  vars.push_back(std::make_tuple("int32", "T_FissurePlateau_CageLever_Cho_Telescope"));
  vars.push_back(std::make_tuple("bool", "T_NewTemple_DoorMain"));
  vars.push_back(std::make_tuple("bool", "T_NewTemple_DoorMain_DoorSide"));
  vars.push_back(std::make_tuple("int32", "P_Exterior_Lock"));
  vars.push_back(std::make_tuple("int32", "P_Exterior_Lock"));
  vars.push_back(std::make_tuple("int32", "P_Exterior_Lock"));
  vars.push_back(std::make_tuple("int32", "P_Exterior_Lock"));
  vars.push_back(std::make_tuple("int32", "P_Exterior_Lock"));
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
void URivenSaveGame::Set_A_LoadGroups(ELoadGroups NewVal) {
   this->A_LoadGroups = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
ELoadGroups URivenSaveGame::Get_A_LoadGroups() {
   return A_LoadGroups;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_A_LoadGroupsMarionettist(EMarionettist NewVal) {
   this->A_LoadGroupsMarionettist = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
EMarionettist URivenSaveGame::Get_A_LoadGroupsMarionettist() {
   return A_LoadGroupsMarionettist;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_A_LoadGroupsMarionettistBooks(bool NewVal) {
   this->A_LoadGroupsMarionettistBooks = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_A_LoadGroupsMarionettistBooks() {
   return A_LoadGroupsMarionettistBooks;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_A_LoadGroupsMarionettistBooks(bool NewVal) {
   this->A_LoadGroupsMarionettistBooks = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_A_LoadGroupsMarionettistBooks() {
   return A_LoadGroupsMarionettistBooks;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_A_LoadGroupsMarionettistBooks(bool NewVal) {
   this->A_LoadGroupsMarionettistBooks = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_A_LoadGroupsMarionettistBooks() {
   return A_LoadGroupsMarionettistBooks;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_A_LoadGroupsMarionettistBooks(bool NewVal) {
   this->A_LoadGroupsMarionettistBooks = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_A_LoadGroupsMarionettistBooks() {
   return A_LoadGroupsMarionettistBooks;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_A_LoadGroupsMarionettistBooksRivenCharacter(FTransform NewVal) {
   this->A_LoadGroupsMarionettistBooksRivenCharacter = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
FTransform URivenSaveGame::Get_A_LoadGroupsMarionettistBooksRivenCharacter() {
   return A_LoadGroupsMarionettistBooksRivenCharacter;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_B_Shore(int32 NewVal) {
   this->B_Shore = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_B_Shore() {
   return B_Shore;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_B_ShoreBoilerExterior(bool NewVal) {
   this->B_ShoreBoilerExterior = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_B_ShoreBoilerExterior() {
   return B_ShoreBoilerExterior;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_B_ShoreBoilerExterior(bool NewVal) {
   this->B_ShoreBoilerExterior = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_B_ShoreBoilerExterior() {
   return B_ShoreBoilerExterior;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_B_ShoreBoilerExterior(bool NewVal) {
   this->B_ShoreBoilerExterior = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_B_ShoreBoilerExterior() {
   return B_ShoreBoilerExterior;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_B_ShoreBoilerExteriorBoilerInterior(bool NewVal) {
   this->B_ShoreBoilerExteriorBoilerInterior = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_B_ShoreBoilerExteriorBoilerInterior() {
   return B_ShoreBoilerExteriorBoilerInterior;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_B_ShoreBoilerExteriorBoilerInterior(bool NewVal) {
   this->B_ShoreBoilerExteriorBoilerInterior = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_B_ShoreBoilerExteriorBoilerInterior() {
   return B_ShoreBoilerExteriorBoilerInterior;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_J_Submarine(ESubPosRot NewVal) {
   this->J_Submarine = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
ESubPosRot URivenSaveGame::Get_J_Submarine() {
   return J_Submarine;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_J_SubmarineTunnelBranch(bool NewVal) {
   this->J_SubmarineTunnelBranch = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_J_SubmarineTunnelBranch() {
   return J_SubmarineTunnelBranch;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_J_SubmarineTunnelBranchIdolInterior(int32 NewVal) {
   this->J_SubmarineTunnelBranchIdolInterior = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_J_SubmarineTunnelBranchIdolInterior() {
   return J_SubmarineTunnelBranchIdolInterior;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_O_Stove(bool NewVal) {
   this->O_Stove = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_O_Stove() {
   return O_Stove;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_O_StoveCageButton(int32 NewVal) {
   this->O_StoveCageButton = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_O_StoveCageButton() {
   return O_StoveCageButton;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_O_StoveCageButtonCageLever(bool NewVal) {
   this->O_StoveCageButtonCageLever = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_O_StoveCageButtonCageLever() {
   return O_StoveCageButtonCageLever;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_S_Dome(int32 NewVal) {
   this->S_Dome = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_S_Dome() {
   return S_Dome;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_S_Dome(int32 NewVal) {
   this->S_Dome = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_S_Dome() {
   return S_Dome;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_S_Dome(int32 NewVal) {
   this->S_Dome = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_S_Dome() {
   return S_Dome;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_S_Dome(int32 NewVal) {
   this->S_Dome = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_S_Dome() {
   return S_Dome;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_S_Dome(int32 NewVal) {
   this->S_Dome = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_S_Dome() {
   return S_Dome;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_T_FissurePlateau_CageLever(bool NewVal) {
   this->T_FissurePlateau_CageLever = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_T_FissurePlateau_CageLever() {
   return T_FissurePlateau_CageLever;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_T_FissurePlateau_CageLever_Cho(bool NewVal) {
   this->T_FissurePlateau_CageLever_Cho = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_T_FissurePlateau_CageLever_Cho() {
   return T_FissurePlateau_CageLever_Cho;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_T_FissurePlateau_CageLever_Cho_Telescope(int32 NewVal) {
   this->T_FissurePlateau_CageLever_Cho_Telescope = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_T_FissurePlateau_CageLever_Cho_Telescope() {
   return T_FissurePlateau_CageLever_Cho_Telescope;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_T_FissurePlateau_CageLever_Cho_Telescope(int32 NewVal) {
   this->T_FissurePlateau_CageLever_Cho_Telescope = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_T_FissurePlateau_CageLever_Cho_Telescope() {
   return T_FissurePlateau_CageLever_Cho_Telescope;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_T_FissurePlateau_CageLever_Cho_Telescope(int32 NewVal) {
   this->T_FissurePlateau_CageLever_Cho_Telescope = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_T_FissurePlateau_CageLever_Cho_Telescope() {
   return T_FissurePlateau_CageLever_Cho_Telescope;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_T_FissurePlateau_CageLever_Cho_Telescope(int32 NewVal) {
   this->T_FissurePlateau_CageLever_Cho_Telescope = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_T_FissurePlateau_CageLever_Cho_Telescope() {
   return T_FissurePlateau_CageLever_Cho_Telescope;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_T_FissurePlateau_CageLever_Cho_Telescope(int32 NewVal) {
   this->T_FissurePlateau_CageLever_Cho_Telescope = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_T_FissurePlateau_CageLever_Cho_Telescope() {
   return T_FissurePlateau_CageLever_Cho_Telescope;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_T_NewTemple_DoorMain(bool NewVal) {
   this->T_NewTemple_DoorMain = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_T_NewTemple_DoorMain() {
   return T_NewTemple_DoorMain;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_T_NewTemple_DoorMain_DoorSide(bool NewVal) {
   this->T_NewTemple_DoorMain_DoorSide = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
bool URivenSaveGame::Get_T_NewTemple_DoorMain_DoorSide() {
   return T_NewTemple_DoorMain_DoorSide;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_P_Exterior_Lock(int32 NewVal) {
   this->P_Exterior_Lock = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_P_Exterior_Lock() {
   return P_Exterior_Lock;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_P_Exterior_Lock(int32 NewVal) {
   this->P_Exterior_Lock = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_P_Exterior_Lock() {
   return P_Exterior_Lock;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_P_Exterior_Lock(int32 NewVal) {
   this->P_Exterior_Lock = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_P_Exterior_Lock() {
   return P_Exterior_Lock;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_P_Exterior_Lock(int32 NewVal) {
   this->P_Exterior_Lock = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_P_Exterior_Lock() {
   return P_Exterior_Lock;
}

UFUNCTION(BlueprintCallable, Category = SaveGame)
void URivenSaveGame::Set_P_Exterior_Lock(int32 NewVal) {
   this->P_Exterior_Lock = NewVal;
}


UFUNCTION(BlueprintCallable, Category = SaveGame)
int32 URivenSaveGame::Get_P_Exterior_Lock() {
   return P_Exterior_Lock;
}

/* [[[end]]] */
