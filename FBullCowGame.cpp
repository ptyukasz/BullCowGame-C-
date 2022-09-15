#include "FBullCowGame.h"
using int32 = int;
int32 FBullCowGame::GetCurrentTry() const { return MyMaxTries; }
int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }

int FBullCowGame::GetCurrentTry() const { return MyMaxTries; }
int FBullCowGame::GetMaxTries() const{ return MyMaxTries; }





bool FBullCowGame::CheckGuessValidity(std::string)
{
	return false;
}

bool FBullCowGame::IsGamWon() const
{
	return false;
}



