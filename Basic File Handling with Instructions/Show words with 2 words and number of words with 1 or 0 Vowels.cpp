#include<iostream>
#include<fstream>
using namespace std;

int filename(const char *);

int main()
{
	const char file[] = "Data.txt";


	cout << filename(file);

	return 0;
}


int filename(const char *file2)
{
	const int size2 = 500;

	char array2[size2];

	int counter = 0, counter2 = 0;

	ifstream fin;

	fin.open(file2);

	while (fin >> array2)
	{
		cout << array2 << " ";
	}
	cout << endl << endl;

	fin.close();

	fin.open(file2);


	cout << "Words with 2 vowels are : \n";
	while (fin >> array2)
	{
		counter = 0;

		for (int count = 0; array2[count] != '\0'; count++)
		{

			switch (array2[count])
			{
			case 'A':
				counter++;
				break;
			case 'E':
				counter++;
				break;
			case 'I':
				counter++;
				break;
			case 'O':
				counter++;
				break;
			case 'U':
				counter++;
				break;
			case 'a':
				counter++;
				break;
			case 'e':
				counter++;
				break;
			case 'i':
				counter++;
				break;
			case 'o':
				counter++;
				break;
			case 'u':
				counter++;
				break;
			}
		}

		if (counter == 2)
		{
			cout << array2 << endl;
		}

		else if (counter <= 1)
		{
			counter2++;
		}
	}

	cout << endl << "Total number of words with 1 and less than 1 vowel are : \n";
	return counter2;
}