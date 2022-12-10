#include <iostream>
using namespace std;
int main()
{
	int num1 = 0, num2 = 0;
	char choice = 'Y';
	
	while(choice == 'Y' || choice == 'y')
	{
		num1 = rand() % 100;

		while (num1 != num2) {
			cout << "Guess the number (0 to 100) : ";
			cin >> num2;
			cout << endl;

			while(num2 <= 0 || num2 >= 100) {
			cout << "WRONG INPUT! \n";
			cout << "Guess the number (0 to 100) : ";
			cin >> num2;
			cout << endl;
			}
 
			if (num1 == num2) {
				cout << "Correct Guess! \n";
			}

			else if (num2 > num1) {
				cout << "Wrong Guess! \n Your number is greater than our number \n Guess Again! \n\n";
			}

			else {
				cout << "Wrong Guess! \n Your number is smaller than our number \n Guess Again! \n\n";
			}

		}

		cout << "If you want to guess again then press Y/y : ";
		cin >> choice;
		cout << endl;

	}

}