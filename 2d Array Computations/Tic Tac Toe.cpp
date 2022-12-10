#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	char array[3][3] = { '\0' };

	cout << setw(72);
	cout << "TIC TAC TOE\n";

	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			cout << "place[" << row + 1 << "][" << col + 1 << "]" << "\t";
		}
		cout << endl << endl;
	}

	char p1 = '\0', p2 = '\0';

	cout << "Player one choose from O or X to continue the game : ";
	cin >> p1;



	system("PAUSE");
	return 0;
}