#include<iostream>
#include<fstream>
using namespace std;

void display(int **array, int size)
{
	cout << "Upper Triangular Matrix of file data is \n\n";

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << *(*(array + i) + j) << " ";
		}
		cout << endl;
	}

	cout << endl << endl;
}

int **dataEntry(int **array, int size)
{
	ifstream fin("MatrixData.txt");

	for (int i = 0; i < size; i++)
	{
		for (int j = i; j < size; j++)
		{
			fin >> *(*(array + i) + j);
		}
	}

	return array;
}

int **zeroEntry(int **array, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			*(*(array + i) + j) = 0;
		}
	}

	return array;
}

int main()
{
	int size = 5;

	int **array = new int*[5];

	for (int i = 0; i < 5; i++)
	{
		*(array + i) = new int[5];
	}

	array = zeroEntry(array, size);

	array = dataEntry(array, size);

	display(array, size);

	system("PAUSE");
	return 0;
}