#pragma once
#include <string>

using FString = std::string;
using int32 = int;

struct FBullCowCount {
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EWordStatus
{
	Invalid_Status,
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase
};


//enum class EResetStatus 
//{
//	No_Hidden_Word,
//	OK
//};

class FBullCowGame {
public:
	FBullCowGame(); // constructor
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;

	bool IsGameWon() const;
	EWordStatus CheckGuessValid(FString) const;

	void Reset(); // TODO Make return value
	FBullCowCount SubmitValidGuess(FString);

	// Ignore this for now
private:
	int32 MyCurrentTry;
	FString MyHiddenWord;
	bool bGameIsWon;
	bool IsIsogram(FString) const;
	bool IsLowerCase(FString) const;
};