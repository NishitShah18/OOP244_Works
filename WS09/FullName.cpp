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

#define _CRT_SECURE_NO_WARNINGS

#include "FullName.h"
#include "Name.h"
#include <cstring>

using namespace std;

namespace sdds {

    void FullName::setEmpty() 
    {
        m_surname = nullptr;
        return;
    }

    FullName::FullName() 
    {
        setEmpty();
    }

    FullName::FullName(const char* name, const char* lastName) : Name(name) 
    {
        if (lastName) {
            m_surname = new char[strlen(name) + 1];
            strcpy(m_surname, name);
        }
        else {
            setEmpty();
        }
    } 

    FullName::FullName(const FullName& fullname): Name(fullname) 
    {
        m_surname = new char[strlen(fullname.m_surname) + 1];
        strcpy(m_surname, fullname.m_surname);
    }

    FullName& FullName::operator=(const FullName& fullname) 
    {
        Name::operator=(fullname);

        delete[] m_surname;
        setEmpty();
        m_surname = new char[strlen(fullname.m_surname) + 1];
        strcpy(m_surname, fullname.m_surname);

        return *this;
    }

    FullName::~FullName() 
    {
        delete[] m_surname;
        setEmpty();
    }

    FullName::operator const char* () const 
    {
        return m_surname;
    }

    FullName::operator bool() const 
    {
        return (m_surname != nullptr && Name::operator bool());
    }

    ostream& FullName::display(ostream& ostr) const 
    {
        Name::display(ostr) << " " << m_surname;

        return ostr;
    }

    istream& FullName::read(istream& istr) 
    {
        Name::read(istr);
        
        char cString[1024];
        istr.getline(cString, 1024, '\n');
        
        m_surname = new char[strlen(cString) + 1];
        strcpy(m_surname, cString);

        return istr;
    }
}