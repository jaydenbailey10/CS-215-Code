/*
 * Course: CS215-005
 * Project: Lab6 (as part of Project 1)
 * Purpose: It demonstrates the game of Nim played between two computer players
 *          In combinatorial game theory, a two-player deterministic perfect information turn-based game
 *          is a first-player-win if with perfect play the first player to move can always force a win.
 *          This program also shows that the game of Nim is a "CONDITIONAL first-player-win" game using two computer players.
 * Author: Jayden Bailey
 */
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <string>

using namespace std;

// define some constants
const int PILE_MAX = 50;
const int PILE_MIN = 10;
const char MARBLE = static_cast<char>(232);  //use code 232 in ASCII Table to represent marble
const int WIDTH = 10;   // for layout purpose
const int PILE_SIZE_TEST = 33;		//the pile size for testing purpose in Lab6 only

bool isPowerOfTwoMinusOne(int number)
{
    int pow = 1;
    while (pow - 1 < number) // Increase powers of 2 and check if pow - 1 is less than the number
    {
        pow *= 2; // Double the value of pow (goes from 1, 2, 4, 8, etc.)
    }
    if ((pow - 1) == number) // Check if pow-1 equals the number
    {
        return true; //  return true if the number is a Power - of - Two - minus - One
    }
    else
    {
        return false; // reutrn false if it isn't a power of two minus 1
    }
}

/*
 * This function represents the legal move when it is the computer's turn to play
 * The computer takes “smart strategy” trying to win the game:
 * (1) If the current pile size is not a Power-of-Two-minus-One,
 * it takes enough marbles to make the remaining size a Power-of-Two-minus-One number.
 * (2) If the current pile size is already a Power-of-Two-minus-One,
 * it makes a random move taking at least one but at most half.
 */

void computer_play(int& pile) {
    if (isPowerOfTwoMinusOne(pile)) {
        // Make a random move taking at least 1 and at most half
        int maxTake = pile / 2;
        int marblesTaken = 1 + rand() % maxTake; // At least 1, at most half
        cout << "Computer takes " << marblesTaken << " marbles." << endl;
        pile -= marblesTaken;
    }
    else {
        // Find the nearest Power-of-Two-minus-One less than the pile size
        int target = pile;
        while (!isPowerOfTwoMinusOne(target) && target > 1) {
            target--;
        }
        // Calculate the marbles to take to reach that target
        int marblesToTake = pile - target;
        cout << "Computer takes " << marblesToTake << " marbles." << endl;
        pile -= marblesToTake;
    }
}

void printMarbles(int pile) // prints the marbles after each transition
{
    cout << "There are " << pile << " marbles in the pile:" << endl;
    for (int i = 0; i < pile; i++) {
        cout << "\t " << MARBLE << "\n "; // Display each marble vertically
    }
}
void player_play(int& pile) //creates the player for us to be a user
{
    bool test = true;
    while (test)
    {
        cout << "It is your turn to play... You may take 1 to " << (pile / 2) << " marbles.\n" << endl;
        cout << "You take: ";
        int amounttook;
        cin >> amounttook;
        if (amounttook > 0 && amounttook <= (pile / 2)) // user to take marbles between 1-half the pile left
        {
            cout << " You took " << amounttook << " marbles. " << endl << endl;
            pile = pile - amounttook;
            test = false; // subtracts the amount chosen from the pile and begins the cycle again with the computer choosing then the user again.
        }
        else if (cin.fail())//clears the input for the user to try again after inputting a invalid input
        {
            cin.clear();
            cin.ignore(256, '\n');
            cout << " Input is not allowed, please try again!\n";
        }
        else //clears the input for the user to try again after inputting a invalid input
        {
            cin.clear();
            cin.ignore(256, '\n');
            cout << " Input is not allowed, please try again!\n";
        }
    }
}



int main()
{

    int seed = static_cast<int>(time(0));
    srand(seed);

    // Generate the initial size of pile (of marbles)
    // at the range of [PILE_MIN, PILE_MAX]
    // for testing purpose only: we "hard-code" the initial size of pile to a constant PILE_SIZE_TEST
    int pileSize = PILE_SIZE_TEST;

    // comment out the testing purpose at line number 40, enable the following statement, which is the general case
    //int pileSize = PILE_MIN + rand() % (PILE_MAX - PILE_MIN + 1);
    int turn = rand() % (2);
    string firstname, lastname;
    cout << "Welcome to the game of CS215 Nim (for two players)" << endl;
    cout << "Please input your name:";
    cin >> firstname;
    cin >> lastname;
    cout << "**********************************************************************" << endl;
    cout << "*                       The game of CS215 Nim                         *" << endl;
    cout << "*               Two players alternate taking at least one             *" << endl;
    cout << "*                        but at most half                             *" << endl;
    cout << "*                   of the marbles in the pile.                       *" << endl;
    cout << "*             The player who takes the last marble loses.             *" << endl;
    cout << "*                      It is written by Jayden Bailey                 *" << endl;
    cout << "*                   I hope you beat the computer :)                   *" << endl;
    cout << "*                  No matter what, have a great day!                  *" << endl;
    cout << "**********************************************************************" << endl;

    

    // The Nim game starts here
    // two players take a turn to play, until the pile size reaches 1
    while (pileSize > 1)
    {
        printMarbles(pileSize);

        if (turn==0) //it is computer's turn to play
        {
            cout << "It is computer's turn:" << endl;
            computer_play(pileSize);
            turn = 1;
        }
        else   // it is user's turn to play
        {
            cout << "It is your turn:" << endl;
            player_play(pileSize);
            turn = 0;

        }

      
    }

    //check which one has to take the last marble to lose the game
    if (turn ==0)  // PIKE's turn (for this program, under the "hard-coded" testing case, this will never happen as long as PIKE is the first player!
    {
        cout << "Computer must take the last marble. "
            << "You win!" << endl;
    }
    else   // User's turn
    {
        cout << "You must take the last marble. "
            << "Computer wins!" << endl;
    }

    return 0;
}
