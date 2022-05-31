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

#ifndef SDDS_BIRTHDATE_H
#define SDDS_BIRTHDATE_H

namespace sdds {
	//////////////////////////
	// CONSTANT VARIABLE(S) 
	//////////////////////////
	const int LOCAL_ARRAY_SIZE = 128;

	//////////////////////////
	// STRUCTURE(S) 
	//////////////////////////
	struct BirthDateData {
		char* name;
		// date:
		int year;
		int month;
		int date;
	};

	//////////////////////////
	// FUNCTION PROTOTYPES 
	//////////////////////////
	bool beginSearch(const char* filename);

	bool readBirthDate(int month);

	void sort();

	void displayBirthdays();

	void deallocate();

	void endSearch();

}

#endif // !SDDS_BIRTHDATE_H
