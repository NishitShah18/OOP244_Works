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

#include "Name.h"
#include <cstring>

using namespace std;

namespace sdds {

    void Name::setEmpty() 
    {
        m_name = nullptr;
        return;
    }

    Name::Name() 
    {
        setEmpty();
    }

    Name::Name(const char* name) 
    {
        if (name) {
            m_name = new char[strlen(name) + 1];
            strcpy(m_name, name);
        }
        else {
            setEmpty();
        }
    }

    Name::~Name() 
    {
        delete[] m_name;
        setEmpty();
    }

    Name::Name(const Name& name) 
    {
        m_name = new char[strlen(name.m_name) + 1];
        strcpy(m_name, name.m_name);
    }

    Name& Name::operator=(const Name& name) 
    {
        delete[] m_name;
        setEmpty();
        m_name = new char[strlen(name.m_name) + 1];
        strcpy(m_name, name.m_name);

        return *this;
    }

    Name::operator const char* () const 
    {
        return m_name;
    }

    Name::operator bool() const 
    {
        return m_name != nullptr;
    }

    ostream& Name::display(ostream& ostr) const 
    {
        ostr << m_name;
        return ostr;
    }

    istream& Name::read(istream& istr) 
    {
        char cString[1024];
        istr.getline(cString, 1024, ' ');

        m_name = new char[strlen(cString) + 1];
        strcpy(m_name, cString);

        return istr;
    }

    ostream& operator<<(ostream& os, const Name& name) 
    {
        return name.display(os);
    }

    istream& operator>>(istream& is, Name& name) 
    {
        return name.read(is);
    }
}