#include "MathOperations.h"
#include <iostream>
#include <iomanip>
using namespace std;

// default constructor
MathOperations::MathOperations()
{
	operand1 = 0;
	operand2 = 0;
	theoperator = 0;
	answer = 0;

}


// set the private data members: operand1 and operand2
	// to op1 and op2 respectively

void MathOperations::setOperands(int op1, int op2)
{
	operand1 = op1;
	operand2 = op2;
}

// get the current value of the private data member: theoperator

char MathOperations::getOperator() const
{
	return theoperator;
}

// return the value of the data member: answer

int MathOperations::getAnswer() const
{
	return answer;
}

// set theoperator to '+'
	// apply the addition operation to operand1 and operand2
	// set the answer equal to operand1 + operand2

void MathOperations::Addition()
{
	theoperator = '+';
	answer = operand1 + operand2;
}

// set theoperator to '-'
   // apply the subtraction operation to operand1 and operand2
   // set the answer equal to operand1 - operand2

void MathOperations::Subtraction()
{
	theoperator = '-';
	answer = operand1 - operand2;
}

// set theoperator to '*'
  // apply the multiplication operation to operand1 and operand2
  // set the answer equal to operand1 * operand2

void MathOperations::Multiplication()
{
	theoperator = '*';
	answer = operand1 * operand2;
}

// set theoperator to const DivisionSymbol, it is ASCII code for obelus
 // apply the division operation to operand1 and operand2
 // set the answer equal to operand1 ÷ operand2

void MathOperations::Division()
{
	theoperator = DivisionSymbol;
	answer = operand1 / operand2;
}

// if answer == response, it returns true
   // otherwise it returns false

bool MathOperations::checkAnswer(int response) const
{
	if (answer == response)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//display the question in the format described in the problem statement
	// for example:
	//    135
	//  +  78
	//  _____
	//

void MathOperations::print() const
{
	cout << "" << setw(5) << operand1 << endl;
	cout << theoperator << "" << setw(4) << operand2 << endl;
	cout << "_____" << endl;
}

// display the question by calling print() first
	// then ask the user for the answer
	// it returns the valid user answer collected from the user input

int MathOperations::collectUserAnswer() const
{
	print(); //display the math question to the user

	int userAnswer; //variable to store the user's answer

	cout << "Please type your answer" << endl;

	cin >> userAnswer;

	//loop to handle invalid inputs until a valid integer is entered
	while (cin.fail()) // check if input is invalid
	{
		cout << "Invalid input! Please try again..." << endl;

		cin.clear(); //clears the invalid input

		cin.ignore(1000, '\n'); // ignore the rest of the line to remove the invalid input from the stream

		cout << "Please type your answer" << endl;

		cin >> userAnswer; //ask user to enter their answer again
	}
	cin.ignore(1000, '\n'); // ignore any remaining characters in the input buffer to prevent issues

	return userAnswer; // return the valid user answer
}

