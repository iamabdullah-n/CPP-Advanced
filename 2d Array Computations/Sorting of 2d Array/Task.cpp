#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	int **array = new int*[3];

	for (int count = 0; count < 3; count++)
	{
		array[count] = new int[3];
	}

	ifstream fin;

	fin.open("Data4.txt");

	int n;

	fin >> n;
	fin >> n;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			fin >> array[i][j];
		}
	}

	cout << "Array : \n";
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << array[i][j] << '\t';
		}
		cout << endl << endl;
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3 - 1; j++)
		{
			if (array[i][j] > array[i][j + 1])
			{
				swap(array[i][j], array[i][j + 1]);
			}
		}
	}

	cout << "\nAFTER SORTING!\nArray : \n";
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << array[i][j] << '\t';
		}
		cout << endl << endl;
	}


	system("PAUSE");
	return 0;
}