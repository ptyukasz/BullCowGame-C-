#pragma once
#include "FBullCowGame.h"

using int32 = int;
int32 FBullCowGame::GetCurrentTry() const { return MyMaxTries; }
int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }

// 
FBullCowGame::FBullCowGame(){Reset();} //constructor





void FBullCowGame::Reset() {
	constexpr  int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;
	MyCurrentTry = 1;
	const Fstring HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;
	return;
}


// recieves a VALID guess, increments turn, and returns count
FBullCowCount FBullCowGame::SubmitGuess(Fstring Guess)
{
	
	//increment the turn number
	MyCurrentTry++;
//setup a return variable
	FBullCowCount BullCowCount;
// loop through all letters in the guess
	int32 HiddenWordLength = MyHiddenWord.length();
	for (int32 i = 0; i < HiddenWordLength; i++) 
	{
		
	}
	
	//compare letters against the hidden word
 	for (int32 j = 0; j < HiddenWordLength; j++) 
	{

		if (Guess == MyHiddenWord) {
			BullCowCount.Bulls++;
		}
			else if (Guess != MyHiddenWord) {

				BullCowCount.Cows++;
			}

			else {
				BullCowCount.Cows++;
			}
			
	}
		// if they match then
	// incriment bulls if they're in the same place
				// incriment cows if not
			//compare letters against the hidden word
			//else
				//incriment cows
	return BullCowCount;
}



bool FBullCowGame::IsGamWon() const
{
	return false;
}

bool FBullCowGame::CheckGuessValidity(Fstring) const
{
	return false;
}






