#include<iostream>
using namespace std;
int main()
{
	const int size = 20;
	char array[size] = { '\0' };
	int counter1 = 0, counter2 = 0;

	cout << "Enter a word : ";
	cin.getline(array, size);

	for (int count = 0; array[count] != '\0'; count++)
	{
		counter1++;
		if (array[count] >= 97 && array[count] <= 122)
		{
			array[count] = array[count] - 32;
		}
	}

	for (int count = 0; array[count] != '\0'; count++) 
	{
		if(array[count] == array[counter1 - (count + 1)])
		{
			counter2++;
		}
		else
		{
			break;
		}
	}

	if (counter1 == counter2)
	{
		cout << "Word is palindromic" << endl;
	}
	else
	{
		cout << "Word is not palindromic" << endl;
	}

	return 0;
}