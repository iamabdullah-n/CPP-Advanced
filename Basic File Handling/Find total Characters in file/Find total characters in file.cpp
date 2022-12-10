#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	ifstream fin;

	char c[200];
	
	fin.open("Data.txt");

	int size = 0;

	if (fin.is_open())
	{
		cout << "File Found" << endl;

		while (fin.getline(c, 200))
		{
			cout << c << endl;
			size = size + strlen(c);

		}
	}

	cout << "Count : " << size << endl;

	system("PAUSE");
	return 0;
}