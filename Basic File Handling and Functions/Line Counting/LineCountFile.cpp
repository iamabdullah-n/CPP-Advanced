#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int main()
{
	fstream fin;

	char words[200];

	int size = 0, counter = 0;

	fin.open("Data.txt");

	while (fin.getline(words, 200))
	{
		cout << words;
		cout << endl;
		size += strlen(words);
		counter++;
	}

	cout << "Total characters are : " << size << endl;
	cout << "Total lines are : " << counter << endl;

	return 0;
}