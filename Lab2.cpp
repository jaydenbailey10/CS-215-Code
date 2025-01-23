/*Author: Jayden Bailey
* Project:Lab 2
*  Purpose: to get familiar with Microsoft Visual Studio IDE.
* to practice using input / output.
* to practice using variables, constants, fundamental data types and basic operations.
* to practice using simple conditional statement.
*/ 
#include<iostream>
#include<iomanip> //settting output width
using namespace std;
int main()
{
	double amount_due;
	double amount_received;
	const int Dollars = 100;
	const int Quarters = 25;
	const int Dimes = 10;
	const int Nickels = 5;
	const int Pennies = 1;
	int due = 0;
	
	cout << " Enter the amount due : $ ";
	cin >> amount_due;
	cout << " The amount received : $ ";
	cin >> amount_received;
	int change_in_cents = static_cast<int>(100 * (amount_due - amount_received) + 0.5);

	cout << "Here is how much you will have to pay" << endl;
	
		if (change_in_cents > 0)
	{
		cout << "Amount received isn't enough!" << endl;
	}
	else if (change_in_cents == 0)
	{
		cout << "Perfect payment, no change needed!" << endl;
		return 0;
	}
	else
	{
			change_in_cents = static_cast<int>(100 * (amount_due - amount_received) -0.5);
			change_in_cents = abs(change_in_cents);
		cout << " Your change to be given back is" << endl;
	
	}
	
		due = change_in_cents / Dollars;
		cout << "	Dollars:" << setw(6) << due << endl;
		change_in_cents = change_in_cents % Dollars;
		due = change_in_cents / Quarters;
		cout << "	Quarters:" << setw(5) << due << endl;
		change_in_cents = change_in_cents % Quarters;
		due = change_in_cents / Dimes;
		cout << "	Dimes:  " << setw(6) << due << endl;
		change_in_cents = change_in_cents % Dimes;
		due = change_in_cents / Nickels;
		cout << "	Nickels:" << setw(6) << due << endl;
		change_in_cents = change_in_cents % Nickels;
		due = change_in_cents / Pennies;
		cout << "	Pennies:" << setw(6) << due << endl;
		change_in_cents = change_in_cents % Pennies;





}