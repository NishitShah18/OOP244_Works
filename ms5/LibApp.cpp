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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include "LibApp.h"
#include "Utils.h"
#include "PublicationSelector.h"
#include "Book.h"
using namespace std;
namespace sdds {

	LibApp::LibApp(const char* fileName, const char* mainTitle, const char*
		exitTitle, const char* selectTitle) : m_NOLP(0), m_LLRN(0),
		m_changed(false), m_mainMenu(mainTitle), m_exitMenu(exitTitle),
		m_publicationTypeMenu(selectTitle) {
		//initialize
		strcpy(m_fileName, fileName);
		
		//set up menu options
		m_mainMenu << "Add New Publication";
		m_mainMenu << "Remove Publication";
		m_mainMenu << "Checkout publication from library";
		m_mainMenu << "Return publication to library";
		m_exitMenu << "Save changes and exit";
		m_exitMenu << "Cancel and go back to the main menu";
		m_publicationTypeMenu << "Book";
		m_publicationTypeMenu << "Publication";

		load();
	}

	LibApp::~LibApp() {
		for (int i = 0; i < m_NOLP; i++) {
			delete m_PPA[i];
			m_PPA[i] = nullptr;
		}
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
		cout << "Loading Data" << endl;
		ifstream fptr(m_fileName);
		char type{};
		for (int i = 0; fptr; i++) {
			fptr >> type;
			fptr.ignore();
			if (fptr) {
				if (type == 'P')
				{
					m_PPA[i] = new Publication;
				}
				else if (type == 'B')
				{
					m_PPA[i] = new Book;
				}
				else
				{
					cout << "no data" << endl;
				}
				if (m_PPA[i] && i < SDDS_LIBRARY_CAPACITY) {
					fptr >> *m_PPA[i];
					m_LLRN = m_PPA[m_NOLP]->getRef();
					m_NOLP++;
				}
			}
		}
		return;
	}
	
	void LibApp::save() {
		cout << "Saving Data" << endl;
		ofstream fptr(m_fileName);
		for (int i = 0; i < m_NOLP; i++) {
			if (m_PPA[i]->getRef() != 0)
			{
				fptr << *m_PPA[i] << endl;
			}
		}
		return;
	}

	Publication* LibApp::getPub(int libRef) {
		Publication* pub{};
		for (int i = 0; i < m_NOLP && !pub; i++) {
			if (m_PPA[i]->getRef() == libRef)
			{
				pub = m_PPA[i];
			}
		}
		return pub;
	}

	int LibApp::search(int option) {
		PublicationSelector pubSelector("Select one of the following found matches:",15);
		char pubType{};
		int catchMenu = m_publicationTypeMenu.run();
		char pubTitle[259] = {0};
		int ref = 0;
		switch (catchMenu)
		{
			case 1:
					pubType = 'B';
					break;
			case 2:
					pubType = 'P';
					break;
		}

		if (catchMenu == 1 || catchMenu == 2)
		{
			cout << "Publication Title: ";
			cin.getline(pubTitle, 256, '\n');
			if (option == 1)
			{
				for (int i = 0; i < m_NOLP; i++) {
					if (m_PPA[i]->type() == pubType && m_PPA[i]->getRef() != 0 && *m_PPA[i] == pubTitle)
					{
						pubSelector << m_PPA[i];
					}
				}
			}
			else if (option == 2)
			{
				for (int i = 0; i < m_NOLP; i++) {
					if (m_PPA[i]->type() == pubType && m_PPA[i]->getRef() != 0 && *m_PPA[i] == pubTitle && m_PPA[i]->onLoan())
					{
						pubSelector << m_PPA[i];
					}
				}
			}
			else if (option == 3)
			{
				for (int i = 0; i < m_NOLP; i++) {
					if (m_PPA[i]->type() == pubType && m_PPA[i]->getRef() != 0 && *m_PPA[i] == pubTitle && !m_PPA[i]->onLoan())
					{
						pubSelector << m_PPA[i];
					}
				}
			}
			if (pubSelector)
			{
				pubSelector.sort();
				ref = pubSelector.run();

				if (ref)
				{
					cout << *getPub(ref) << endl;
				}
				else
				{
					cout << "Aborted!" << endl << endl;
				}
			}
			else 
			{
				cout << "No matches found!" << endl << endl;
			}
		}
		else
		{
			cout << "Aborted!" << endl << endl;
		}
		return ref;
	}

	void LibApp::newPublication() {

		// If the NOLP is equal to the SDDS_LIBRARY_CAPACITY, print: "Library is at its maximum capacity!" and exit.
		if (m_NOLP == SDDS_LIBRARY_CAPACITY) {
			cout << "Library is at its maximum capacity!" << endl << endl;
		}
		//Otherwise,
		else
		{
			//print: "Adding new publication to the library"
			cout << "Adding new publication to the library" << endl;
			//get the publication type from the user.
			Publication* pub{};
			int catchMenu = m_publicationTypeMenu.run();
			switch (catchMenu)
			{
			//in a publication pointer, instantiate a dynamic "Publication" or "Book" based on the user's choice.
			case 1:
				pub = new Book;
				break;
			case 2:
				pub = new Publication;
				break;
			case 0:
				pub = nullptr;
				cout << "Aborted!" << endl << endl;
				break;
			}
			if (pub)
			{
				//Read the instantiated object from the cin object.
				cin >> *pub;
				//If the cin is ok, 
				//then confirm that the user wants to add the publication to the library 
				//using this prompt: "Add this publication to the library?".If the user did not confirm, print "Aborted!" and exit.
				if (cin)
				{
					if (confirm("Add this publication to library?"))
					{
						m_changed = true;
						m_PPA[m_NOLP] = pub;
						m_LLRN = m_PPA[m_NOLP]->getRef();
						m_NOLP++;
						cout << "Publication added" << endl << endl;
					}
					else 
					{
						cout << "Failed to add publication!" << endl << endl;
						delete pub;
					}
				}
				else
				{
					cout << "Aborted!" << endl << endl;
					delete pub;
				}
			}
		}

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

	

	

}