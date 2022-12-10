#include<iostream>
using namespace std;
int main()
{
	const int size = 50;
	char array[size];
	int counter1 = 0, counter2 = 0;

	cout << "Enter the statement : ";
	cin.getline(array, size);

	for (int count = 0; array[count] != '\0'; count++)
	{
		if (array[count] >= 65 && array[count] <= 90)
		{
			counter1++;
		}

		else if (array[count] >= 97 && array[count] <= 122)
		{
			counter2++;
		}
	}

	cout << "Capital letters are " << counter1 << endl;
	cout << "Small letters are " << counter2 << endl;


	return 0;
}