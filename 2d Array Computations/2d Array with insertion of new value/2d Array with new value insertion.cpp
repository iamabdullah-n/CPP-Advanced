#include<iostream>
using namespace std;

int menu(int);

int ** regrow(int **, const int, int *, int);

void copy (int **, const int, int *, int **);

void display(int **, const int, int *);

int arraySum(int **, const int, int *, int);

int main()
{
	const int row = 10;
	
	int choice = 0, num = 0;

	int col[row] = { 0 };

	int sum = 0;
	
	for (int count = 0; count < row; count++)
	{
		col[count] = rand() % 6;
	}

	int **elements = new int*[row];

	for (int count = 0; count < row; count++)
	{
		*(elements + count) = new int[col[count]];
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col[i]; j++)
		{
			*(*(elements + i) + j) = rand() % 101;
		}
	}

	do
	{
		choice = menu(choice);

		if (choice == 1)
		{
			display(elements, row, col);
			
		}

		else if (choice == 2)
		{
			cout << "\n\nEnter the row number in which you want to insert a value : ";
			cin >> num;

			elements = regrow(elements, row, col, num);

			col[num - 1]++;
		}

		else if (choice == 3)
		{
			sum = arraySum(elements, row, col, sum);

			cout << "\n\nThe sum of array elements is " << sum << endl << endl << endl;
		}

		else if (choice == 4)
		{
			break;
		}

	} while (true);

	system("PAUSE");
	return 0;
}

int menu(int choice)
{
	cout << "Choose from the following option\n";
	cout << "Press 1 to display 2d Array\n";
	cout << "Press 2 to add a new value in 2d Array\n";
	cout << "Press 3 to find the sum of the 2d Array elements\n";
	cout << "Press 4 to terminate the program\n";
	cout << "Enter your choice : ";
	cin >> choice;

	while (choice > 4 || choice < 1)
	{
		cout << "\n\nINVALID INPUT!!!\nEnter your choice again : ";
		cin >> choice;
	}

	return choice;
}

int ** regrow(int ** elements, const int row, int *col, int num)
{
	int **array = new int*[row];

	for (int count = 0; count < row; count++)
	{
		*(array + count) = new int[col[count]];

		if (count == (num - 1))
		{
			*(array + count) = new int[col[count] + 1];
		}
	}

	copy(elements, row, col, array);

	for (int count = 0; count < row; count++)
	{
		delete[] elements[count];
	}
	delete[] elements;

	elements = NULL;

	cout << "\n\nEnter the value you want to add in row no." << num << " : ";
	cin >> *(*(array + (num - 1)) + col[num - 1]);

	cout << "\n\nNEW ELEMENT ADDED.....\n\n\n";

	return array;
}

void copy(int ** oldArray, const int row, int *col, int ** newArray)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col[i]; j++)
		{
			*(*(newArray + i) + j) = *(*(oldArray + i) + j);
		}
	}
}

void display(int **elements, const int row, int *col)
{
	cout << "Array : \n\n";
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col[i]; j++)
		{
			cout << *(*(elements + i) + j) << "\t";
		}
		cout << endl << endl;
	}
	cout << endl << endl;
}

int arraySum(int ** elements, const int row, int *col, int sum)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col[i]; j++)
		{
			sum += *(*(elements + i) + j);
		}
	}

	return sum;
}