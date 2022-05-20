/*************************************************************************

Name			: Nishit Gaurang Shah
Student number	: 130 176 217
Email Id		: ngshah3@myseneca.ca
Section			: OOP244NFF

Autheticity Declaraition :
I declare that I have done all the coding by myself and only copied the
code that my professor provided to complete my workshops and assignments.

*************************************************************************/

// SAFE-GAURD
#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H

namespace sdds
{
	//////////////////////////
	// FUNCTION PROTOTYPES 
	//////////////////////////
	void flushkeys();
	bool ValidYesResponse(char ch);
	bool yes();
	void readCstr(char cstr[], int len);
	int readInt(int min, int max);
}

#endif // !SDDS_UNITS_H