#include<iostream>
#include<fstream>

using namespace std;

int main()
{
	ifstream fin("Names.txt");

	int row_size = 0;

	fin >> row_size;

	int *col_size = new int[row_size], *col2_size = new int[row_size], *index = new int[row_size];

	char *first = new char[row_size];

	char **names = new char*[row_size], **names2 = new char*[row_size];

	for (int i = 0; i < row_size; i++)
	{
		fin >> col_size[i];

		col_size[i]++;

		names[i] = new char[col_size[i]];
		
		fin >> names[i];
	}

	cout << "Data in file : \n\n";
	for (int i = 0; i < row_size; i++)
	{
		col2_size[i] = col_size[i];

		index[i] = i;

		first[i] = names[i][0];

		for (int j = 0; j < col_size[i]; j++)
		{
			cout << *(*(names + i) + j);
		}
		cout << endl << endl;
	}

	for (int i = 0; i < row_size - 1; i++)
	{
		for (int j = i + 1; j < row_size; j++)
		{
			if (first[i] > first[j])
			{
				swap(first[i], first[j]);
				swap(col2_size[i], col2_size[j]);
				swap(index[i], index[j]);
			}
		}
	}

	for (int i = 0; i < row_size; i++)
	{
		names2[i] = new char[col2_size[i]];
		
		strcpy(names2[i], names[index[i]]);
	}

	fin.close();

	ofstream fout("Records.txt");

	cout << "\n\nAFTER SORTING\n\nData : \n\n";
	for (int i = 0; i < row_size; i++)
	{
		cout << names2[i] << endl << endl;
	}

	cout << "\n\nSORTED DATA IS ADDED IN FILE...........\n\n";

	for (int i = 0; i < row_size; i++)
	{
		col2_size[i]--;
		fout << col2_size[i] << '\t' << names2[i] << endl<< endl;
	}

	fout.close();

	for (int i = 0; i < row_size; i++)
	{
		delete[] names[i];
	}
	delete[] names;

	for (int i = 0; i < row_size; i++)
	{
		delete[] names2[i];
	}
	delete[] names2;

	delete[] col_size, first, col2_size, index;

	col_size = NULL, first = NULL, names = NULL, col2_size = NULL, index = NULL;

	system("PAUSE");
	return 0;
}