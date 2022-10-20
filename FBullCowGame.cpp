#pragma once
#include "FBullCowGame.h"
#include <map>
#define TMap std::map

using int32 = int;



// 
FBullCowGame::FBullCowGame(){Reset();} //constructor
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length();}
bool FBullCowGame::IsGameWon() const {return bGameIsWon;}
bool FBullCowGame::IsIsogram() { return true; }

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
	bGameIsWon = false;
	return;
}


	


// recieves a VALID guess, increments turn, and returns count
FBullCowCount FBullCowGame::SubmitValidGuess(Fstring Guess)
{
	MyCurrentTry++;
	bGameIsWon=false;

	FBullCowCount BullCowCount;
	int32 WordLength = MyHiddenWord.length();
	//compare letters against the guess
	for (int32 MHWChar = 0; MHWChar < WordLength; MHWChar++) 
	{
		//compare letters against the guess
		for (int32 GChar = 0; GChar < WordLength; GChar++)
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
		if (BullCowCount.Bulls == WordLength) 
		{
			bGameIsWon = true;
		}
		else
		{
			bGameIsWon = false;
		}

	}
return BullCowCount;
}	




bool FBullCowGame::GameIsWon() const
{
	

	return false;
}




EGuessStatus FBullCowGame::CheckGuessValidity(Fstring Guess) const
{

	
		
	if (!IsIsogram(Guess)) 
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

bool FBullCowGame::IsIsogram(Fstring Word) const
{
	// treat 0 and 1 letter words as isograms
	if (Word.length() <= 1) { return true; }

	TMap<char, bool> LetterSceen;
	for (auto Letter : Word)
	{
		Letter = tolower(Letter); //handle mixed case
		if (LetterSceen[Letter])
		{
			return false;
		}
		else
		{
			LetterSceen[Letter] = true;
		}
	}
	return true; // for example where "/0" entered

}

bool FBullCowGame::IsLowercase(Fstring Word)const
{
	for (auto letter : Word)
	{
		for (auto Letter : Word)
		{
			if (!islower(Letter))// is not a lowercase letter
			{
				return false;
			}


		}
	}	return true;
}


	





