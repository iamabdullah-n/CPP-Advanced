#include<iostream>
using namespace std;

int **shrink(int **, int, int *, int);

int main()
{
	int row = 0;

	cout << "Enter the number of rows for 2d array : ";
	cin >> row;

	int *col = new int[row];

	int **array = new int*[row];

	for (int i = 0; i < row; i++)
	{
		*(col + i) = rand() % 5;

		*(array + i) = new int[col[i]];

		for (int j = 0; j < col[i]; j++)
		{
			*(*(array + i) + j) = rand() % 10;
		}
	}

	cout << "Array : \n\n";
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col[i]; j++)
		{
			cout << *(*(array + i) + j) << "\t";
		}
		cout << endl << endl;
	}

	int  num = 0;

	cout << "Enter the value to delete : ";
	cin >> num;

	array = shrink(array, row, col, num);

	cout << "Array : \n\n";
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col[i]; j++)
		{
			cout << *(*(array + i) + j) << "\t";
		}
		cout << endl << endl;
	}

	for (int i = 0; i < row; i++)
	{
		delete[] array[i];
	}
	delete[] array;

	delete[] col;

	array = NULL, col = NULL;

	system("PAUSE");
	return 0;
}

int **shrink(int **array, int row, int *col, int num)
{
	int index1 = -1, index2 = -1;

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col[i]; j++)
		{
			if (array[i][j] == num)
			{
				index1 = i;
				index2 = j;
			}
		}
	}

	if (index1 != -1 && index2 != -1)
	{
		for (int i = index2; i < col[index1] - 1; i++)
		{
			array[index1][i] = array[index1][i + 1];
		}

		int **newArray = new int*[row];

		for (int i = 0; i < row; i++)
		{
			if (index1 == i)
			{
				*(newArray + i) = new int[col[i] - 1];
			}

			else
			{
				*(newArray + i) = new int[col[i]];
			}
		}

		col[index1]--;

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col[i]; j++)
			{
				newArray[i][j] = array[i][j];
			}
		}

		for (int i = 0; i < row; i++)
		{
			delete[] array[i];
		}
		delete[] array;

		return newArray;
	}

	else
	{
		return array;
	}
}