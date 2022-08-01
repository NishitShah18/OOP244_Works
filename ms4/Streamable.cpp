/*
Final Project Milestone 4
Module      : Streamable
Filename    : Streamable.cpp
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

#include <iostream>
#include "Streamable.h"
namespace sdds
{
    std::ostream &operator<<(std::ostream &os, const Streamable &src)
    {
        if (src) src.write(os);
        return os;
    }
    std::istream &operator>>(std::istream &is, Streamable &src)
    {
        return src.read(is);
    }
    Streamable::~Streamable()
    {
        //empty
    }
}
