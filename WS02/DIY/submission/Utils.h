/*************************************************************************
Workshop 2 Part 2
Full Name   : Nishit Gaurang Shah
Student ID# : 130 176 217
Email       : ngshah3@myseneca.ca
Section     : OOP244NFF

Date : 30th May 2022

Autheticity Declaraition :
I declare that I have done all the coding by myself and only copied the
code that my professor provided to complete my workshops and assignments.

*************************************************************************/

#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H

#include"BirthDate.h"

namespace sdds {
	//////////////////////////
	// FUNCTION PROTOTYPES 
	//////////////////////////
	bool openFile(const char filename[]);
	void closeFile();

	int noOfRecords();

	bool read(char* name);
	bool read(int& monthOrDate);
	bool read(int& year, int isYear);
}

#endif // !SDDS_BIRTHDATE_H
