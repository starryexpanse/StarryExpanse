// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "GenericPlatformFile.h"
#include "FileSysUtils.generated.h"


UENUM(BlueprintType)
enum class EFileSysOperationResult : uint8
{
	Success,
	Error
};

/**
 * 
 */
UCLASS()
class STARRYEXPANSE_API UFileSysUtils : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

		UFUNCTION(BlueprintCallable, Category="FileSystem", Meta = ( ExpandEnumAsExecs = "Branches" ))
		static TArray<FString> ListSaveGames(uint8& ErrorCode, EFileSysOperationResult Branches);
};

class UFSDirectoryVisitor : public IPlatformFile::FDirectoryVisitor {
	private:
		TArray<FString> *arr;
	public:
		UFSDirectoryVisitor(TArray<FString> *arr);
		virtual bool Visit(const TCHAR* FilenameOrDirectory, bool bIsDirectory);
};
