#pragma once
#include <string>
// notice me
class FBullCowGame {
public:
	FBullCowGame(); //Constructor
	void Reset(); // TODO more rich value;
	int GetMaxTries() const;
	int GetCurrentTry ()const;
	bool IsGamWon() const;
	
	void Reset();
	bool CheckGuessValidity(std::string); //TODO make a more rich return value;
	//provide a method for counting bulls & cows, and increasing turn #




private:
	// see constructor for initialization
	int MyCurrentTry;
	int MyMaxTries;

};
		

