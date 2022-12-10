#include<iostream>
using namespace std;

int **regrow(int **, int, int *, int, int);

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

	int row_check = 0, num = 0;

	cout << "Enter the row number : ";
	cin >> row_check;

	cout << "ENter the value : ";
	cin >> num;

	row_check--;

	array = regrow(array, row, col, row_check, num);

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

int **regrow(int **array, int row, int *col, int row_check, int num)
{
	int **newArray = new int*[row];

	for (int i = 0; i < row; i++)
	{
		if (i == row_check)
		{
			*(newArray + i) = new int[col[i] + 1];
		}
		else
		{
			*(newArray + i) = new int[col[i]];
		}
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col[i]; j++)
		{
			newArray[i][j] = array[i][j];
		}
	}

	newArray[row_check][col[row_check]] = num;

	col[row_check]++;

	for (int i = 0; i < row; i++)
	{
		delete[] array[i];
	}
	delete[] array;

	return newArray;
}