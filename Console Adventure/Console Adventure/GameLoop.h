#pragma once

#include <iostream>
#include <string>

#include "Player.h"
#include "PlayerOptions.h"

using namespace std;

namespace GameLoop
{
	void WelcomePlayer(Player& player);
	void GivePlayerOptions();
	void GetPlayerInput(string& playerInput);
	PlayerOptions EvaluateInput(string& playerInput);
	bool RunGame();
}
