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

#ifndef SDDS_MEMBERPARLIAMENT_H
#define SDDS_MEMBERPARLIAMENT_H

#include <iostream>

namespace sdds
{
    class MemberParliament
    {
    private:
        char m_id[32];
        char m_district[64];
        int m_age;

    public:
        MemberParliament(const char *id, int age);
        MemberParliament(const char *id, const char *district, int age);
        void NewDistrict(const char *district);
        std::ostream &write(std::ostream &os) const;
        std::istream &read(std::istream &in);
    };
    std::ostream &operator<<(std::ostream &os, const MemberParliament &MP);
    std::istream &operator>>(std::istream &in, MemberParliament &MP);
}
#endif