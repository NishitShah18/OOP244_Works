/*************************************************************************
Workshop 2 Part 1
Full Name   : Nishit Gaurang Shah
Student ID# : 130 176 217
Email       : ngshah3@myseneca.ca
Section     : OOP244NFF

Date : 27th May 2022

Autheticity Declaraition :
I declare that I have done all the coding by myself and only copied the
code that my professor provided to complete my workshops and assignments.

*************************************************************************/

// SAFE-GAURD
#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_

namespace sdds {

	//////////////////////////
	// FUNCTION PROTOTYPES 
	//////////////////////////
	bool openFile(const char filename[]);
	void closeFile();

	int noOfRecords();
	
	bool read(char* name);
	bool read(int& studentNumber);
	bool read(char& grade);

	void deallocateFptr();
}
#endif // !SDDS_FILE_H_