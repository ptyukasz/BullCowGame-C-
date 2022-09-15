#pragma once
#include <string>
using Fstring = std::string;
using int32 = int;
struct BullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

class FBullCowGame 

{
public:
	FBullCowGame();
	void Reset(); // TODO more rich value;
	int32 GetMaxTries() const;
	int32 GetCurrentTry()const;
	bool IsGamWon() const;
	bool CheckGuessValidity(Fstring); //TODO make a more rich return value
	BullCowCount SubmitGuess(Fstring);

private:
	// see constructor for initialization
	int32 MyCurrentTry =1;
	int32 MyMaxTries =5;
};
		
