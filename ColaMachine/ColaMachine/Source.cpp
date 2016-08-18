#include <iostream>
#include <string>

using namespace std;

int main()
{
	cout << "Hi there! Welcome to the Cola Machine!" << endl;
	int userChoice;
	cout << "Please enter your choice of Cola Brand (1 for Coca-Cola, 2 for Pepsi, 3 for Dr Pepper, 4 for Mountain Dew, 5 for Tesco brand)" << endl;
	cin >> userChoice;
	switch (userChoice)
	{
	case 1:
		cout << "You have selected Coca-Cola, enjoy!" << endl;
		break;
	case 2:
		cout << "You have selected Pepsi, enjoy!" << endl;
		break;
	case 3:
		cout << "You have selected Dr Pepper, enjoy!" << endl;
		break;
	case 4:
		cout << "You have selected Mountain Dew, enjoy!" << endl;
		break;
	case 5:
		cout << "You have select Tesco brand, enjoy!" << endl;
		break;
	default:
		cout << "Invalid choice, here's your money back!" << endl;
		break;
	}
	return 0;
}