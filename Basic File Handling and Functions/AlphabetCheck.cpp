#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	char c, check;
	int counter = 0, counter2 = 0;
	
	char alphabets[27] = { "NULL" };
	int alphaCount[26] = { 0 };

	ifstream fin;

	fin.open("Data.txt");

	for (int count = 97; count <= 122; count++)
	{
		counter = 0;

		check = count;

		alphabets[counter2] = check;

		while (fin >> c)
		{
			if (c >= 65 && c <= 90)
			{
				c += 32;
			}

			if (c == check)
			{
				counter++;
			}
		}

		alphaCount[counter2] = counter;

		counter2++;
	}

	for (int count = 0; count < 26; count++)
	{
		cout << alphabets[count] << " : " << alphaCount[count] << endl;
	}

	return 0;
}