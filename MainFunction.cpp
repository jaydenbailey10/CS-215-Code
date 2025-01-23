/*
 * course: CS215-00x
 * Project: Lab 10 (as part II of Project 2)
 * Purpose: this program can be used as a math tutor for a young student:
 *                       In the first week of November, the topic is multiplication questions.
 *          This program focuses on testing the class definition of MathReport class, as the second part of Project 2.
 *          It shows FIVE questions ("hard-coded" questions) for the student to solve
 *          For each question, the program should wait for the student to enter the answer:
 *              if the answer is correct, a message of congratulations should be printed;
 *              if the answer is not correct, a sorry message should be printed (however DO NOT show the correct answer since the student can practice again).
 *          After FIVE questions are done, there are two cases:
 *              Case 1: if the student answers all questions correctly, it should generate a report which contains the following information then quit the program;
 *                         (1) the number of questions the student has solved;
 *                         (2) the list of questions the student has solved with correct answers;
 *                         (3) the number of questions the student answered correctly;
 *                         (4) the number of questions the student made mistakes;
 *                         (5) followed by "Great job!" message then directly quit the program
 *              Case 2: if the student answers at least one question wrong, it should first generate a report which contains the following information:
 *                         (1) the number of questions the student has solved;
 *                         (2) the list of questions the student has solved without answers;
 *                         (3) the number of questions the student answered correctly;
 *                         (4) the number of questions the student made mistakes;
 *                         (5) display either "Great job!"(if (2) > (3)) or "You will do better next time..." (otherwise),
 *                      then the program should provide the student at maximum THREE times to practice the wrong questions again:
 *                                                   During the practice, only if the answer is correct, the question will be removed from the practice list.
 *                                                   After THREE times, the program should generate a final report then quit the program:
 *                                                                      (1) the number of questions the student has solved;
 *                                                                      (2) the list of questions the student has solved without answers;
 *                                                                      (3) the number of questions the student answered correctly;
 *                                                                      (4) the number of questions the student made mistakes;
 *                                                                      (5) display either "Great job!"(if (2) > (3)) or "You will do better next time..." (otherwise)
 * Author: Jayden Bailey
 */

#include <iostream>
#include <string>
#include "MathOperations.h"
#include "MathReport.h"

using namespace std;

int main()
{
    // define some constants for "hard-coded" questions
    const int OP1_STARTNUM = 25;
    const int NUM_QUESTIONS = 5;
    const int OP2 = 9;
    const int MAX_PRACTICE = 3;

    cout << "\tMonth-at-a-Glance (MAAG) of November" << endl;
    cout << "\tMath Is Fun! Try to solve Multiplication problems..." << endl;

    int op1;                    // The first operand
    int op2 = OP2;              // The second operand
    int studentAnswer;          // The student's answer
    MathOperations question;    // the question for user to solve
    MathReport userReport;  // The user report for using Math Tutor program

    for (op1 = OP1_STARTNUM; op1 < OP1_STARTNUM + NUM_QUESTIONS; op1++)
    {
        question.setOperands(op1, op2);
        question.Multiplication();
        // Display the question and collect the user input
        studentAnswer = question.collectUserAnswer();
        if (question.checkAnswer(studentAnswer))
            cout << "Congratulations! " << studentAnswer << " is the right answer." << endl;
        else
            cout << "Sorry, the answer is wrong. You may practice again." << endl;
        //add the current question and the user answer into the user report
        userReport.insert(question, studentAnswer);
        cout << endl << endl;
    }

    // generate the user report for using Math Tutor
    cout << endl;
    bool withAnswer = true;

    if (userReport.getNumOfWrongAnswers() != 0)
    {
        withAnswer = false;
        userReport.generateReport(withAnswer);
        string option;
        bool morePractice = true;

        // allow the user to practice at maximum 3 times of questions with wrong answer
        int i = 0;
        while (morePractice && i < MAX_PRACTICE)
        {
            morePractice = userReport.needMorePractice();
            i++;
        }

        if (morePractice && i == MAX_PRACTICE)
        {
            cout << "Sorry! You have reached a maximum of " << MAX_PRACTICE << " times of practice!" << endl << endl;
        }
        withAnswer = true;
    }

    userReport.generateReport(withAnswer);
    cout << "Thank you for using Math Tutor." << endl;
    return 0;
}






#include <iostream>
#include "MathOperations.h"
#include "MathReport.h"
#include <limits>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

// Displaying welcome message
void displayWelcomeMessage() {
    cout << "Four basic Math operations are: + - * " << DivisionSymbol << endl;
    cout << "They are considered to be the cornerstone of Math." << endl;
    cout << "I am your online math tutor, my name is Yi Pike" << endl;
    cout << "I will help you build skills in Mathematics." << endl;
    cout << "You will gain confidence by practicing some questions." << endl;
}

// Display the main menu
void displayMenu() {
    cout << "Challenge Activities in CS215 Math Tutor" << endl;
    cout << "Math Is Fun! Take a challenge..." << endl;
    cout << "-----------------------------------------" << endl;
    cout << "1. Addition problem" << endl;
    cout << "2. Subtraction problem" << endl;
    cout << "3. Multiplication problem" << endl;
    cout << "4. Division problem" << endl;
    cout << "5. Quit this program" << endl;
    cout << "-----------------------------------------" << endl;
}

// Validate the user’s choice for the menu
int getValidMenuChoice() {
    int choice;

    while (true) {
        cout << "Enter your choice (1-5): ";

        if (cin >> choice) {
            if (choice >= 1 && choice <= 5) {
                return choice;
            }
            else {
                cout << "Invalid choice! The valid choices are 1, 2, 3, 4, and 5." << endl;
            }
        }
        else {
            // Handle non-numeric input
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a number between 1 and 5." << endl;
        }
    }
}

// Function to generate and check addition problem
bool askAddition() {
    int num1 = rand() % 999 + 1;
    int num2 = rand() % 999 + 1;
    int correctAnswer = num1 + num2;
    int userAnswer;

    cout << num1 << "\n+ " << num2 << "\n-----\n";
    cout << "Please type your answer: ";

    while (true) {
        if (cin >> userAnswer) {
            if (userAnswer == correctAnswer) {
                cout << "Congratulations! " << userAnswer << " is the right answer." << endl;
                return true;
            }
            else {
                cout << "Sorry, the answer is wrong. You may practice again." << endl;
                cout << "Please type your answer: ";
            }
        }
        else {
            cout << "Invalid input! Please enter a valid number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please type your answer: ";
        }
    }
}

// Function to generate and check subtraction problem
bool askSubtraction() {
    int num1 = rand() % 999 + 1;
    int num2 = rand() % 999 + 1;
    if (num1 < num2) {
        swap(num1, num2);  // Ensure the result is non-negative
    }
    int correctAnswer = num1 - num2;
    int userAnswer;

    cout << num1 << "\n- " << num2 << "\n-----\n";
    cout << "Please type your answer: ";

    while (true) {
        if (cin >> userAnswer)
        {
            // Ignore anything left in the input stream after reading the number
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (userAnswer == correctAnswer)
            {
                cout << "Congratulations! " << userAnswer << " is the right answer." << endl;
                return true;
            }
            else
            {
                cout << "Sorry, the answer is wrong. You may practice again." << endl;
                cout << "Please type your answer: ";
            }
        }
        else
        {
            cout << "Invalid input! Please enter a valid number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please type your answer: ";
        }
    }
}

// Function to generate and check multiplication problem
bool askMultiplication()
{
    int num1 = rand() % 98 + 2;  // Between 2 and 99
    int num2 = rand() % 8 + 2;   // Between 2 and 9
    int correctAnswer = num1 * num2;
    int userAnswer;

    cout << num1 << "\n* " << num2 << "\n-----\n";
    cout << "Please type your answer: ";

    while (true) {
        if (cin >> userAnswer)
        {
            // Ignore anything left in the input stream after reading the number
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (userAnswer == correctAnswer)
            {
                cout << "Congratulations! " << userAnswer << " is the right answer." << endl;
                return true;
            }
            else
            {
                cout << "Sorry, the answer is wrong. You may practice again." << endl;
                cout << "Please type your answer: ";
            }
        }
        else
        {
            cout << "Invalid input! Please enter a valid number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please type your answer: ";
        }
    }
}

// Function to generate and check division problem
bool askDivision() {
    int num1 = rand() % 98 + 2;  // Between 2 and 99
    int num2 = rand() % 8 + 2;   // Between 2 and 9
    int correctAnswer = num1 / num2;
    int userAnswer;

    cout << num1 << "\n " << DivisionSymbol << num2 << "\n-----\n";
    cout << "Please type your answer: ";

    while (true) {
        if (cin >> userAnswer)
        {
            // Ignore anything left in the input stream after reading the number
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (userAnswer == correctAnswer)
            {
                cout << "Congratulations! " << userAnswer << " is the right answer." << endl;
                return true;
            }
            else {
                cout << "Sorry, the answer is wrong. You may practice again." << endl;

            }
        }
        else {
            cout << "Invalid input! Please enter a valid number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please type your answer: ";
        }
    }
}

int main()
{
    srand(time(0));

    displayWelcomeMessage();

    vector<string> questionsAttempted;
    vector<int> correctAnswers;
    vector<int> incorrectAnswers;

    while (true) {
        displayMenu();
        int choice = getValidMenuChoice();

        if (choice == 5) {
            // Quit the program and show results
            cout << "You have solved the following " << questionsAttempted.size() << " math problems:" << endl;
            for (size_t i = 0; i < questionsAttempted.size(); ++i) {
                cout << questionsAttempted[i] << endl;
            }
            cout << "You answered " << correctAnswers.size() << " questions correctly." << endl;
            cout << "You made " << incorrectAnswers.size() << " mistakes." << endl;

            if (!incorrectAnswers.empty()) {
                cout << "Do you want to practice the questions with wrong answers? (enter 'Q' or 'q' to quit): ";
                char practiceChoice;
                cin >> practiceChoice;
                if (practiceChoice != 'Q' && practiceChoice != 'q') {
                    for (int wrongAnswer : incorrectAnswers) {
                        // Practice wrong answers again
                        cout << "Practicing question: " << wrongAnswer << endl;
                    }
                }
            }

            cout << "I am your online Math Tutor, Jayden Bailey. See you next time." << endl;
            break;
        }

        bool correct = false;
        string question;
        int userAnswer = 0;

        switch (choice) {
        case 1: {
            int num1 = rand() % 999 + 1;
            int num2 = rand() % 999 + 1;

            cout << question << endl;
            correct = askAddition();
            break;
        }
        case 2: {
            int num1 = rand() % 999 + 1;
            int num2 = rand() % 999 + 1;
            if (num1 < num2) swap(num1, num2);

            cout << question << endl;
            correct = askSubtraction();
            break;
        }
        case 3: {
            int num1 = rand() % 98 + 2;
            int num2 = rand() % 8 + 2;

            cout << question << endl;
            correct = askMultiplication();
            break;
        }
        case 4: {
            int num1 = rand() % 98 + 2;
            int num2 = rand() % 8 + 2;
            cout << question << endl;
            correct = askDivision();
            break;
        }
        }

        // Update vectors based on results
        questionsAttempted.push_back(question);
        if (correct) {
            correctAnswers.push_back(userAnswer); // Push correct answer for tracking
        }
        else {
            incorrectAnswers.push_back(userAnswer); // Push incorrect answer for practice
        }
    }
}