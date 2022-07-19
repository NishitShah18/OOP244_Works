/*************************************************************************
Workshop 7
Full Name   : Nishit Gaurang Shah
Student ID# : 130 176 217
Email       : ngshah3@myseneca.ca
Section     : OOP244NFF
Date : 18th July 2022
Autheticity Declaraition :
I declare that I have done all the coding by myself and only copied the
code that my professor provided to complete my workshops and assignments.
*************************************************************************/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>
#include "Minister.h"
#include "MemberParliament.h"

using namespace std;

namespace sdds
{
    Minister::Minister(const char *id, int age, double year, const char *name, const char *district) : MemberParliament(id, district, age)
    {
        strcpy(this->m_name, name);
        this->m_year = year;
    }
    void Minister::changePM(const char *pm)
    {
        strcpy(this->m_name, pm);
    }
    void Minister::assumeOffice(double year)
    {
        this->m_year = year;
    }
    ostream &Minister::write(ostream &os) const
    {
        MemberParliament::write(os);
        cout << " | " << this->m_name << "/" << this->m_year;
        return os;
    }
    istream &Minister::read(istream &in)
    {
        MemberParliament::read(in);
        cout << "Reports TO: ";
        in >> this->m_name;
        cout << "Year Assumed Office: ";
        in >> this->m_year;
        return in;
    }
    ostream &operator<<(ostream &os, const Minister &M)
    {
        return M.write(os);
    }
    istream &operator>>(istream &in, Minister &M)
    {
        return M.read(in);
    }
}
