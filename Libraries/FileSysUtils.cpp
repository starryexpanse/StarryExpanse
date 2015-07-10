// Fill out your copyright notice in the Description page of Project Settings.


#include "StarryExpanse.h"
#include "FileSysUtils.h"

/* UFSDirectoryVisitor */

UFSDirectoryVisitor::UFSDirectoryVisitor(TArray<FString> *arr) 
	: arr(arr) 
{ 
}

bool UFSDirectoryVisitor::Visit(const TCHAR* FilenameOrDirectory, bool bIsDirectory) {
	if ( !bIsDirectory ) {
		FString fname = FPaths::GetBaseFilename(FilenameOrDirectory, true);
		FString ext = FPaths::GetExtension(FilenameOrDirectory, false);
		if ( ext.ToLower() == "sav" ) {
			arr->Push(fname);
		}
	}
	return true;
}

/* UFileSysUtils */


UFileSysUtils::UFileSysUtils(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{

}

TArray<FString> UFileSysUtils::ListSaveGames(uint8& ErrorCode, EFileSysOperationResult Branches) {
	auto& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();

	TArray<FString> ret;

	UFSDirectoryVisitor x (&ret);

	FString dir = FPaths::GameSavedDir() + TEXT("/SaveGames/");

	bool success = PlatformFile.IterateDirectory(*dir, x);
	if ( success ) {
		ErrorCode = 0;
		Branches = EFileSysOperationResult::Success;
		return ret;
	}

	ErrorCode = 1; /* Right now, only one error code. Might be expanded later (check if Read-Only FS, etc.) */

	Branches = EFileSysOperationResult::Error;
	TArray<FString> empty;
	empty.Push(FString(TEXT("/:: SAVEGAME LISTING ERROR ::/")));
	return empty;
}
