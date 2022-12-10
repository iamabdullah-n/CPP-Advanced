#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstring>

using namespace std;

void list(void);
void search(void);
void add(void);
void remove(void);

int main()
{
	int  choice = 0;

	do
	{
		cout << endl;
		cout << setw(75);
		cout << "STUDENT RECORD MANAGEMENT SYSTEM" << endl;


		cout << endl;
		cout << "Choose from the following options:\n";
		cout << "1. Display the records of all students.\n";
		cout << "2. Search a student record by roll number.\n";
		cout << "3. Add record of another student.\n";
		cout << "4. Remove record of student.\n";
		cout << "0. Exit the application.\n";
		cout << "Enter your choice : ";
		cin >> choice;
		cout << endl;

		system("cls");

		if (choice == 1)
		{
			list();
		}

		else if (choice == 2)
		{
			search();
		}

		else if (choice == 3)
		{
			add();
		}

		else if (choice == 4)
		{
			remove();
		}

		else if (choice == 0)
		{
			cout << "Exited Application\nThank You, Good Bye\n";
		}

	} while (choice != 0);


	system("PAUSE");
	return 0;
}

void list()
{
	ifstream fin;

	const int size = 100;

	char firstLine[size] = { '\0' }, firstName[size] = { '\0' }, lastName[size] = { '\0' }, rollNumber[size] = { '\0' }, city[size] = { '\0' };

	int age = 0;

	float gpa = 0;

	fin.open("Records.txt");

	fin.getline(firstLine, size);
	cout << "The list of records are : \n";
	cout << firstLine << endl;

	while (!fin.eof())
	{
		fin >> firstName;

		fin >> lastName;

		fin >> rollNumber;

		fin >> age;

		fin >> gpa;

		fin >> city;

		cout << firstName << " " << lastName << "\t|\t" << rollNumber << "\t|\t" << age << "\t|\t" << gpa << "\t|\t" << city << endl;
	}
	cout << endl;

	fin.close();
}

void search()
{
	ifstream fin;

	fin.open("Records.txt");

	const int size = 100;

	char firstLine[size] = { '\0' }, firstName[size] = { '\0' }, lastName[size] = { '\0' }, city[size] = { '\0' }, rollNumber[size] = { '\0' }, rollCheck[size] = { '\0' };

	int age = 0;

	float gpa = 0;

	bool isFound = false;

	cout << "Enter the roll number of the student you want to find : ";
	cin >> rollCheck;
	cout << endl;

	fin.getline(firstLine, size);

	while (!fin.eof())
	{
		isFound - false;

		fin >> firstName;

		fin >> lastName;

		fin >> rollNumber;

		fin >> age;

		fin >> gpa;

		fin >> city;

		if (strcmp(rollNumber, rollCheck) == 0)
		{
			isFound = true;
			break;
		}
	}

	if (isFound == true)
	{
		cout << "STUDENT FOUND!\n";
		cout << firstName << " " << lastName << "\t\t" << rollNumber << "\t\t" << age << "\t\t" << gpa << "\t\t" << city << endl;
	}

	else
	{
		cout << "STUDENT NOT FOUND!\n";
	}

	fin.close();
}

void add()
{
	ifstream fin;
	ofstream fout;

	fout.open("Records.txt", ios::app);

	const int size = 100;

	char firstName[size] = { '\0' }, lastName[size] = { '\0' }, city[size] = { '\0' }, rollNumber[size] = { '\0' };

	int age = 0;

	float gpa = 0;

	cin.ignore();
	cout << "Enter you first name : ";
	cin >> firstName;

	cout << "Enter the last name : ";
	cin >> lastName;

	cout << "Enter your roll number : ";
	cin >> rollNumber;

	cout << "Enter your age : ";
	cin >> age;

	cout << "Enter your GPA : ";
	cin >> gpa;

	cin.ignore();
	cout << "Enter name of the city you belongs : ";
	cin.getline(city, size);

	fout << endl << firstName << " " << lastName << "\t\t" << rollNumber << "\t\t" << age << "\t\t" << gpa << "\t\t" << city;

	cout << "\nNEW STUDENT ADDED\n";

	fout.close();
}

void remove()
{
	ifstream fin;
	ofstream fout;

	fin.open("Records.txt");

	const int size = 100;

	char firstLine[size] = { '\0' }, firstName[size] = { '\0' }, lastName[size] = { '\0' }, city[size] = { '\0' }, rollNumber[size] = { '\0' }, rollCheck[size] = { '\0' };

	int age = 0;

	float gpa = 0;

	bool isFound = false;

	cout << "Enter the roll number of the student you want to find : ";
	cin >> rollCheck;
	cout << endl;

	fin.getline(firstLine, size);

	while (!fin.eof())
	{
		isFound = false;

		fin >> firstName;

		fin >> lastName;

		fin >> rollNumber;

		fin >> age;

		fin >> gpa;

		fin >> city;

		if (strcmp(rollNumber, rollCheck) == 0)
		{
			isFound = true;
			break;
		}
	}

	fin.close();

	if (isFound == true)
	{
		char choice = '\0';

		cout << "STUDENT FOUND!\n";
		cout << firstName << " " << lastName << "\t\t" << rollNumber << "\t\t" << age << "\t\t" << gpa << "\t\t" << city << endl;

		cout << "\n\nDo you want to remove the data of this student?\nIf yes then press Y! ";
		cin >> choice;

		if (choice == 'y' || choice == 'Y')
		{
			fin.open("Records.txt");
			fout.open("Temp.txt");

			fin.getline(firstLine, size);
			fout << firstLine;

			while (!fin.eof())
			{
				isFound = false;

				fin >> firstName;

				fin >> lastName;

				fin >> rollNumber;

				fin >> age;

				fin >> gpa;

				fin >> city;

				if (strcmp(rollNumber, rollCheck) != 0)
				{
					fout << endl << firstName << " " << lastName << "\t\t" << rollNumber << "\t\t" << age << "\t\t" << gpa << "\t\t" << city;
				}
			}

			fin.close();
			fout.close();

			remove("Records.txt");
			rename("Temp.txt", "Records.txt");

			cout << "\nSTUDENT RECORD DELETED!\n";

		}

	}

	else
	{
		cout << "STUDENT NOT FOUND!\n";
	}
}