/* Course: CS 215-005
* Project: Lab 3 Increasing and Decreasing
* Purpose: to get familiar with Microsoft Visual Studio IDE.,
* to continue practicing using input/output.
* to continue practicing using variables,fundamental data types, and basic operations.
* to practice using nested conditional statements. 
* Author: Jayden Bailey 
*/

#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main()

{
	char choice;

	cout << " Your wish is my command!" << endl;
	cout << "I will sort three numbers under your wish" << endl;
	cout << "Enter I for increasing order, D for decreasing order (I or D): ";
	
	cin >> choice;

	if (choice != 'I' && choice != 'i' && choice != 'D' && choice != 'd')
	{
		cout << "Invalid choice, program is quitting now..." << endl;
		return 0;
	}
	//user inputs there numbers.

	cout << "Please enter three integers:";
	int num1, num2, num3;
	cin >> num1 >> num2 >> num3;
	
	//this is for increasing order

	if (choice == 'I' || choice == 'i')
	{

		
		if (num1 > num2)
		{
			//Swap num1 and num2
			int k = num1;
			num1 = num2;
			num2 = k;
		}
		if (num2 > num3)
		{
			//Swap num2 and num3
			int k = num2;
			num2 = num3;
			num3 = k;
		}
		if (num1 > num2)
		{
			int k = num1;
			num1 = num2;
			num2 = k;
		}
		cout << " Numbers are sorted in increasing order!" << endl;
		
		cout <<num1<< "--> "<< num2 <<"--> "<< num3 << endl;
		
		//strictly increasing leniently and leniently

		if (num1 == num2 || num2 == num3)
		{
			cout << "Numbers are in leniently increasing order!" << endl;
		}
		else
			cout << "Numbers are in strictly increasing order!" << endl;
	}
	
	else if (choice == 'D' || choice == 'd')
	{
		//sort in decreasing order
		
		//swap num1 and num2
		
		if (num1 < num2)
		{
			int k = num1;
			num1 = num2;
			num2 = k;
		}
		
		// swap num2 and num3
		
		if (num2 < num3)
		{
			int k = num2;
			num2 = num3;
			num3 = k;
		}
		
		//swap num1 and num2
		
		if (num1 < num2)
		{
			int k = num1;
			num1 = num2;
			num2 = k;
		}
		cout << "Numbers are sorted in decreasing order!" << endl;
		cout << num1 << "<-- " << num2 << "<-- " << num3 << endl;
		//strictly decreasing leniently and leniently 
		//strictly increasing leniently and leniently

		if (num1 == num2 || num2 == num3)
		{
			cout << "Numbers are in leniently decreasing order!" << endl;
		}
		else
			cout << "Numbers are in strictly decreasing order!" << endl;
	

	}
	return 0;
}







		