#include<iostream>
using namespace std;
int main()
{
	const int size = 4;

	int array[size][size] = { 0 };

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			array[i][j] = rand() % 10;
		}
	}

	cout << "\nArray : \n";
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << array[i][j] << "\t";
		}
		cout << endl;
	}

	int sum = 0;

	cout << "\nDiagnol Elements : \n";
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if ((i == j) || (i + j == size - 1))
			{
				cout << array[i][j] << "\t";
				sum += array[i][j];
			}
			else
			{
				cout << " " << "\t";
			}
		}
		cout << endl;
	}

	cout << "\nSum of diagnol values is : " << sum << endl;

	system("PAUSE");
	return 0;
}