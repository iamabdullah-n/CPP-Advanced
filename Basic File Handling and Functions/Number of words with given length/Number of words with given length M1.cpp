#include<iostream>
#include<fstream>
#include<string>

int length(int);

using namespace std;
int main()
{
	int num = 0;

	cout << "Enter a number : ";
	cin >> num;

	cout << length(num) << " words are of the length entered by you \n";

	return 0;
}

int length(int N)
{
	int size = 0, counter = 0;

	string S;

	fstream fin;

	fin.open("Data.txt", ios::in);

	while (fin >> S)
	{
		cout << S << " ";

		size = sizeof(S);

		cout << size << endl;

		if (size == N)
		{
			counter++;
		}
	}

	return counter;
}