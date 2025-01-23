#include "SuperString.h"
#include<stack>
#include <iostream>

SuperString::SuperString(string ini_str)
{
	str = ini_str;
}

string SuperString::getString() const
{
	return str;
}

void SuperString::setString(string input_str)
{
	str = input_str;
}

string SuperString::rev_loop() const
{
	string reversed; 
	for (int i = str.length() - 1; i >= 0; i--)
	{
		reversed += str[i]; // add the characters in reversed order 
	}
	return reversed;;
}
string reverseRecursively(const string& input, int start, int end)
{
	if (start >= end) {
		return ""; // Base case: when the indices cross, return empty string
	}
	// Build the reversed string by concatenating characters
	return input[end - 1] + reverseRecursively(input, start, end - 1);
}
string SuperString::rev_recursion() const
{
	return reverseRecursively(str, 0, str.size());
}

string SuperString::rev_stack() const
{
	stack<char> charStack;
	string reversed = "";
	
	//push all characters of str onto the stack
	for (char ch : str)
	{
		charStack.push(ch);
	}
	//pop characters to reverse
	while (!charStack.empty())
	{
		reversed += charStack.top();
		charStack.pop();
	}
	return reversed; // returns the reversed string entered
}

bool SuperString::isPalindrome() const
{
	string reversed = rev_loop(); //use rev_loop() to reverse the string 
	return str == reversed; // compare original and reversed strings 
}

bool SuperString::isPalindrome_recursion() const
{
	//base case
	if (this->str.length() <= 1)
		return true; //base case
	
	//recursive step
	string middle = this->str.substr(1, this->str.length() - 2);
	SuperString subSS(middle);
	return subSS.isPalindrome_recursion() && str.at(0) == str.at(str.length() - 1);
	
}

void SuperString::print() const
{
	cout << str<<endl;
}


