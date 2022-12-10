#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	const int size = 500;

	char array[size];

	int counter = 0;

	ifstream fin;

	ofstream fout;

	fin.open("File.txt");

	fout.open("Output.txt");

	while (fin >> array)
	{
		if (array[counter] != 'o' && array[counter + 1] != 'f')
		{
			cout << array;
			fout << array;
		}
	}

	return 0;
}