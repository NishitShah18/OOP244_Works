/*************************************************************************

Name			: Nishit Gaurang Shah
Student Num.		: 130 176 217
Email ID		: ngshah3@myseneca.ca
Section			: OOP244NFF

Date : 23rd May 2022

Autheticity Declaraition :
I declare that I have done all the coding by myself and only copied the
code that my professor provided to complete my workshops and assignments.

*************************************************************************/

// SAFE-GAURD
#ifndef QUIZZER_QUIZ_H
#define QUIZZER_QUIZ_H

namespace quizzer
{
	//////////////////////////
	// CONSTANT VARIABLES 
	//////////////////////////
	const int MAX_NO_OF_QUE = 60;
	const int MAX_NO_OF_ANS = 10;
	const int MAX_QUE_LENGTH = 1024;
	const int MAX_ANS_LENGTH = 128;

	//////////////////////////
	// STRUCTURES 
	//////////////////////////
	struct Answer
	{
		char option[4];
		char answerOption[MAX_ANS_LENGTH + 1];
	};

	struct Question
	{
		char type[5]; // "{mc}\0" or "{ma}\0"
		char question[MAX_QUE_LENGTH + 1];
		struct Answer ans[MAX_NO_OF_ANS];
	};

	struct Quiz
	{
		int quizIndexController;
		int totalQuestion;
		int trueQuestion;
		bool isQuizTaken;
	};

	//////////////////////////
	// FUNCTION PROTOTYPES 
	//////////////////////////
	int LoadQuiz(const char* filename);

	int IsQuizValid();
	int countQuestions();

	int HasMoreQuestions();
	void ShowNextQuestion();
	void ShowQuizResults();
}

#endif // !QUIZZER_QUIZ_H