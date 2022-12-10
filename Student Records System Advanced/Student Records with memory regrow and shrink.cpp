#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

int menu(int);
string *regrow(string *, int, string);
void display(string *, string *, int);

int main()
{
	int choice = 0, size = 0;

	string *rollNumber = NULL, *studentName = NULL;

	string roll, name;

	do
	{
		choice = menu(choice);

		while (choice < 0 || choice > 2)
		{
			cout << "\nWRONG INPUT!\nEnter the correct choice again : ";
			cin >> choice;
		}

		if (choice == 1)
		{

			cout << "\n\nEnter the Roll Number of the student : ";
			cin >> roll;

			rollNumber = regrow(rollNumber, size, roll);

			cin.ignore();
			cout << "\nEnter the Name of student : ";
			getline(cin, name);

			studentName = regrow(studentName, size, name);

			size++;

		}

		else if (choice == 2)
		{
			display(rollNumber, studentName, size);
		}

	} while (choice != 0);

	system("PAUSE");
	return 0;
}

int menu(int choice)
{
	system("cls");
	cout << setw(70);
	cout << "STUDENT RECORD SYSTEM\n";
	cout << "Choose from the following menu.\n";
	cout << "1. Enter data of new student in records\n";
	cout << "2. Display data of all students currenctly in records\n";
	cout << "0. Exit the application\n";
	cout << "\nEnter your choice : ";
	cin >> choice;

	return choice;
}

string *regrow(string *oldArray, int size, string data)
{
	string *newArray = new string[size + 1];

	for (int count = 0; count < size; count++)
	{
		*(newArray + count) = *(oldArray + count);
	}
	
	*(newArray + size) = data;

	return newArray;
}


void display(string *rollNumber, string *studentName, int size)
{
	char choice;

	system("cls");
	cout << setw(70);
	cout << "STUDENT RECORD SYSTEM\n";
	cout << "\n\nThe students in the records are :-\n\n";
	for (int count = 0; count < size; count++)
	{
		cout << *(rollNumber + count) << "\t\t|\t\t" << *(studentName + count) << endl;
	}

	cout << "\n\nEnter any alphanumeric key to continue : ";
	cin >> choice;
}