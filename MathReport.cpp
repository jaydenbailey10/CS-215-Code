#include "MathReport.h"
#include "MathOperations.h"
#include <iostream>
#include<vector>
#include<list>
#include<iomanip>


using namespace std;

//Default constructor for MathReport, initializes correct and wrong answers
MathReport::MathReport()
{
	numCorrectAnswers = 0;
	numWrongAnswers = 0;
}

//inserts a new math question and the user's response into the report
void MathReport::insert(MathOperations newQuestion, int response)
{
	mathQuestions.push_back(newQuestion); //add a question to mathQuestion

	//check if the response is correct and update counters and lists accordingly
	if (newQuestion.checkAnswer(response))
	{
		numCorrectAnswers++; //updates the correct answer counter
	}
	else
	{
		numWrongAnswers++;//updates the wrong answer counter 
		errorList.push_back(newQuestion);// Add question to error list if incorrect
	}
}
//returns the number of correct answers recorded

int MathReport::getNumOfCorrectAnswers() const
{
	return numCorrectAnswers;
}

//returns the number of wrong answers recorded


// Generates a report of all questions and answers, with an option to show the correct answers
int MathReport::getNumOfWrongAnswers() const
{
	return numWrongAnswers;
}

void MathReport::generateReport(bool showAnswer) const
{
	if (showAnswer == true)
	{
		cout << "You have solved the following " << mathQuestions.size() << " math problems:" << endl;
		
		// Loop through each question in mathQuestions
		for (size_t i = 0; i < mathQuestions.size(); ++i)
		{
			cout << "Question " << i + 1 << ":" << endl;

			mathQuestions[i].print();//displays each question

			if (showAnswer)//display the answer if showAnswer is true
			{
				cout << mathQuestions[i].getAnswer() << endl;
			}
			cout << endl;
		}
		cout << "----------------------------------" << endl;
		cout << "You answered " << numCorrectAnswers << " questions correctly." << endl;
		cout << "You made " << numWrongAnswers << " mistakes." << endl;
		cout << "Great job!" << endl;
	}
	else
	{
		cout << "You have solved the following" << mathQuestions.size() << "math problems:" << endl;
	
		//loop through each question without showing answers
		for (size_t i = 0; i < mathQuestions.size(); ++i) //size_t represents the size of objects in memory
		{
			cout << "Question " << i + 1 << ":" << endl;

			mathQuestions[i].print(); if (errorList.empty())

			cout << endl;

		}
		cout << "----------------------------------" << endl;
		cout << "You answered " << numCorrectAnswers << " questions correctly." << endl;
		cout << "You made " << numWrongAnswers << " mistakes." << endl;
		
		// If there were no wrong answers, print a motivational message
		if (numWrongAnswers == 0)
		{
			cout << "You will do better next time..." << endl;
		}
		else
		{
			cout << "You will do better next time..." << endl;
		}

	}

}

// Provides practice for incorrectly answered questions, removes them from errorList once correct
bool MathReport::needMorePractice()
{
	int nextAnswer; //variable for user's next answer
	int i = 1;
	int max_practice = 3; //maximum practice attempts
	bool morepractice = true;
	
	// Loop through errorList, allowing user to retry incorrect questions
	for (auto it = errorList.begin(); it != errorList.end();)
	{
		MathOperations& question = *it;//reference to current question in error list

		nextAnswer = question.collectUserAnswer();//ask user for an answer

		if (question.checkAnswer(nextAnswer))
		{
			// If correct, increment correct answers, decrement wrong answers, remove from errorList
			cout << "Congratulations!" << nextAnswer << " is the right answer" <<endl;
			numCorrectAnswers++;
			numWrongAnswers--;
			it = errorList.erase(it);// Remove question from errorList and advance iterator
		}
		else
		{
			//if incorrect, prompt user to try again

			cout << "Sorry, your answer is incorrect. You may practice again" << endl;
			++it;
			//move to the next question without erasing
		}
	}
	if (errorList.empty()) // if all question are correct, no more practice is needed
	{
		cout << "Excellent! Your answers are all correct! No more practice is needed :)" << endl;
		return false;
	}

	//if there are still incorrect questions, suggest more practice.
	cout << "You still need more practice!" << endl;
	i++;
}
