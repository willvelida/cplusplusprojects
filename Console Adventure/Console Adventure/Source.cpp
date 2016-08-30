#include <iostream>
#include <string>

using namespace std;

struct Player
{
	string m_name;
};

void WelcomePlayer(Player& player)
{
	cout << "Welcome to Console Adventure!" << endl;
	cout << "What is your name?" << endl;

	cin >> player.m_name;
	cout << "Hello " << player.m_name << ", are you ready for the adventure of a lifetime?" << endl;
}

int main()
{
	Player player;
	WelcomePlayer(player);

	return 0;
}