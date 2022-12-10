#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;

int main()
{
	ifstream fin;
	fin.open("Out.txt");

	const int size = 100;

	char word[size] = { '\0' };

	int counter = 0;

	while (!fin.eof())
	{
		fin >> word;
		cout << word << " ";
		counter += strlen(word);
	}

	cout << "\nThere are total " << counter << " alphabets in the file\n";

	system("PAUSE");
	return 0;
}