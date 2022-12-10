#include<iostream>
#include<fstream>
using namespace std;

void readfile(const char*, int&, int&, int&);
void check(int*, int&, int&, int&);

int main()
{
	const char filename[] = "data.txt";

	int a, b, c;
	
	readfile(filename, a, b, c);

	cout << "The number is " << a << endl;

	cout << "The sum is " << b << endl;

	cout << "Number " << a << " repeats " << c << " times " << endl;

	system("PAUSE");
	return 0;
}

void readfile(const char* file, int &a, int &b, int &c)
{
	int array[100] = { 0 };
	int count = 0, x, y, z;

	ifstream fin;

	fin.open(file);

	while (fin >> array[count++])
	{
	}

	check(array, x, y, z);

	a = x;
	b = y;
	c = z;
}

void check(int* array2, int &x, int &y, int &z)
{
	int number = 0, sum = 0, frequency = 0;
	bool isFound = false;

	for (int count = 0; array2[count] != NULL; count++)
	{
		if (isFound == false)
		{
			if (array2[count] % 2 == 0 && array2[count] != 2)
			{
				number = array2[count];
				sum = number;
				frequency++;
				isFound = true;
			}
		}
		else
		{
			if (array2[count] == number)
			{
				sum += number;
				frequency++;
			}
		}
	}

	x = number;
	y = sum;
	z = frequency;


}