#include <iostream>

using namespace std;

void sorting(char*);

int main()
{
	char alpha[] = "aAbBcCdDeEfF";

	sorting(alpha);

	return 0;
}

void sorting(char array[])
{
	cout << array << endl;

	for (int i = 0; array[i] != '\0'; i++)
	{
		if (array[i] >= 65 && array[i] <= 90)
		{
			for (int j = i + 1; array[j] != '\0'; j++)
			{
				if (array[j] >= 97 && array[j] <= 122)
				{
					swap(array[i], array[j]);
					break;
				}
			}
		}
	}

	for (int i = 0; array[i] != '\0'; i++)
	{
		if (array[i] >= 65 && array[i] <= 90)
		{
			for (int j = i + 1; array[j] != '\0'; j++)
			{
				if (array[i] > array[j])
				{
					swap(array[i], array[j]);
				}
			}
		}
	}

	cout << array << endl;
}