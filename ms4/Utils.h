/*
Final Project Milestone 3
Module      : Utils
Filename    : Utils.h
Version 2.0

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

// Revision History
// ---------------------------------------------------------------------
// Name               Date                 Reason
// Nishit             2022/07/29		   Implementation of Utils Class

#ifndef SDDS_UTILS_H__
#define SDDS_UTILS_H__
#include <iostream>
using namespace std;
namespace sdds
{
    class Utils
    {
    public:
        Utils() = delete;
        static void clearInputBuffer(void);
        static void getChar(istream &is, char c);
        static void getChar(istream &is);
        static int getInt(istream &is, int minimum, int maximum);
        static void copyStr(char *&desc, const char *src);
        static char *readInput(istream &is, char del = '\n');
    };
}
#endif // !SDDS_UTILS_H__
