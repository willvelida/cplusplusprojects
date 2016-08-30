#include <iostream>
#include <string>

using namespace std;

int main()
{
	cout << "Welcome to Console Adventure!" << endl;
	cout << "What is your name?" << endl;

	string playerName;
	cin >> playerName;

	cout << "Hello " << playerName << ", are you ready for the adventure of a lifetime?" << endl;

	return 0;
}