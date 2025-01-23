/*course: CS215 - 005
 *Project: Lab 5
 *Purpose:  
 *to continue practicing loop statements
 *to define your own functions
 *to get familiar with the Visual Studio debugger

 *
 *Author: Jayden Bailey
 */

#include <iostream> 
#include <iomanip> 
#include <limits>    
#include<cmath>
using namespace std;

// Function to check if a number is of the form 2^n - 1
// & sets changes made inside the function would only affect a copy
// leaving the original variable unchanged.
bool create_PowerOfTwoMinusOne(int num, int& end) {
    // initialize power to be 1(2^0)
    int power = 1;
    //keeps doubling until power-1 is greater than the initial num
    while ((power - 1) <= num) {
        // goes to the next  power of two
        power *= 2;
    }
    // Set goal to the largest power-of-two-minus-one <= num
    end = power / 2 - 1;
    // Return true if num is a power-of-two-minus-one
    return end == num;
}

// Function to draw a symmetric triangle
void drawTri(int n) {
    // the outer loop runs from 1 to n where i is the current row number increasing by 1
    for (int i = 1; i <= n; i++) {
        // Print spaces for centering increasing by 1 till you get to n
        for (int j = 0; j < n - i; j++) {
            cout << " ";
        }
        // second loop that prints the stars and increases with each row
        for (int j = 0; j < 2 * i - 1; j++) {
            cout << "*";
        }
        cout << endl;
    }
}

// Function to draw a triangle rotated 90 degrees clockwise
void drawTriR90(int n) {
    // First, draw the top of the triangle by printing stars for each row from 1 to n
    for (int i = 1; i <= n; i++) {
        // Print stars equal to the row number
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }

    // Now draw the bottom half in reverse order from n-1 down to 1
    for (int i = n - 1; i >= 1; i--) {
        // Print stars equal to the row number
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }
}

int main() {
  
    cout << "Welcome to CS 215 Pattern Match!" << endl;
    cout << "First I will demonstrate two triangle patterns for you." << endl;
    cout << " One with the size 5." << endl;
    drawTri(5);
    cout << "... followed by the roation of 90 degrees clockwise." << endl;
    drawTriR90(5);
        cout << endl << " Another one witrh the size:12" << endl; 
        drawTri(12);
        cout << endl << " followed by tge rotation of 90 degrees clockwise." << endl;
        drawTriR90(12);



    
    while (true) {
        cout << "I will play Pattern Match as you wish!" << endl;

        int input, end;
        cout << "Please enter a positive integer (enter -1 to quit) for the longest row of stars: ";
        cin >> input;

        if (input == -1) {
            // Exit the loop if the user enters -1
            cout << "Thank you, have a great day!" << endl;
            break;
        }

        if (input < 1) {
            // Restart the loop and prompt again
            cout << "Expecting a positive integer, please try again..." << endl;
            continue;
        }

        // Output the user input
        cout << "You enter: " << input << endl;

        // Check if the input is a power of two minus one
        if (create_PowerOfTwoMinusOne(input, end)) {

            cout << "It is a Power of Two Minus One number." << endl;
            cout << "I will EXACTLY match your desired number of stars in the last row!" << endl;
        }
        else {
            cout << "It is NOT a Power of Two Minus One number." << endl;
            cout << "I will just match the closest Power of Two Minus One number of stars in the last row:)" << endl;
        }

        // Print the triangle based on the goal
        cout << "The triangle with " << end << " number of stars at the longest row" << endl;
        cout << "Here comes the triangle with size " << (end + 1) / 2 << " :" << endl;
        drawTri((end + 1) / 2);

        cout << "...followed by the rotation for 90 degrees clockwise:" << endl;
        drawTriR90((end + 1) / 2);
    }

    return 0;
}
