#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	const int size1 = 7, size2 = 3;

	int array[size1][size2] = { 0 };

	ifstream fin;
	fin.open("Lab.txt");

	cout << "Enter elements of array!\n";
	for (int i = 0; i < size1; i++)
	{
		for (int j = 0; j < size2; j++)
		{
			//cout << "Enter array[" << i << "][" << j << "] : ";
			fin >> array[i][j];
		}
	}

	cout << "BEFORE COMPARISON!\nArray : \n";
	for (int i = 0; i < size1; i++)
	{
		for (int j = 0; j < size2; j++)
		{
			cout << array[i][j] << "\t\t";
		}
		cout << endl << endl;
	}

	int counter = 0;

	for (int i = 0; i < size1; i++)
	{
		for (int i2 = i + 1; i2 < size1; i2++)
		{
			counter = 0;
			for (int j = 0; j < size2; j++)
			{
				if (array[i][j] == array[i2][j])
				{
					//cout << array[i][j] << '\t' << array[i2][j] << endl << endl;

					counter++;
				}
				else
				{
					continue;
				}
			}

			if (counter == 3)
			{
				for (int j = 0; j < size2; j++)
				{
					array[i][j] = -1;
					array[i2][j] = -1;
				}
			}
		}
	}

	cout << "AFTER COMPARISON!\nArray : \n";
	for (int i = 0; i < size1; i++)
	{
		for (int j = 0; j < size2; j++)
		{
			cout << array[i][j] << "\t\t";
		}
		cout << endl << endl;
	}

	system("PAUSE");
	return 0;
}