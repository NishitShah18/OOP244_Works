/*
Final Project Milestone 2
Module      : LibApp
Filename    : LibApp.h
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

#include <iostream>
#include <cstring>
#include "LibApp.h"
using namespace std;
namespace sdds {
	bool LibApp::confirm(const char* message) {
		bool returnValue = false;
		int catchRun = 0;
		//Instantiate a Menu in this function and initialize it with the message argument.
		Menu obj(message); 
		//Then add only a "yes" as a single menu item to the Menu.
		obj << "Yes";
		//Run the menu
		catchRun = obj.run();
		if (catchRun == 1) { 
			returnValue = true;
		}
		//Return true if the run method of Menu returns 1 and otherwise this function returns false.
		return returnValue;
	}

	void LibApp::load() {
		// prints: "Loading Data"<NEWLINE>
		cout << "Loading Data" << endl;

		return;
	}
	
	void LibApp::save() {
		// prints: "Saving Data"<NEWLINE>
		cout << "Saving Data" << endl;

		return;
	}

	void LibApp::search() {
		// prints: "Searching for publication"<NEWLINE>
		cout << "Searching for publication" << endl;

		return;
	}

	void LibApp::returnPub() {
		// Calls the search() method.
		search();
		// prints "Returning publication" < NEWLINE >
		cout << "Returning publication" << endl;
		// prints "Publication returned"<NEWLINE>
		cout << "Publication returned" << endl;
		// sets m_changed to true;
		m_changed = true;

		return;
	}

	void LibApp::newPublication() {
		bool catchConfirm = false;
		// prints "Adding new publication to library"+newline
		cout << "Adding new publication to library" << endl;
		// calls the confirm method with "Add this publication to library?"
		catchConfirm = confirm("Add this publication to library?");
		if (catchConfirm == true) {
			//If confrim returns true, it will set m_changed to true
			m_changed = true;
			//Prints "Publication added" + newline
			cout << "Publication added" << endl;
		}

		return;
	}

	void LibApp::removePublication() {
		bool catchConfirm = false;
		// prints "Removing publication from library" + newline
		cout << "Removing publication from library" << endl;
		// calls the search method
		search();
		// calls the confirm method with "Remove this publication from the library?"
		catchConfirm = confirm("Remove this publication from the library?");
		if (catchConfirm == true) {
			//If confrim returns true, it will set m_changed to true
			m_changed = true;
			//Prints "Publication removed" + newline
			cout << "Publication removed" << endl;
		}

		return;
	}

	void LibApp::checkOutPub() {
		bool catchConfirm = false;
		// calls the search method
		search();
		// calls the confirm method with Check out publication?"
		catchConfirm = confirm("Check out publication?");
		if (catchConfirm == true) {
			//If confrim returns true, it will set m_changed to true
			m_changed = true;
			//Prints "Publication checked out" + newline
			cout << "Publication checked out" << endl;
		}

		return;
	}

	LibApp::LibApp() :m_mainMenu("Seneca Library Application"), m_exitMenu("Changes have been made to the data, what would you like to do?") {
		//Initializes the attributes
		m_changed = false;
		//Populates the Menu attributes
		m_mainMenu << "Add New Publication";
		m_mainMenu << "Remove Publication";
		m_mainMenu << "Checkout publication from library";
		m_mainMenu << "Return publication to library";
		m_exitMenu << "Save changes and exit";
		m_exitMenu << "Cancel and go back to the main menu";
		//Calls the `load()` method
		load();
	}

	void LibApp::run() {
		bool exitCode = false;
		int choice = -1;
		int endChoice = -1;
		while (exitCode == false) {
			choice = m_mainMenu.run();
			switch (choice)
			{
			case 1:
				newPublication();
				cout << endl;
				break;
			case 2:
				removePublication();
				cout << endl;
				break;
			case 3:
				checkOutPub();
				cout << endl;
				break;
			case 4:
				returnPub();
				cout << endl;
				break;
			case 0:
				if (m_changed == true) { 
					endChoice = m_exitMenu.run();
					if (endChoice == 1) {
						save();
						exitCode = true;
					}
					else if (endChoice == 2) {
						cout << endl;
					}
					else {
						exitCode = confirm("This will discard all the changes are you sure? ");
					}
				}
				else {
					exitCode = true;
				}
			}
		}
		cout << endl << "-------------------------------------------" << endl;
		cout << "Thanks for using Seneca Library Application" << endl;

		return;
	}

}