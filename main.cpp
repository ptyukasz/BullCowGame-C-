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

		EGuessStatus Status = EGuessStatus::Invalid_Status;
	
		do
		{
			int32 CurrentTry = BCGame.GetCurrentTry();
			std::cout << "Try: " << CurrentTry << ":\nEnter your guess  ";
			FText Guess = "";
			std::getline(std::cin, Guess);
			// ask for user to input guess

			Status = BCGame.CheckGuessValidity(Guess);
			switch (Status)
			{
			case EGuessStatus::Wrong_Length:
				std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word. \n";
				break;
			case EGuessStatus::Not_Isogram:
				std::cout << "please enter an isogram \n";
				break;
			case EGuessStatus::Not_Lowercase:
				std::cout << "only enter lowercase letters\n";
				break;
			case EGuessStatus::OK:
				std::cout << "Valid Entry\n";
				break;
			default:
				return Guess;
			}
			std::cout << std::endl;
		} while (Status!= EGuessStatus::OK); //keep looping until we get no errors
	}


			void PlayGame()
		{
			BCGame.Reset();
			//instantiate a new game 
			int32 MaxTries = BCGame.GetMaxTries();
			std::cout << MaxTries << std::endl;

			for (int32 count = 1; count <= MaxTries; count++)
			{
				FText Guess = GetValidGuess(); //TODO make loop checking valid

				//Submit valid guess to the game
				FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
				std::cout << "Bulls = " << BullCowCount.Bulls;
				std::cout << "Cow = " << BullCowCount.Cows << "\n\n";
			}
		}
		bool AskToPlayAgain()
		{

			std::cout << "Do you want to play again (y/n?): ";
			FText Response = "";
			std::getline(std::cin, Response);
			std::cout << std::endl;
			return (Response[0] == 'y' || (Response[0] == 'Y'));
		}