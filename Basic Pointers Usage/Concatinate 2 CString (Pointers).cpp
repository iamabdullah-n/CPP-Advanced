#include<iostream>

using namespace std;

void arrayMerge(char*, char*, int);

int main()
{
	const int size = 10;

	char array1[size] = { 0 }, array2[size] = { 0 };


	cout << "Source Array : \n";
	for (int count = 0; count < size; count++)
	{
		array1[count] = (rand() % 26) + 65;
		array2[count] = (rand() % 26) + 65;
	}

	cout << "1st character array : \n";
	for (int count = 0; count < size; count++)
	{
		cout << array1[count] << '\t';
	}
	cout << endl;

	cout << "2nd character array : \n";
	for (int count = 0; count < size; count++)
	{
		cout << array2[count] << '\t';
	}
	cout << endl << endl;

	arrayMerge(array1, array2, size);

	return 0;
}

void arrayMerge(char* character1, char* character2, int size)
{
	const int size2 = 20;
	char mergeArray[size2] = { '\0' };


	int counter = 0;

	for (int count = 0; count < size; count++)
	{
		mergeArray[counter] = character1[count];
		counter++;
	}

	for (int count = 0; count < size; count++)
	{
		mergeArray[counter] = character2[count];
		counter++;
	}

	for (int i = 0; i < size2 - 1; i++)
	{
		for (int j = i + 1; j < size2; j++)
		{
			if (mergeArray[i] > mergeArray[j])
			{
				swap(mergeArray[i], mergeArray[j]);
			}
		}
	}

	cout << "AFTER Merging!\nFinal Array :\n";
	for (int count = 0; count < 20; count++)
	{
		cout << mergeArray[count] << '\t';
	}
	cout << endl;
}