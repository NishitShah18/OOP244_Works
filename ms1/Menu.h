/*
Final Project Milestone 1
Module      : Menu
Filename    : Menu.h
Version 1.0
Author	    : Nishit Gaurang Shah
Student ID# : 130 176 217
Email       : ngshah3@myseneca.ca
Section     : OOP244NFF

Date : 8th July 2022

Autheticity Declaraition :
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------
*/

#ifndef SDDS_MENU_H__
#define SDDS_MENU_H__
#include <iostream>
#include "Utils.h"
using namespace std;
namespace sdds {
	const int MAX_MENU_ITEMS = 20;
	class Menu;
	class MenuItem {
		// This class holds only one Cstring of characters for the content of the menu item dynamically.
		char* m_menuItem;
		
		// Constructor
		MenuItem();	// If no value is provided for the description at the moment of creation, the MenuItem should be set to an empty state.
		MenuItem(const char* item); // Allocates and sets the content of the MenuItem to a Cstring value at the moment of instantiation (or initialization).
		
		/*
			Rule of Three
			A MenuItem object cannot be copied from or assigned to another MenuItem object.
			(Copy constructor and Copy assignment are deleted)
		*/
		MenuItem(const MenuItem&) = delete;
		MenuItem& operator=(const MenuItem&) = delete;

		// bool type conversion
		operator bool()const; // When a MenuItem is casted to “bool” it should return true, if it is not empty and it should return false if it is empty.
		
		// const char* type conversion  
		operator const char*()const; // When a MenuItem is casted to “const char*” it should return the address of the content Cstring.

		// displaying the MenuItem
		void displayMit(std::ostream& os)const; // Create a method to display the content of the MenuItem on ostream. (No newline is printed after) Nothing is printed if MenuItem is empty.
		
		// Destructor
		~MenuItem();

		// Make the “Menu” class a friend of this class (which makes MenuItem class only accessible by the Menu class).
		friend class Menu;
	};

	class Menu {
		// Attributes
		MenuItem m_menuTitle;
		MenuItem* m_itemList[MAX_MENU_ITEMS];
		int m_numberOfItems;

	public:
		// Constructors
		Menu();
		Menu(const char* menuTitle);

		// Rule of Three
		Menu(const Menu&) = delete;
		Menu& operator=(const Menu&) = delete;

		void printTitle(ostream& os)const;
		// Create a function to display the entire Menu on ostream.
		void display()const;

		// Create a member function called run. This function displays the Menu and gets the user selection.
		int run()const;

		// Overload operator~ to do exactly what the run function does (two different ways to run the menu)
		int operator~()const;

		// Overload a member insertion operator (operator<<) to add a MenuItem to the Menu.
		Menu& operator<<(const char* menuitemConent);

		// Overload two type conversions for int and unsigned int to return the number of MenuItems on the Menu.
		operator int()const;
		operator unsigned int()const;

		// Overload the type conversion for bool to return true if the Menu has one or more MenuItems otherwise, false;
		operator bool()const;

		// Overload the indexing operator to return the const char* cast of the corresponding MenuItem in the array of MenuItem pointers. If the index passes the number of MenuItems in the Menu, loop back to the beginning.
		const char* operator[](int i)const;

		// Destructor
		~Menu();
	};

	// Overload the insertion operator to print the title of the Menu using cout.
	std::ostream& operator<<(std::ostream&, const Menu&);
}
#endif // !SDDS_MENU_H__
