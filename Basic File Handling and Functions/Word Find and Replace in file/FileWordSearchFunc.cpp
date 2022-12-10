#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int count(char*);

int main()
{
	int counter = 0;

	const int size = 100;

	char array[size] = { "\0" };

	cout << "Enter a word to search in file : ";
	cin >> array;

	counter = count(array);

	cout << array << " occured in the file " << counter << " times \n";

	return 0;
}

int count(char* array2)
{
	const int size = 100;

	char array3[size] = { "\0" };

	int counter2 = 0;

	ifstream fin;

	fin.open("Data.txt");


	while (!fin.eof())
	{
		fin >> array3;

		if (strcmp(array2, array3) == 0)
		{
			counter2++;
		}
	}


	return counter2;

}