// Guess my number
// Classic Number Guessing Game
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	// seed random number generator
	srand(static_cast<unsigned int>(time(0)));

	// random number between 1 and 100
	int secretNumber = rand() % 100 + 1;
	int tries = 0;
	int guess;

	cout << "\tWelcome to Guess My Number Game!\n\n";

	// Game Loop
	do
	{
		cout << "Enter a guess: ";
		cin >> guess;
		++tries;

		if (guess > secretNumber)
		{
			cout << "Too high!\n\n";
		}
		else if (guess < secretNumber)
		{
			cout << "Too Low!\n\n";
		}
		else
		{
			cout << "\nThat's the number! You took " << tries << " attempts to get it!\n";
		}
	} while (guess != secretNumber);

	return 0;
}