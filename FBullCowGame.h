#pragma once
#include <string>


using int32 = int;
using Fstring = std::string;

struct FBullCowCount

{
	int32 Bulls = 0;
	int32 Cows = 0;
};

class FBullCowGame 

{
public:
	FBullCowGame(); //constructor
	

	int32 GetMaxTries() const;
	int32 GetCurrentTry()const;
	bool IsGamWon() const;
	bool CheckGuessValidity(Fstring) const; //TODO make a more rich return value
	FBullCowCount SubmitGuess(Fstring);
	void Reset();


private:
	// see constructor for initialization
	int32 MyCurrentTry ;
	int32 MyMaxTries ;
	Fstring MyHiddenWord;
};

   