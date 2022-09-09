#include "FBullCowGame.h"
FBullCowGame::FBullCowGame(){Reset();}

int FBullCowGame::GetCurrentTry() const { return MyMaxTries; }
int FBullCowGame::GetMaxTries() const{ return MyMaxTries; }


void FBullCowGame::Reset()
{
	constexpr  int MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;

	MyCurrentTry = 1;
	return;
}


bool FBullCowGame::CheckGuessValidity(std::string)
{
	return false;
}

bool FBullCowGame::IsGamWon() const
{
	return false;
}



