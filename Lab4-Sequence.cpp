/* Course: CS 215-005
* Project: Lab 4 Number Sequences
* Purpose: 
* to continue practicing conditional statements
* to practice loop statements
* Author: Jayden Bailey
*/

#include<iostream>
#include<string>
#include<algorithm>

using namespace std;


    bool isPrime(int n) 
    {
        if (n <= 1) return false;
        for (int i = 2; i * i <= n; i++) 
        {
            if (n % i == 0) return false;
        }
        return true;
    }

    // Function to check if a number is a "Power of Two Minus One"
    bool isPowerOfTwoMinusOne(int n) 
    {
        if (n <= 0) return false;
        int power = 1;
       
        while ((1 << power) - 1 <= n)
        {  // 1 << power is 2^power
            if ((1 << power) - 1 == n)
                return true;
            power++;
        }
        return false;
    }

    int main()
    {
        int input;
        int cumulativeTotal = 0;
        int primeCount = 0;
        int sum = 0;
   

        while (true)
        {
            cout << "Welcome to CS215 number sequence!" << endl;
            cout << "Enter positive integers (enter -1 to quit):" << endl;
            cin >> input;

            if (input == -1) break;  // Quit condition

            if (input > 0) {
                // Update cumulative total
                cumulativeTotal += input;
                cout << "The corresponding  element for the cumulative total sequence  is :" << cumulativeTotal << endl;
                
                // Check if it's a power of two minus one
                if (isPowerOfTwoMinusOne(input))
                {
                    cout << input << " is a power of Two Minus One." << endl;
                }
                else 
                {
                    cout << input << " is not a power of Two Minus One." << endl;
                }

                // Check if it's a prime number
                if (isPrime(input)) {
                    cout << input << " is a prime number." << endl;
                    primeCount++;
                }
                else {
                    cout << input << " is not a prime number." << endl;
                }

                // Add input to total sum
                sum += input;
                
            }
            else 
            {
                cout << "Expecting a positive integer, please try again... " << endl;
               
            }
          
        }


        // After user quits
         if (sum)
         {
             cout << "The sum of all positive numbers entered is: " << sum << endl;
             cout << "The number of Prime numbers among them is: " << primeCount << endl;
         }
         else
         {
             cout << "No positive integer entered!" << endl;
         }
         cout << "Have a great day!" << endl;

        return 0;
    
}