// Fill out your copyright notice in the Description page of Project Settings.

#include "StarryExpanse.h"
#include "StringUtilities.h"


FString UStringUtilities::JoinStringsWithNewlines(TArray<FString> strings) {
	FString result;
	for ( auto Itr(strings.CreateIterator()); Itr; Itr++ ) {
		result.Append(*Itr);
		if ( Itr + 1 ) {
			result.Append("\n");
		}
	}
	return result;
}