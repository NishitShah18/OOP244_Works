/*************************************************************************
Workshop 3 Part 2
Full Name   : Nishit Gaurang Shah
Student ID# : 130 176 217
Email       : ngshah3@myseneca.ca
Section     : OOP244NFF
Date : 5th June 2022
Autheticity Declaraition :
I declare that I have done all the coding by myself and only copied the
code that my professor provided to complete my workshops and assignments.
*************************************************************************/

#ifndef SDDS_BAR_H
#define SDDS_BAR_H
#include <iostream>
#include <cstring>
#include <iomanip>

namespace sdds {
	
	const int MAX_TITLE_LEN = 100;

	class Bar {
		char m_title[MAX_TITLE_LEN];
		char m_fillChar;
		int m_noOfBars;

	public:

		void setEmpty();
		void set(const char* title, char fillBar, int numSamples);
		bool isValid() const;
		void draw() const;
	};
}

#endif 

