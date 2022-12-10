#include<iostream>
using namespace std;
int main()
{
	const int size1 = 200, size2 = 50;
	char sent[size1];
	char word[size2];

	int counter1 = 0, counter2 = 0;

	cout << "Enter any sentence : \n";
	cin.getline(sent, size1);

	cout << "You have entered a sentence \nNow enter a word to find it in a sentence : ";
	cin.getline(word, size2);

	for (int count = 0; word[count] != '\0'; count++)
	{
		counter1++;
	}


	for (int i = 0; i < size2; i++)
	{
		for (int j = 0; j < size1; j++)
		{
			if (word[i] == sent[j])
			{
				while (counter1 != counter2)
				{
					if (word[i] == sent[j])
					{
						counter2++;
					}

					i++;
					j++;
				}
			}
		}
	}

	if (counter1 == counter2)
	{
		cout << "Word Found in the sentence \n";
	}

	else
	{
		cout << "Word not Found in the sentence \n";
	}

	return 0;
}