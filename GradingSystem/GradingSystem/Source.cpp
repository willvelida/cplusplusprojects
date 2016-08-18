#include <iostream>
#include <string>

using namespace std;

int main()
{
	cout << "Welcome to the programming grading system!" << endl;
	cout << "Please enter the student's mark " << endl;
	int studentMark;
	char studentGrade;
	cin >> studentMark;
	if (studentMark >= 90)
	{
		studentGrade = 'A';
	}
	else if (studentMark >= 80)
	{
		studentGrade = 'B';
	}
	else if (studentMark >= 70)
	{
		studentGrade = 'C';
	}
	else if (studentMark >= 60)
	{
		studentGrade = 'D';
	}
	else
	{
		studentGrade = 'F';
	}
	cout << "The student has recieved a " << studentGrade << endl;
}