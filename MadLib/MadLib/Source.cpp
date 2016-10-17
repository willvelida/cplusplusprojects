// Mad Lib
// Creates a story based on user input

#include <iostream>
#include <string>

using namespace std;

string askText(string prompt);
int askNumber(string prompt);
void tellStory(string name, string noun, int number, string bodyPart, string verb);

int main()
{
	cout << "Welcome to Mad Lib.\n\n";
	cout << "Answer the questions to tell your story!\n";

	string name = askText("What is your name?: ");
	string noun = askText("Enter a plural noun: ");
	int number = askNumber("What's your lucky number?: ");
	string bodyPart = askText("Enter a body part: ");
	string verb = askText("Enter a verb: ");
	tellStory(name, noun, number, bodyPart, verb);

	return 0;
}

string askText(string prompt)
{
	string text;
	cout << prompt;
	cin >> text;
	return text;
}

int askNumber(string prompt)
{
	int num;
	cout << prompt;
	cin >> num;
	return num;
}

void tellStory(string name, string noun, int number, string bodyPart, string verb)
{
	cout << "\nHere's your story:\n";
	cout << "The famous explorer " + name + " had nearly given up a quest to find ";
	cout << "The lost city of " + noun + " when one day the " + noun + " found the explorer.\n";
	cout << "Surrounded by " + number;
	cout << " " << noun;
	cout << " , a tear came to " << name << "'s " + bodyPart << ".\n";
	cout << "After all this time, the quest had come to an end.";
	cout << "The moral of the story is, be careful what you " << verb << " for.";
}