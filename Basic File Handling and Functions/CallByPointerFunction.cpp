#include<iostream>
using namespace std;

int add(int*, int*);

int main()
{
	int x = 10, y = 20;

	cout << "BEFORE CALLING FUNCTION! \n\n";
	cout << x << endl;
	cout << y << endl;
	cout << x + y;

	cout << "\n\nFUNCTION CALL! \n";
	cout << add( &x, &y);

	cout << "\n\nAFTER CALLING FUNCTION! \n\n";
	cout << x << endl;
	cout << y << endl;
	cout << x + y;

	return 0;
}

int add(int* a, int* b)
{

	*a += 10;
	*b += 10;

	return *a + *b;
}