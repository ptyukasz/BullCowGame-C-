
#include<iostream>	
#include <string>
#include "FBullCowGame.h"
#include "FBullCowGame.cpp"


//variables and constants




//prototype functions
	void PrintIntro();
	void PlayGame();
	std::string GetGuess();
	bool AskToPlayAgain();
	FBullCowGame BCGame;
//main 
	int main()
{// intro text with WORD_LENGTH constant
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
	constexpr int WORD_LENGTH = 9;
	std::cout << "Welcome to Bulls and Cows.\n";
	std::cout << "Can you guess the " << WORD_LENGTH;
	std::cout << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;
	
return;
}
std::string GetGuess() {
	int CurrentTry = BCGame.GetCurrentTry();
	// ask for user to input guess
		std::string Guess = "";
		std::cout << "Try: "<<CurrentTry<< ":\nEnter your guess  ";
		std::getline(std::cin, Guess);
		return Guess;
}

bool AskToPlayAgain()
{   
	
	std::cout << "Do you want to play again (y/n?): ";
	std::string Response = "";
	std::getline(std::cin, Response);
	std::cout << std::endl;
	return (Response[0] == 'y' || (Response[0]=='Y'));
}
void PlayGame()
{
	FBullCowGame BCGame; //instantiate a new game 
	int MaxTries = BCGame.GetMaxTries();

	
	// loop for the number of turns asking for guesses
	// TODO change from FOR to WHILE loop once we are validating tries
	//TODO summarise game

	for (int count = 1; count <= MaxTries; count++)
	{
		std::string Guess = GetGuess(); //TODO make loop checking valid

		//Submit valid guess to the game
		//Print number of bulls and cows
		//
		std::cout << "Your guess was: " << Guess << std::endl;
		std::cout << std::endl;
	}
	
}





