#pragma once
#include<iostream>	
#include <string>
#include "FBullCowGame.h"



//variables and constants




//prototype functions
using FText = std::string;
using int32 = int;
	void PrintIntro();
	void PlayGame();
	FText GetValidGuess();
	bool AskToPlayAgain();

	FBullCowGame BCGame; //instance

	
	//entry point
	int main()
{
	bool bPlayAgain = false;
	
		do
		{
			PrintIntro();
			PlayGame();
			bPlayAgain = AskToPlayAgain();
			//TODO add a game summary
		}
		while (bPlayAgain);

	

	return 0; // exit the application
}

	//functions 
	void PrintIntro()
	{
		//constant for word length
		constexpr int32 WORD_LENGTH = 6;
		std::cout << "Welcome to Bulls and Cows.\n";
		std::cout << "Can you guess the " << WORD_LENGTH;
		std::cout << " letter isogram I'm thinking of?\n";
		std::cout << std::endl;

		return;
	}
	//loop continually until the user gives a valid guess
	FText GetValidGuess()
	{
		FText Guess = "";
		
		EGuessStatus Status = EGuessStatus::Invalid_Status;
		do {
			// get a guess from the player
			int32 CurrentTry = BCGame.GetCurrentTry();
			std::cout << "Try " << CurrentTry << " of " << BCGame.GetMaxTries();
			std::cout << ". Enter your guess: ";
			std::getline(std::cin, Guess);

			// check status and give feedback
			Status = BCGame.CheckGuessValidity(Guess);
			switch (Status) {
			case EGuessStatus::Wrong_Length:
				std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n\n";
				break;
			case EGuessStatus::Not_Isogram:				
				std::cout << "Please enter a word without repeating letters.\n\n";
				break;
			case EGuessStatus::Not_Lowercase:
				std::cout << "Please enter all lowercase letters.\n\n";
				break;
		
			default:
				// assume the guess is valid
				break;
			}
		} while (Status != EGuessStatus::OK); // keep looping until we get no errors
		return Guess;
	}

	bool AskToPlayAgain()
	{
		
		
		std::cout << "Do you want to play again (y/n?): ";
		FText Response = "";
		std::getline(std::cin, Response);
		std::cout << std::endl;
		return (Response[0] == 'y' || (Response[0] == 'Y'));
		
	}
		

//keep looping until we get no errors
void PlayGame()
		{
			BCGame.Reset();
			//instantiate a new game 
			int32 MaxTries = BCGame.GetMaxTries();
			std::cout << MaxTries << std::endl;
			// loop asking for guesses while the game 
			// is NOT won and ther eare still tries remaining

			while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <=MaxTries)
			{
				FText Guess = GetValidGuess(); 

				//submit valid guess to the game
				FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
				std::cout << "Bulls= " << BullCowCount.Bulls;
				std::cout << "Cow= " << BullCowCount.Cows << "\n\n";
				if (BCGame.IsGameWon() == true)
				{
					AskToPlayAgain();
				}
				else 
				{
					return;	
				}
				
			}
		}

	