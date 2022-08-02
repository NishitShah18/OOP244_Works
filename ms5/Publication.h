/*
Final Project Milestone 4
Module      : Publication
Filename    : Publication.h
Version 1.0

Author	    : Nishit Gaurang Shah
Student ID# : 130 176 217
Email       : ngshah3@myseneca.ca
Section     : OOP244NFF

Date : 1st August 2022

Autheticity Declaraition :
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------
*/

#ifndef SDDS_PUBLICATION_H__
#define SDDS_PUBLICATION_H__
#include <iostream>
#include "Date.h"
#include "Streamable.h"
#include "Lib.h"
using namespace std;
namespace sdds
{
    class Publication : public Streamable
    {
        char *m_title{};
        char m_shelfId[SDDS_SHELF_ID_LEN + 1]{};
        int m_membership;
        int m_libRef;
        Date m_date;

    public:
        //Constructor (default)
        Publication();
        //The Rule of three
        Publication(const Publication &src);
        Publication& operator=(const Publication& src);
        virtual ~Publication();
        
        virtual void set(int member_id);    // Sets the membership attribute to either zero or a five-digit integer.
        void setRef(int value);             // Sets the **libRef** attribute value
        void resetDate();                   // Sets the date to the current date of the system.

        virtual char type()const;           //Returns the character 'P' to identify this object as a "Publication object"
        bool onLoan()const;                 //Returns true is the publication is checkout (membership is non-zero)
        Date checkoutDate()const;           //Returns the date attribute
        bool operator==(const char* title)const;    //Returns true if the argument title appears anywhere in the title of the 
                                                    //publication. Otherwise, it returns false; (use strstr() function in <cstring>)
        operator const char* ()const;       //Returns the title attribute
        int getRef()const;                  //Returns the libRef attirbute. 

        //Streamable pure virtual function implementations
        bool conIO(ios &io) const;
        ostream &write(ostream &os) const;
        istream &read(istream &istr);
        operator bool() const;

        //Mr.Helper
        virtual void deleteAll();
    };
}
#endif // !SDDS_PUBLICATION_H__
