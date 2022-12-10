#include<iostream>
using namespace std;

void copy(int *oldArray, int size, int *newArray)
{
	for (int i = 0; i < size; i++)
	{
		*(newArray + i) = *(oldArray + i);
	}
}

void display(int *evenNumbers, int size)
{
	cout << "\n\nElements in the Array : \t";
	for (int i = 0; i < size; i++)
	{
		cout << *(evenNumbers + i) << '\t';
	}
	cout << endl;
}

int *regrow(int *evenNumbers, int size, int temp)
{
	int *array = new int[size + 1];

	copy(evenNumbers, size, array);

	*(array + size) = temp;

	delete[] evenNumbers;
	evenNumbers = NULL;

	return array;
}

int main()
{
	char choice = '\0';

	int num = 0, size = 0;

	int *temp = new int;

	int *evenNumbers = NULL;

	do
	{
		cout << "\n\nEnter how many numbers you want to enter : ";
		cin >> num;

		for (int i = 0; i < num; i++)
		{
			cout << "Enter the number " << i + 1 << " : ";
			cin >> *temp;

			if (*temp % 2 == 0)
			{
				evenNumbers = regrow(evenNumbers, size, *temp);

				size++;
			}
		}

		display(evenNumbers, size);

		cout << "\n\nEnter Y/y to continue adding numbers or Enter N/n to close the program : ";
		cin >> choice;

	} while (choice != 'N' || choice != 'n');

	delete[] evenNumbers;
	delete temp;

	evenNumbers = NULL, temp = NULL;

	system("PAUSE");
	return 0;
}