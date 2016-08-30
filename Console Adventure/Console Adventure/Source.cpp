#include <iostream>
#include <string>

#include "Player.h"
#include "GameLoop.h"
#include "PlayerOptions.h"

using namespace std;

// You need to write the main method last?
int main()
{
	Player player;
	// We need to reference GameLoop to make this work
	GameLoop::WelcomePlayer(player);

	bool isPlaying = true;
	while (isPlaying)
	{
		isPlaying = GameLoop::RunGame();
	}

	return 0;
}
