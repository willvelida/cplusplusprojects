#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

// Prototypes of the methods
void PrintIntro();
FText GetValidGuess();
void PlayGame();
bool AskToPlayAgain();
void PrintGameSummary();

FBullCowGame BCGame; // Instiantiate a new game

// Entry point for the application
int main()
{
	bool bWantsToPlayAgain = false;
	do
	{
		PrintIntro();
		PlayGame();
		// Add a game summary
		bWantsToPlayAgain = AskToPlayAgain();
	} 
	while (bWantsToPlayAgain);
	return 0; // exit the application
}

void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();

	// loop for the number of turns asking for guesses until win conditions met
	// TODO: change from FOR to WHILE
	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries)
	{
		FText Guess = GetValidGuess();
		// Submit valid guess to game
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
		std::cout << "Bulls = " << BullCowCount.Bulls << std::endl;
		std::cout << "Cows = " << BullCowCount.Cows << std::endl;
		std::cout << std::endl;
	}

	PrintGameSummary();
}

// Definition of PrintIntro
void PrintIntro()
{
	// This is constant at compile time
	std::cout << "Welcome to BullCow Game! A fun word game\n";
	std::cout << "Can you think of the " << BCGame.GetHiddenWordLength() << " letter word that I am thinking of?\n";

	return;
}

// Defintion of GetGuess
FText GetValidGuess()
{
	FText Guess = "";
	EWordStatus Status = EWordStatus::Invalid_Status;
	do
	{
		int32 CurrentTry = BCGame.GetCurrentTry();
		// get a guess from the user
		std::cout << "Try " << CurrentTry << " of " << BCGame.GetMaxTries() << " Enter your guess: ";
		
		std::getline(std::cin, Guess);

		Status = BCGame.CheckGuessValid(Guess);
		switch (Status)
		{
		case EWordStatus::Wrong_Length:
			std::cout << "Please a enter a " << BCGame.GetHiddenWordLength() << " letter word.\n\n";
			break;
		case EWordStatus::Not_Lowercase:
			std::cout << "Please make sure your word is lower case\n\n";
			break;
		case EWordStatus::Not_Isogram:
			std::cout << "Please ensure that your word is an isogram\n\n";
			break;
		default:
			// assuming the guess is valid
			break;
		}
		std::cout << std::endl;
	} while (Status != EWordStatus::OK); // Keep looping until we get no errors
	
	return Guess;
	
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again with the same hidden word? (y/n)";
	FText Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y' || Response[0] == 'Y');
}

void PrintGameSummary()
{
	if (BCGame.IsGameWon())
	{
		std::cout << "Well done, you won!\n";
	}
	else
	{
		std::cout << "Better luck next time!\n";
	}
}
