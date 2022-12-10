#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;
int main()
{
	const int size = 500;

	char array[size] = "\0", array2[size] = "\0";

	int counter = 0, counter2 = 0, large = 0;

	char letter = '\0';

	ifstream fin;

	fin.open("Data.txt");

	while (fin >> array)
	{
		cout << array << " ";
		counter = strlen(array);

		if (counter > large)
		{
			large = counter;
			swap(array, array2);
		}
	}

	cout << endl << endl << array2 << " is the longest word with " << large << " letters \n\n";

	fin.close();
	

	for (int count1 = 65; count1 <= 90; count1++)
	{
		counter2 = 0;
		letter = count1;

		fin.open("Data.txt");

		for (int count = 1; !fin.eof(); count++)
		{
			fin.getline(array, size);


			for (int count2 = 0; array[count2] != '\0'; count2++)
			{
				if (array[count2] >= 97 && array[count2] <= 122)
				{
					array[count2] = array[count2] - 32;
				}

				if (letter == array[count2])
				{
					counter2++;
				}
			}
		}

		cout << letter << " repeats " << counter2 << " times \n";

		fin.close();
	}

	return 0;
}