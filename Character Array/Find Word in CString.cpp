#include<iostream>
using namespace std;
int main()
{
	const int size = 50;
	char sent[size] = { '\0' }, word[size] = { '\0' };
	int counter = 0, counter2 = 0, counter3 = 0;
	
	cout << "Enter animal names without spaces :- \n";
	cin.getline(sent, size);

	cout << "Enter the animal name to find it in the sentence : ";
	cin.getline(word, size);

	for (int count = 0; word[count] != '\0'; count++)
	{
		counter++;
	}


	for (int count = 0; sent[count] != '\0'; count++)
	{
		if(sent[count] == word[counter2])
		{
			while (count != counter2)
			{
				if (sent[count] == word[counter2])
				{
					count++;
					counter2++;
					counter3++;

				}
				else
				{
					break;
				}
			}
		}
	}

	if (counter == counter3)
	{
		cout << "Word found" << endl;
	}

	else
	{
		cout << "Word not found" << endl;
	}

	return 0;
}