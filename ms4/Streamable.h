/*
Final Project Milestone 3
Module      : Streamable
Filename    : Streamable.h
Version 1.0

Author	    : Nishit Gaurang Shah
Student ID# : 130 176 217
Email       : ngshah3@myseneca.ca
Section     : OOP244NFF

Date : 29th July 2022

Autheticity Declaraition :
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------
*/

#ifndef SDDS_STREAMABLE_H_
#define SDDS_STREAMABLE_H_
#include <iostream>
using namespace std;
namespace sdds
{
    class Streamable
    {
    public:
        virtual std::ostream &write(std::ostream &os) const = 0;
        virtual std::istream &read(std::istream &is) = 0;
        virtual bool conIO(std::ios &io) const = 0;
        virtual operator bool() const = 0;
        virtual ~Streamable();
    };
    std::ostream &operator<<(std::ostream &os, const Streamable &src);
    std::istream &operator>>(std::istream &is, Streamable &src);
}
#endif // !SDDS_STREAMABLE_H__
