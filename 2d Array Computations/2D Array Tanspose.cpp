#include<iostream>
using namespace std;
int main()
{
	int array[3][2] = { 0 }, array2[2][3] = { 0 };

	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 2; col++)
		{
			array[row][col] = (rand() % 10) + 10;
		}
	}

	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 2; col++)
		{
			array2[col][row] = array[row][col];
		}
	}

	cout << "\nNormal Array :\n";
	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 2; col++)
		{
			cout << array[row][col] << "\t";
		}
		cout << endl;
	}

	cout << "\nTransposed Array :\n";
	for (int col = 0; col < 2; col++)
	{
		for (int row = 0; row < 3; row++)
		{
			cout << array2[col][row] << "\t";
		}
		cout << endl;
	}

	system("PAUSE");
	return 0;
}