#include<iostream>
#include<string>
#include<fstream>
using namespace std;

void removeVowels(char*);

int main()
{
	char array[100] = { NULL };

	ifstream fin;

	fin.open("input.txt");

	fin.getline(array, 100);

	fin.close();

	removeVowels(array);

	return 0;
}

void removeVowels(char* array2)
{
	ofstream fout;

	fout.open("output.txt");

	cout << array2 << endl;

	for (int count = 0; array2[count] != '\0'; count++)
	{
		if (array2[count] == 'A' || array2[count] == 'E' || array2[count] == 'I' || array2[count] == 'O' || array2[count] == 'U')
		{
			continue;
		}
		
		else if (array2[count] == 'a' || array2[count] == 'e' || array2[count] == 'i' || array2[count] == 'o' || array2[count] == 'u')
		{
			continue;
		}

		else
		{
			fout << array2[count];
		}
	}

	fout << endl;
	fout.close();
}