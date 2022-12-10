#include<iostream>
#include<fstream>
#include<string>

using namespace std; 

int main()
{
	const int size = 500;

	char array1[size], array2[size];

	int array3[size];

	int temp = 0;


	ofstream fout1, fout2, fout3, fout4;

	fout1.open("File1.txt");

	cout << "Enter a sentence : ";
	cin.getline(array1, size);

	fout1 << array1;

	fout2.open("File2.txt");

	cout << "Enter a sentence : ";
	cin.getline(array2, size);

	fout2 << array2; 
	
	cout << "Enter how many numbers you want to enter : ";
	cin >> temp;

	fout3.open("File3.txt");

	for (int count = 0; count < temp; count++)
	{
		cout << count + 1 << ". Enter a number = ";
		cin >> array3[count];
		fout3 << array3[count] << " ";
	}

	fout1.close();
	fout2.close();
	fout3.close();

	ifstream fin1, fin2, fin3;


	fin1.open("File1.txt");

	fin2.open("File2.txt");

	fin3.open("File3.txt");

	fout4.open("SumofFiles.txt");

	for (int i = 0; !fin1.eof(); i++)
	{
		fin1.getline(array1, size);
		fout4 << array1 << " ";
	}

	for (int i = 0; !fin2.eof(); i++)
	{
		fin2.getline(array2, size);
		fout4 << array2 << " ";
	}

	fout4 << array2 << " ";


	for (int count = 0; count < temp; count++)
	{
		fin3 >> array3[count];

		fout4 << array3[count] << " ";
	}
	
	fout4 << endl;
	


	return 0;
}