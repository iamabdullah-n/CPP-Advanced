#include<iostream>
#include<fstream>

int length(int);

using namespace std;
int main()
{
	int num = 0;

	cout << "Enter a number : ";
	cin >> num;

	cout << endl << length(num) << " word matched the length entered by you \n";

	return 0;
}

int length(int N)
{
	const int size = 200;
	char array[size] = { "NULL" };

	int counter = 0, counter2 = 0;

	int total = 0;

	ifstream fin;

	fin.open("Data.txt");

	fin.getline(array, size);

	for (int count = 0; array[count] != '\0'; count++)
	{
		total++;
		cout << array[count];
		if (array[count] == ' ')
		{
			total--;
			if (total == N)
			{
				counter2++;
			}

			total = 0;
		}
	}

	return counter2;
}