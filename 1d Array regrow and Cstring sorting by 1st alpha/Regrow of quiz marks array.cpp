#include<iostream>
#include<fstream>

using namespace std;

float retake(float);

float *regrow(float *, int, float);

void copy(float *, int, float*);

int main()
{
	int size = 0, counter = 0;

	float newMarks = 0;

	ifstream fin("Marks.txt");

	fin >> size;

	float *array = new float[size];

	while (!fin.eof())
	{
		fin >> *(array + counter);

		counter++;
	}

	fin.close();

	cout << "Array : \t";
	for (int count = 0; count < size; count++)
	{
		cout << *(array + count) << '\t';
	}
	cout << endl << endl;

	newMarks = retake(newMarks);

	array = regrow(array, size, newMarks);

	size++;

	cout << "\n\nArray : \t";
	for (int count = 0; count < size; count++)
	{
		cout << *(array + count) << '\t';
	}
	cout << endl << endl;

	ofstream fout("Marks.txt");

	fout << size << endl;

	for (int count = 0; count < size; count++)
	{
		fout << *(array + count) << '\t';
	}

	system("PAUSE");
	return 0;
}

float retake(float newMarks)
{
	cout << "Enter the marks of the quiz which was retaken : ";
	cin >> newMarks;

	return newMarks;
}

float *regrow(float *oldArray, int size, float newMarks)
{
	float *newArray = new float[size + 1];

	copy(oldArray, size, newArray);

	delete[] oldArray;
	oldArray = NULL;

	*(newArray + size) = newMarks;

	return newArray;
}

void copy(float *oldArray, int size, float *newArray)
{
	for (int count = 0; count < size; count++)
	{
		*(newArray + count) = *(oldArray + count);
	}
}