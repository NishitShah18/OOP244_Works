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
#ifndef SDDS_SHOPPINGLIST_H
#define SDDS_SHOPPINGLIST_H

namespace sdds
{	
	//////////////////////////
	// CONSTANT VARIABLES 
	//////////////////////////
	const int MAX_NO_OF_RECS = 15;

	//////////////////////////
	// FUNCTION PROTOTYPES 
	//////////////////////////
	bool loadList();
	void displayList();
	void removeBoughtItems();
	void removeItem(int index);
	bool saveList();
	void clearList();
	void toggleBought();
	void addItemToList();
	void removeItemfromList();
	bool listIsEmpty();
}

#endif // !SDDS_SHOPPINGLIST_H