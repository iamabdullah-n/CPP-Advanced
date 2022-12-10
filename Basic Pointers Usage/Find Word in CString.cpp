#include<iostream>

using namespace std;

bool animalCheck(char*, char*);

int main()
{
	const int size = 100;
	char animalNames[size] = { '\0' }, animal[size] = { '\0' };


	cout << "Enter Animal names without space : ";
	cin >> animalNames;

	cout << "Now enter the word which you want to search : ";
	cin >> animal;

	bool isFound = animalCheck(animalNames, animal);


	if (isFound == true)
	{
		cout << "WORD FOUND! \n";
	}
	else
	{
		cout << "WORD NOT FOUND! \n";
	}

	return 0;
}

bool animalCheck(char* animalNames2, char* animal2)
{
	
	int check = 0, counter = 0, counter2 = 0;

	for (int count = 0; animal2[count] != '\0'; count++)
	{
		counter++;
	}

	for (int i = 0; animalNames2[i] != '\0'; i++)
	{
		if (animal2[check] == animalNames2[i])
		{
			while (animal2[check] == animalNames2[i])
			{
				i++;
				check++;
				counter2++;

				if (counter == counter2)
				{
					break;
				}
			}
		}
	}

	if (counter == counter2)
	{
		return true;
	}
	else
	{
		return false;
	}
}