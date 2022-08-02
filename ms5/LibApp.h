/*
Final Project Milestone 5
Module      : LibApp
Filename    : LibApp.h
Version 2.0
Author	    : Nishit Gaurang Shah
Student ID# : 130 176 217
Email       : ngshah3@myseneca.ca
Section     : OOP244NFF

Date : 2nd August 2022

Autheticity Declaraition :
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------
*/

// Revision History
// ---------------------------------------------------------------------
// Name               Date                 Reason
// Nishit             2022/08/02		   Updated according to MS-5

#ifndef SDDS_LIBAPP_H__
#define SDDS_LIBAPP_H__

#include"Menu.h"
#include"Publication.h"

namespace sdds {
	class LibApp {
		//LibApp Attributes
		char m_fileName[256]{}; //file name
		Publication* m_PPA[SDDS_LIBRARY_CAPACITY]{}; //Public pointer array
		int m_NOLP; //PPA array size
		int m_LLRN; //record the last ref number in the library
		bool m_changed;
		Menu m_mainMenu;
		Menu m_exitMenu;
		Menu m_publicationTypeMenu;

	public:
		LibApp(const char* fileName, const char* mainTitle = "Seneca Library Application",
			const char* exitTitle = "Changes have been made to the data, what would you like to do?", 
			const char* selectTitle = "Choose the type of publication:");
		void run(); //The run method is the main application driver.
		//Rule of three
		LibApp(const LibApp& src) = delete;
		LibApp& operator=(const LibApp& src) = delete;
		virtual ~LibApp();
	private:
		bool confirm(const char* message); //Confirms what needed
		void load();  //Loades Data
		void save();  //Saves Data
		Publication* getPub(int libRef);
		int search(int option = 1);	//Searches for publication
		void returnPub();  /*  Calls the search() method.
							   sets m_changed to true	*/
		void newPublication(); //Adds new publication
		void removePublication(); //Removes publication
		void checkOutPub(); // checks publication out
	};
}

#endif // !SDDS_LIBAPP_H__
