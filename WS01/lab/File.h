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
#ifndef SDDS_FILE_H
#define SDDS_FILE_H

#include"ShoppingRec.h"

namespace sdds
{
	//////////////////////////
	// CONSTANT VARIALES 
	//////////////////////////
	const char* const SHOPPING_DATA_FILE = "shoppinglist.csv";

	//////////////////////////
	// FUNCTION PROTOYPES 
	//////////////////////////
	bool openFileForRead();
	bool openFileForOverwrite();
	void closeFile();
	bool freadShoppingRec(ShoppingRec* rec);
	void fwriteShoppintRec(const ShoppingRec* rec);
}

#endif // !SDDS_FILE_H