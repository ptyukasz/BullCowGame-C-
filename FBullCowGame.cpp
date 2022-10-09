#pragma once
#include "FBullCowGame.h"

using int32 = int;



// 
FBullCowGame::FBullCowGame(){Reset();} //constructor
int32 FBullCowGame::GetCurrentTry() const { return MyMaxTries; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length();}

int32 FBullCowGame::GetMaxTries() const
{
	return 8;
}

void FBullCowGame::Reset() {
	constexpr  int32 MAX_TRIES =5;
	MyMaxTries = MAX_TRIES;
	MyCurrentTry = 1;
	const Fstring HIDDEN_WORD = "plane";
	MyHiddenWord = HIDDEN_WORD;
	return;
}


// recieves a VALID guess, increments turn, and returns count
FBullCowCount FBullCowGame::SubmitGuess(Fstring Guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;
	int32 HiddenWordLength = MyHiddenWord.length();

	for (int32 MHWChar = 0; MHWChar < HiddenWordLength; MHWChar++) 
	{
		
	
	
	//compare letters against the hidden word
 			for (int32 GChar = 0; GChar < HiddenWordLength; GChar++) 
			{

				if (Guess[GChar] == MyHiddenWord[MHWChar])
				{
					if (MHWChar == GChar) 
					{
						BullCowCount.Bulls++;
					}
					else 
					{
						BullCowCount.Cows++;
					}
				}
					
			}
	}
	return BullCowCount;

}	



bool FBullCowGame::IsGamWon() const
{
	return false;
}



EGuessStatus FBullCowGame::CheckGuessValidity(Fstring Guess) const
{
	if (false) 
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (false) 
	{
		return EGuessStatus::Not_Lowercase;
	}
	else if (Guess.length() != GetHiddenWordLength())
	{
		return EGuessStatus::Wrong_Length;
	}

	//if the guess isn't an isogram
	// if the guess isn't the right word length
	// if the guess isn't all lowercase
	else
	{
		return EGuessStatus::OK;
	}
}






