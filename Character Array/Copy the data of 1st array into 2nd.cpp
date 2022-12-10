#include<iostream>
using namespace std;
int main()
{
	const int size = 50;
	char array[size], array2[size] = { '/0' };

	cout << "Enter the statement : ";
	cin.getline(array, size);

	for (int count = 0; array[count] != '\0'; count++)
	{
		array2[count] = array[count];
	}

	for (int count = 0; array2[count] != '\0'; count++)
	{
		cout << array2[count];
	}

	return 0;
}