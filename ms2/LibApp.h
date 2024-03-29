/*
Final Project Milestone 2
Module      : Menu
Filename    : Menu.h
Version 1.0
Author	    : Nishit Gaurang Shah
Student ID# : 130 176 217
Email       : ngshah3@myseneca.ca
Section     : OOP244NFF

Date : 22nd July 2022

Autheticity Declaraition :
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------
*/

#ifndef SDDS_LIBAPP_H__
#define SDDS_LIBAPP_H__

#include"Menu.h"

namespace sdds {
	class LibApp {
		//LibApp Attributes
		bool m_changed;
		Menu m_mainMenu;
		Menu m_exitMenu;
		bool confirm(const char* message); //Instantiates a Menu in this function and initialize it with the message argument.
		void load();  // prints: "Loading Data"<NEWLINE>
		void save();  // prints: "Saving Data"<NEWLINE>
		void search();  // prints: "Searching for publication"<NEWLINE>
		void returnPub();  /*  Calls the search() method.
							   prints "Returning publication"<NEWLINE>
							   prints "Publication returned"<NEWLINE>
							   sets m_changed to true;
						   */
		void newPublication(); /*  prints "Adding new publication to library"+newline
								   calls the confirm method with "Add this publication to library?"
								   if confrim returns true, it will set m_changed to true and prints "Publication added" + newline
							   */
		void removePublication(); /*  prints "Removing publication from library"+newline
								      calls the search method
									  calls the confirm method with "Remove this publication from the library?"
									  if confrim returns true, it will set m_changed to true and prints "Publication removed" + newline
								  */
		void checkOutPub(); /* calls the search method
							   calls the confirm method with Check out publication?"
							   if confrim returns true, it will set m_changed to true and prints "Publication checked out" + newline
							*/
	public:
		LibApp(); //Constructor
		void run(); //The run method is the main application driver.
	};
}

#endif // !SDDS_LIBAPP_H__
