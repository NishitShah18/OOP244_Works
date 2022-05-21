/*************************************************************************

Name			: Nishit Gaurang Shah
Student number		: 130 176 217
Email Id		: ngshah3@myseneca.ca
Section			: OOP244NFF

Date : 20th May 2022

Autheticity Declaraition :
I declare that I have done all the coding by myself and only copied the
code that my professor provided to complete my workshops and assignments.

*************************************************************************/

// SAFE-GAURD
#ifndef SDDS_SHOPPINGREC_H
#define SDDS_SHOPPINGREC_H

namespace sdds
{
	//////////////////////////
	// CONSTANT VARIABLES 
	//////////////////////////
	const int MAX_TITLE_LENGTH = 50;
	const int MAX_QUANTITY_VALUE = 50;

	//////////////////////////
	// STRUCTURES 
	//////////////////////////
	struct ShoppingRec
	{
		char m_title[MAX_TITLE_LENGTH + 1];
		int m_quantity;
		bool m_bought;
	};

	//////////////////////////
	// FUNCTION PROTOTYPES 
	//////////////////////////
	ShoppingRec getShoppingRec();
	void displayShoppingRec(const ShoppingRec* shp);
	void toggleBoughtFlag(ShoppingRec* rec);
	bool isShoppingRecEmpty(const ShoppingRec* shp);
}

#endif // !SDDS_SHOPPINGREC_H