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
#include<cstdio>
#include<cstring>
#include"quiz.h"
#include"question.h"

using namespace std;

namespace quizzer
{
	//////////////////////////
	// GLOBAL VARIABLES 
	//////////////////////////
	FILE* sfptr = nullptr;
	struct Question qA[MAX_NO_OF_QUE] = {};
	struct Quiz quiz = {};

	//////////////////////////
	// FUNCTION DEFINITIONS 
	//////////////////////////
	int LoadQuiz(const char* filename)
	{
		int returnValue = 0;
		// quiz is not taken yet
		quiz.isQuizTaken = false;

		sfptr = fopen(filename, "r");
		int i = 0;

		if (!sfptr)
		{
			returnValue = -1;
		}
		else
		{
			struct Question temp[MAX_NO_OF_QUE] = { {} };
			// putting qA to safe empty state
			for (i = 0; i < MAX_NO_OF_QUE; i++)
			{
				qA[i] = temp[i];
			}

			int indexController = -1;
			int answerIndexController = 0;
			char ch = '\0';

			do
			{
				ch = fgetc(sfptr);
				fseek(sfptr, -1, SEEK_CUR);

				if (ch == '{')
				{
					indexController++;
					answerIndexController = 0;
					fscanf(sfptr, "%4[^\n] %[^\n]\n",
						temp[indexController].type, temp[indexController].question);
				}
				else if (ch == '[')
				{
					fscanf(sfptr, "%3[^\n] %[^\n]\n",
						temp[indexController].ans[answerIndexController].option, temp[indexController].ans[answerIndexController].answerOption);
					answerIndexController++;
				}
				else if (ch == '\n')
				{
					fseek(sfptr, 2, SEEK_CUR);
				}
				else
				{
					// ch = EOF;
				}

			} while (ch != EOF);

			for (i = 0; i < MAX_NO_OF_QUE; i++)
			{
				qA[i] = temp[i];
			}
		}
		if (sfptr) fclose(sfptr);

		return returnValue;
	}

	int IsQuizValid()
	{
		int returnValue = -1;
		int totalQuestions = countQuestions();

		if (totalQuestions < 5)
		{
			// INVALID QUIZ : print nothing
		}
		else
		{
			int i = 0;
			int validQuestions = 0;

			for (i = 0; i < totalQuestions; i++)
			{
				evaluateQuestion(&qA[i], (i + 1), &validQuestions);
			}
			if(validQuestions == totalQuestions)
			{
				struct Quiz emptyTheStruct = {};
				quiz = emptyTheStruct;

				quiz.totalQuestion = totalQuestions;

				returnValue = 1;
			}
			else
			{
				// invalid quiz. print nothing.
			}
		}
		return returnValue;
	}

	int countQuestions()
	{
		int i = 0;
		int counter = 0;

		for (i = 0; i < MAX_NO_OF_QUE; i++)
		{
			if (strcmp(qA[i].type, "{mc}") == 0)
			{
				counter += 1;
			}
			else if (strcmp(qA[i].type, "{ma}") == 0)
			{
				counter += 1;
			}
			else
			{
				// do nothing 
			}
		}
		return counter;
	}

	int HasMoreQuestions()
	{
		int returnValue = -1;

		if (strcmp(qA[quiz.quizIndexController + 1].type, "{ma}") == 0)
		{
			quiz.quizIndexController++;
		}
		else if (strcmp(qA[quiz.quizIndexController + 1].type, "{mc}") == 0)
		{
			quiz.quizIndexController++;
		}
		else
		{
			returnValue = 0;
		}

		return returnValue;
	}

	void ShowNextQuestion()
	{
		int ans = 0;
		showFormattedQuestion(&qA[quiz.quizIndexController]);
		cout << "Your answer? ";
		cin >> ans;
		if (strcmp(qA[quiz.quizIndexController].ans[ans-1].option, "[X]") == 0)
		{
			quiz.trueQuestion++;
		}
		quiz.isQuizTaken = true;
	}

	void ShowQuizResults()
	{
		if (quiz.isQuizTaken == true)
		{
			cout << endl << "QUIZ RESULTS: your score is " << quiz.trueQuestion << "/" << quiz.totalQuestion << "." << endl;
		}
		else
		{
			// Quiz is not taken. Print nothing.
		}
	}
}