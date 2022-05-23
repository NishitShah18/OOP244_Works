/*************************************************************************

Name			: Nishit Gaurang Shah
Student Num.	: 130 176 217
Email ID		: ngshah3@myseneca.ca
Section			: OOP244NFF

Date :  May 2022

Autheticity Declaraition :
I declare that I have done all the coding by myself and only copied the
code that my professor provided to complete my workshops and assignments.

*************************************************************************/

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstring>
#include"quiz.h"
#include"question.h"

using namespace std;

namespace quizzer
{
	//////////////////////////
	// GLOBAL VARIABLES 
	//////////////////////////
	
	//////////////////////////
	// FUNCTION DEFINITIONS 
	//////////////////////////
	void evaluateQuestion(struct Question* rec, int num, int* valid)
	{
		int trueAnswers = 0;
		countTrueAnswers(&trueAnswers, rec);
		if (strcmp(rec->type, "{mc}") == 0 && trueAnswers == 1)
		{
			cout << "Question " << num << " -> OK" << endl;
			*valid = *valid + 1;
		}
		else if (strcmp(rec->type, "{ma}") == 0 && trueAnswers >=1)
		{
			cout << "Question " << num << " -> OK" << endl;
			*valid = *valid + 1;
		}
		else
		{
			cout << "Question " << num << " -> ERROR" << endl;
		}
	}

	void countTrueAnswers(int* ans, struct Question* rec)
	{
		int i = 0;

		for (i = 0; i < MAX_NO_OF_ANS; i++)
		{
			if (strcmp(rec->ans[i].option, "[X]") == 0)
			{
				*ans = *ans + 1;
			}
		}

		return;
	}
/*
What does 'std::printf("Hello\n")' means in C++?
1. nothing, the syntax is not correct
2. call the function "std" and pass "printf" as parameter
3. insert the text "Hello" into a file
4. print the text "Hello" to the screen
*/

	void showFormattedQuestion(struct Question* rec)
	{
		int answerIndex = 0;
		int exitCode = 0;
		puts(rec->question);
		do
		{
			cout << answerIndex + 1 << ". ";
			puts(rec->ans[answerIndex].answerOption);

			if (strcmp(rec->ans[answerIndex+1].option, "[X]") == 0 || strcmp(rec->ans[answerIndex+1].option, "[ ]") == 0)
			{
				exitCode = 0;
			}
			else
			{
				exitCode = 1;
			}

			answerIndex++;

		} while (exitCode!=1);

		return;
	}
}