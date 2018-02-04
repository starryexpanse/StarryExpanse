//
// Copyright, 59 Volt Entertainment, all rights reserved.
//

#include "SaveGame/ESaveGameField.h"
#include "StarryExpanse.h"

FString GetSaveGameFieldAsString(ESaveGameField field) {
  const UEnum *EnumPtr =
      FindObject<UEnum>(ANY_PACKAGE, TEXT("ESaveGameField"), true);
  if (!EnumPtr)
    return FString("Invalid");

  return EnumPtr->GetNameByValue((int64)field).ToString();
}
