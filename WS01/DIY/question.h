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
#ifndef QUIZZER_QESTION_H
#define QUIZZER_QESTION_H

namespace quizzer
{
	//////////////////////////
	// FUNCTION PROTOTYPES 
	//////////////////////////
	void evaluateQuestion(struct Question* rec, int num, int* valid);
	void countTrueAnswers(int* ans, struct Question* rec);
	void showFormattedQuestion(struct Question* rec);
}

#endif // !QUIZZER_QESTION_H