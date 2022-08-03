/*
Final Project Milestone 5
Module      : LibApp
Filename    : LibApp.cpp
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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
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
		strcpy(m_fileName, fileName);
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
		Menu obj(message); 
		obj << "Yes";
		catchRun = obj.run();
		if (catchRun == 1) { 
			returnValue = true;
		}
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
					cout << "Aborted!" << endl;
				}
			}
			else 
			{
				cout << "No matches found!" << endl;
			}
		}
		else
		{
			cout << "Aborted!" << endl;
		}
		return ref;
	}

	void LibApp::newPublication() {
		if (m_NOLP == SDDS_LIBRARY_CAPACITY) {
			cout << "Library is at its maximum capacity!" << endl;
		}
		else
		{
			cout << "Adding new publication to the library" << endl;
			Publication* pub{};
			int catchMenu = m_publicationTypeMenu.run();
			switch (catchMenu)
			{
			case 1:
				pub = new Book;
				break;
			case 2:
				pub = new Publication;
				break;
			case 0:
				pub = nullptr;
				cout << "Aborted!" << endl;
				break;
			}
			if (pub)
			{
				cin >> *pub;
				if (cin)
				{
					if (confirm("Add this publication to the library?"))
					{
						m_PPA[m_NOLP] = pub;
						m_LLRN++;
						m_PPA[m_NOLP]->setRef(m_LLRN);
						m_NOLP++;
						cout << "Publication added" << endl;
						m_changed = true;
					}
					else 
					{
						cout << "Failed to add publication!" << endl;
						delete pub;
					}
				}
				else
				{
					cout << "Aborted!" << endl;
					delete pub;
				}
			}
		}

		return;
	}

	void LibApp::removePublication() {
		int catchSearch = 0;
		cout << "Removing publication from the library" << endl;
		catchSearch = search();
		if (catchSearch != 0) {
			confirm("Remove this publication from the library?");
			getPub(catchSearch)->setRef(0);
			m_changed = true;
			cout << "Publication removed" << endl;
		}
		else
		{
			cout << "Aborted!" << endl;
		}
		return;
	}

	void LibApp::checkOutPub() {
		int catchSearch = 0;
		int membershipNumber = 0;
		char errorMessage[39] = "Invalid membership number, try again: ";
		cout << "Checkout publication from the library" << endl;
		catchSearch = search(3);
		if (catchSearch != 0) {
			if(confirm("Check out publication?"))
			{
				cout << "Enter Membership number: ";
				membershipNumber = Utils::inputIntRangeWithMessage(9999, 100000, errorMessage);
				getPub(catchSearch)->set(membershipNumber);
				m_changed = true;
				cout << "Publication checked out" << endl;
			}
			else
			{
				cout << "Aborted!" << endl;
			}
		}

		return;
	}

	void LibApp::returnPub() {
		int catchSearch = 0;
		// Print: "Return publication to the library"
		cout << "Return publication to the library" << endl;
		// Search for "on loan" publications only
		catchSearch = search(2);
		if (catchSearch != 0) {
			if (confirm("Return Publication?"))
			{
				Date returnDate;
				Date checkoutDate = getPub(catchSearch)->checkoutDate();
				int loanedDays = returnDate - checkoutDate;
				//If the publication is more than 15 days on loan, a 50 cents per day penalty will be calculated for the number of days exceeding the 15 days.
				if (loanedDays > SDDS_MAX_LOAN_DAYS)
				{
					cout << fixed << setprecision(2) << "Please pay $" << double(loanedDays) * (0.5) << " penalty for being" << loanedDays - SDDS_MAX_LOAN_DAYS << " days late!" << endl;
				}
				// set the membership number of the publication to 0 (zero)
				getPub(catchSearch)->set(0);
				// set the "changed" flag to true
				m_changed = true;
				// prints "Publication returned"<NEWLINE>
				cout << "Publication returned" << endl;
			}
			else
			{
				cout << "Aborted!" << endl;
			}
		}

		return;
	}

}
