#include<iostream>
using namespace std;
int main()
{
	const int size = 20, size2 = 50;
	char word[size] = { '\0' }, word2[size] = { '/0' };
	char sent[size2] = { '\0' };
	

	cout << "Enter the first word : ";
	cin.getline(word, size);

	cout << "Enter the second word : ";
	cin.getline(word2, size);

	int counter = 0;
	for (int count = 0; word[count] != '\0'; count++)
	{
		sent[count] = word[count];
		counter = count;
	}

	sent[counter] = ' ';
	counter++;

	for (int count = 0; word2[count] != '\0'; count++)
	{
		sent[counter] = word2[count];
		counter++;
	}

	for (int count = 0; sent[count] != '\0'; count++)
	{
		cout << sent[count];
	}

	return 0;
}