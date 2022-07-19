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
#include <iomanip>
#include "MemberParliament.h"

using namespace std;

namespace sdds
{
    MemberParliament::MemberParliament(const char *id, int age)
    {
        strcpy(m_id, id);
        strcpy(m_district, "Unassigned");
        this->m_age = age;
    }
    MemberParliament::MemberParliament(const char *id, const char *district, int age)
    {
        strcpy(this->m_district, district);
        strcpy(m_id, id);
        this->m_age = age;
        cout << "|" << setw(8) << right << m_id << "| |          Unassigned ---> " << setw(23) << left << m_district << "|" << endl;
    }
    void MemberParliament::NewDistrict(const char *district)
    {
        cout << "|" << setw(8) << right << m_id << "| |" << setw(20) << right << this->m_district << " ---> " << setw(23) << left << district << "|" << endl;
        strcpy(this->m_district, district);
    }
    ostream &MemberParliament::write(ostream &os) const
    {
        cout << "| " << right << m_id << " | " << m_age << " | " << m_district;
        return os;
    }
    istream &MemberParliament::read(istream &in)
    {
        cout << "Age: ";
        in >> m_age;
        cout << "Id: ";
        in >> m_id;
        cout << "District: ";
        in >> m_district;
        return in;
    }
    ostream &operator<<(ostream &os, const MemberParliament &MP)
    {
        return MP.write(os);
    }
    istream &operator>>(istream &in, MemberParliament &MP)
    {
        return MP.read(in);
    }
}