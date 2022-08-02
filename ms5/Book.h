/*
Final Project Milestone 5
Module      : Book
Filename    : Book.h
Version 1.0

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

#ifndef SDDS_BOOK_H__
#define SDDS_BOOK_H__
#include <iostream>
#include "Publication.h"
using namespace std;
namespace sdds {
	class Book : public Publication {
		char* m_authorName{};
	public:
		//Constructor (default)
		Book();
		//The Rule of three
		Book(const Book& src);
		Book& operator=(const Book& src);
		virtual ~Book();

		void set(int member_id); // invoke the set of the base class to set the member, reset the date to the current date.
		char type()const; // Returns the character "B".
		
		//Streamable pure virtual function implementations
		bool conIO(std::ios& io)const;
		ostream& write(ostream& ostr)const;
		istream& read(istream& istr);
		operator bool()const;

		//Mr.Helper
		virtual void deleteAll();
	};
}
#endif // !SDDS_BOOK_H__
