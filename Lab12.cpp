/*
 * Course: CS215-00x
 * Project: Lab 12
 * Purpose: To reverse each text line, say original,
 *          either from the specified file passing as the command line argument
 *          or from the user input
 *          and then decide if each of original,
 *          is a palindrome or not
 ******PLEASE DO NOT CHANGE THIS FILE!******
 *
 */

#include <iostream>
#include <string>
#include <fstream>
#include "SuperString.h"

using namespace std;

int main(int argc, char* argv[])
{
    const int NO_COMMD_ARG = 1;  //running program without command line argument: argc = 1
    const int COMMD_ARG = 2;     //running program with one command line argument: argc = 2

    // check if the number of command line arguments is correct
    if (argc < NO_COMMD_ARG || argc > COMMD_ARG)
    {
        cout << "Usage: " << argv[0] << "  or " << argv[0] << " <filename>" << endl;
        return 1;
    }
    // if there is no command line argument, read the standard input from the keyboard
    if (argc == NO_COMMD_ARG)
    {
        string original;
        cout << "Welcome to CS215 Super String operations! " << endl;
        cout << "Please input a string to watch its magic: " << endl;
        getline(cin, original);

        // Stop the loop when the user clicks Ctrl-z
        while (!cin.eof())
        {
            // create s SuperString object
            SuperString magic(original);
            cout << "The original string you type is: ";
            magic.print();
            cout << "Reverse of the string (using a loop): " << magic.rev_loop() << endl;
            cout << "Reverse of the string (using recursion): " << magic.rev_recursion() << endl;
            cout << "Reverse of the string (using a stack): " << magic.rev_stack() << endl << endl;

            // when the boolalpha format flag is set, bool values are represented as true or false, instead of integral values
            // for standard streams, the boolalpha flas is not set on initialization
            cout << boolalpha;
            cout << "Is \" " << magic.getString() << " \" a palindrome? " << endl;
            // note that the following two answers should always be the same
            cout << "Calling member function to decide, the answer is: " << magic.isPalindrome() << endl;
            cout << "Using recursion to decide, the answer is: " << magic.isPalindrome_recursion() << endl;

            // asking for another input string...till the user clicks Ctrl-d
            cout << endl << endl;
            cout << "Please input a string to watch its magic: " << endl;
            getline(cin, original);
        }
        return 0;
    }
    // if there is one command line argument, read each line from the input file 
    else
    {
        string original;
        ifstream inFile;
        inFile.open(argv[1]);
        if (!inFile.good())
        {
            cout << "File open failure!" << endl;
            return 1;
        }
        //display each text lines from the file in original order, then followed by reversed order
        cout << "Welcome to CS215 Super String operations! " << endl;
        cout << "Display each text line from the file in original order, then followed by the reverse order: " << endl;
        while (getline(inFile, original))     // it also contains eof check, avoid an extra line
        {
            SuperString magic(original);
            magic.print();
            cout << "--> " << magic.rev_recursion() << endl;
        }
        inFile.close();
        return 0;
    }
}
