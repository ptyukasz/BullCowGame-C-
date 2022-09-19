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
	FText GetGuess();
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
	void PrintIntro() {
		//constant for word length
		constexpr int32 WORD_LENGTH = 6;
		std::cout << "Welcome to Bulls and Cows.\n";
		std::cout << "Can you guess the " << WORD_LENGTH;
		std::cout << " letter isogram I'm thinking of?\n";
		std::cout << std::endl;

		return;
	}
	FText GetGuess() {
		int32 CurrentTry = BCGame.GetCurrentTry();
		// ask for user to input guess
		FText Guess = "";

		std::cout << "Try: " << CurrentTry << ":\nEnter your guess  ";
		std::getline(std::cin, Guess);
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
	void PlayGame()
	{
		BCGame.Reset();
		//instantiate a new game 
		BCGame.GetMaxTries();
		int32 MaxTries = BCGame.GetMaxTries();
		std::cout << MaxTries << std::endl;


		// loop for the number of turns asking for guesses
		// TODO change from FOR to WHILE loop once we are validating tries
		//TODO summarise game

		for (int32 count = 1; count <= MaxTries; count++)
		{
			FText Guess = GetGuess(); //TODO make loop checking valid

			//Submit valid guess to the game
			FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
			//Print number of bulls and cows
			std::cout << "Bulls =" << BullCowCount.Bulls;
			std::cout << "Cow = " << BullCowCount.Cows << std::endl;
			std::cout << std::endl;
		}

	}












