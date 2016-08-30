#include <iostream>
#include <string>

using namespace std;

struct Player
{
	string m_name;
};

// player choices
enum class PlayerOptions
{
	Quit,
	None
};

void WelcomePlayer(Player& player)
{
	cout << "Welcome to Console Adventure!" << endl;
	cout << "What is your name?" << endl;

	cin >> player.m_name;
	cout << "Hello " << player.m_name << ", are you ready for the adventure of a lifetime?" << endl;
}

// Gives the player options to proceed
void GivePlayerOptions()
{
	cout << "How would you like to proceed? (Enter a corresponding number" << endl;
	cout << "1: Quit" << endl;
}

// Getting player commands and store them in a string
void GetPlayerInput(string& playerInput)
{
	cin >> playerInput;
}

PlayerOptions EvaluateInput(string& playerInput)
{
	PlayerOptions chosenOption = PlayerOptions::None;

	if (playerInput.compare("1")==0)
	{
		cout << "You have chosen to Quit!" << endl;
		chosenOption = PlayerOptions::Quit;
	}
	else
	{
		cout << "Not an option, try again!" << endl;
	}

	return chosenOption;
}

bool RunGame()
{
	bool shouldEnd = false;
	GivePlayerOptions();
	string playerInput;
	GetPlayerInput(playerInput);
	shouldEnd = EvaluateInput(playerInput) == PlayerOptions::Quit;

	return !shouldEnd;
}

// You need to write the main method last?
int main()
{
	Player player;
	WelcomePlayer(player);

	bool isPlaying = true;
	while (isPlaying)
	{
		isPlaying = RunGame();
	}

	return 0;
}
