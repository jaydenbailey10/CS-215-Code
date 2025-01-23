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

using namespace std;

// define some constants
const int PILE_MAX = 50;
const int PILE_MIN = 10;
const char MARBLE = static_cast<char>(232);  //use code 232 in ASCII Table to represent marble
const int WIDTH = 10;   // for layout purpose
const int PILE_SIZE_TEST = 33;		//the pile size for testing purpose in Lab6 only


// represent the legal move when it is the computer's turn to play the game
void computer_play(int& pile);

// display marbles on the pile
void printMarbles(int pile);

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

    cout << "**********************************************************************" << endl;
    cout << "* In combinatorial game theory:                                      *" << endl;
    cout << "*  a two-player deterministic perfect information turn-based game    *" << endl;
    cout << "*               is a first-player-win, if with perfect play          *" << endl;
    cout << "*       the first player to move, can always force a win.            *" << endl;
    cout << "*   I will show you (not prove to you) that                          *" << endl;
    cout << "*       the game of Nim is a CONDITIONAL first-player-win game :)    *" << endl;
    cout << "*                       The game of CS215 Nim                        *" << endl;
    cout << "*   Two players alternate taking at least one but at most half       *" << endl;
    cout << "*                         of the marbles in the pile.                *" << endl;
    cout << "*   The player who takes the last marble loses.                      *" << endl;
    cout << "**********************************************************************" << endl;

    bool PIKE_turn = true;
    cout << "PIKE and SUPER are two computers. " << endl;
    cout << "They play the game of CS215 Nim." << endl << endl;
    cout << "PIKE always starts first!!! SUPER plays the second." << endl;
    cout << endl << endl;

    // The Nim game starts here
    // two players take a turn to play, until the pile size reaches 1
    while (pileSize > 1)
    {
        printMarbles(pileSize);

        if (PIKE_turn) //it is PIKE's turn to play
        {
            cout << "It is PIKE's turn:" << endl;
            computer_play(pileSize);
        }
        else   // it is SUPER's turn to play
        {
            cout << "It is SUPER's turn:" << endl;
            computer_play(pileSize);
        }

        PIKE_turn = !PIKE_turn;
    }

    //check which one has to take the last marble to lose the game
    if (PIKE_turn)  // PIKE's turn (for this program, under the "hard-coded" testing case, this will never happen as long as PIKE is the first player!
    {
        cout << "Computer PIKE must take the last marble. "
            << "Computer SUPER wins!" << endl;
    }
    else   // SUPER's turn
    {
        cout << "Computer SUPER must take the last marble. "
            << "Computer PIKE wins!" << endl;
    }

    return 0;
}

// Function to check if a number is a Power-of-Two-minus-One
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

void printMarbles(int pile) {
    cout << "There are " << pile << " marbles in the pile:" << endl;
    for (int i = 0; i < pile; i++) {
        cout << "\t " << MARBLE << "\n "; // Display each marble vertically
    }
}


