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

#ifndef SDDS_MINISTER_H
#define SDDS_MINISTER_H

#include "MemberParliament.h"

using namespace std;

namespace sdds
{
    class Minister : public MemberParliament
    {
    private:
        char m_name[50];
        double m_year;

    public:
        Minister(const char *id, int age, double year, const char *district, const char *name);
        void changePM(const char *pm);
        void assumeOffice(double year);
        ostream &write(ostream &os) const;
        istream &read(istream &in);
    };
    ostream &operator<<(ostream &os, const Minister &M);
    istream &operator>>(istream &in, Minister &M);
}
#endif