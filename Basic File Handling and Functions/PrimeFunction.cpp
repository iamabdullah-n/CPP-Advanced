#include<iostream>

int prime(int);

using namespace std;
int main()
{
	int num = 0;

	cout << "Enter a number = ";
	cin >> num;

	if (prime(num) == 0)
	{
		cout << "Number is prime \n";
	}

	else if(prime(num) == 1)
	{
		cout << "Number is not prime \n";
	}

	return 0;
}

int prime(int x)
{
	int counter = 0, check = 0;

	for (int count = 2; count <= x / 2; count++)
	{
		if (x % count == 0)
		{
			counter++;
		}
	}

	if (counter == 0)
	{
		check = 0;
	}

	else
	{
		check = 1;
	}

	return check;
}