/*************************************************************************
Workshop 9
Full Name   : Nishit Gaurang Shah
Student ID# : 130 176 217
Email       : ngshah3@myseneca.ca
Section     : OOP244NFF
Date : 30th July 2022
Autheticity Declaraition :
I declare that I have done all the coding by myself and only copied the
code that my professor provided to complete my workshops and assignments.
*************************************************************************/

#ifndef SDDS_FULLNAME_H__
#define SDDS_FULLNAME_H__

#include "Name.h"
#include <iostream>
using namespace std;
namespace sdds {
    class FullName : public Name {
        char* m_surname;
    public:
        // Constructors
        FullName();
        FullName(const char* name, const char* lastName);

        void setEmpty();

        // Rule of three
        ~FullName();
        FullName(const FullName& fullname);
        FullName& operator=(const FullName& fullname);
        
        operator const char* () const;  // Returns the address in the m_value of the FullName        
        virtual operator bool() const;  // Returns true only if both FullName and Name are not empty
        virtual ostream& display(ostream& ostr = cout) const;    // It will insert the Name, one space and then the m_value of the FullName into the ostream reference without going to the new line
        virtual istream& read(istream& istr = cin);  // Reads the Name and then dynamically reads a Cstring into the m_value of FullName from istream until it reaches the newline character
    };
};
#endif // !SDDS_FULLNAME_H__