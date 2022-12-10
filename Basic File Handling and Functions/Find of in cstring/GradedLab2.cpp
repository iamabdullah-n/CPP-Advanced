#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	const int size = 500;

	char array[size] = {'\0'};

	int counter = 0;

	ifstream fin;

	ofstream fout;

	fin.open("Graded2File.txt");

	fout.open("Graded2Output.txt");

	while (fin >> array)
	{
		if (array[counter] != 'o' && array[counter + 1] != 'f')
		{
			cout << array << " ";

			fout << array;
		}
	}

	cout << "\n\n\n";


	return 0;
}