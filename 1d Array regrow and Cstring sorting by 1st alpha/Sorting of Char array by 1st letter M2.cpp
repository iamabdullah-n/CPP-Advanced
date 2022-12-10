#include<iostream>
#include<fstream>

using namespace std;

void address_swap(char * &LHS, char * &RHS)
{
	swap(LHS, RHS);
}

int main()
{
	ifstream fin("Names.txt");

	int row_size;

	fin >> row_size;

	char **names = new char*[row_size];

	int *col_size = new int[row_size];

	for (int i = 0; i < row_size; i++)
	{
		fin >> col_size[i];

		names[i] = new char[col_size[i] + 1];

		fin >> names[i];
	}

	cout << "Data : \n";
	for (int i = 0; i < row_size; i++)
	{
		cout << col_size[i] << '\t' << names[i] << endl;
	}

	for (int i = 0; i < row_size - 1; i++)
	{
		for (int j = i + 1; j < row_size; j++)
		{
			if (*(*(names + i) + 0) > *(*(names + j) + 0))
			{
				address_swap(*(names + i), *(names + j));

				swap(*(col_size + i), *(col_size + j));
			}
		}
	}

	cout << "AFTER SORTING!!!\n\nData : \n";
	for (int i = 0; i < row_size; i++)
	{
		cout << col_size[i] << '\t' << names[i] << endl;
	}

	system("PAUSE");
	return 0;
}