// Lost Fortune
// A personalized adventure

#include <iostream>
#include <string>

using namespace std;

int main()
{
	const int GOLD_PIECES = 900;
	int adventures, killed, survivors;
	string leader;

	// Get the information
	cout << "Welcome to Lost Fortune\n\n";
	cout << "Please enter the following for your adventure!\n";

	cout << "Enter a number: ";
	cin >> adventures;

	cout << "Enter a number, smaller than the first: ";
	cin >> killed;

	survivors = adventures - killed;

	cout << "Enter your last name: ";
	cin >> leader;

	// Tell the story
	cout << "\nA group of " << adventures << " went out for a feed. ";
	cout << "This group was lead by " << leader << ".\n";
	cout << "However, a truck came along and killed " << killed << " members of the group. ";
	cout << "In the end, only " << survivors << " survived and got something to eat.\n";
	cout << "The meal ended up costing " << GOLD_PIECES << ". Pretty cheap meal!";

	return 0;
}