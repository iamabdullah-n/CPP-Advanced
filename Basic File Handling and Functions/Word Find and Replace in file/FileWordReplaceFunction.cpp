#include<iostream>
#include<fstream>
#include<cstring>
#include<string>
#include<string.h>

bool wordSearch(char*);
void wordReplace(char*, char*);

using namespace std;
int main()
{
	char array[100] = { NULL }, array2[100] = { NULL };

	bool isFound = false;

	cout << "Enter a word to search in a file : ";
	cin >> array;

	isFound = wordSearch(array);

	if (isFound == true)
	{
		cout << "Word " << array << " Found!\n";
		cout << "Enter the word with which you want to replace : ";
		cin >> array2;

		wordReplace(array, array2);
	}

	else
	{
		cout << "Word " << array << " not Found!\n";
	}

	return 0;
}

bool wordSearch(char* word)
{
	char data[100] = { NULL };

	bool isFound = false;

	ifstream fin;

	fin.open("Data.txt");

	while (fin >> data)
	{
		if (strcmp(data, word) == 0)
		{
			isFound = true;
		}
	}

	fin.close();

	if (isFound == true)
	{
		return true;
	}
	else
	{
		return false;
	}

}

void wordReplace(char* word1, char* word2)
{
	char array[100] = { NULL };

	ifstream fin;

	fin.open("Data.txt");

	while (fin >> array)
	{
		if (strcmp(array, word1) == 0)
		{
			strcpy(array, word2);
		}
	}

	cout << "Word Replaced! \n";

}