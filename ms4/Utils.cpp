/*
Final Project Milestone 3
Module      : Utils
Filename    : Utils.cpp
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

// Revision History
// ---------------------------------------------------------------------
// Name               Date                 Reason
// Nishit             2022/07/29		   Implementation of Utils Class

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include <ctype.h>
#include "Utils.h"
namespace sdds
{
    void Utils::clearInputBuffer(void)
    {
        // Discard all remaining char's from the standard input buffer:
        while (getchar() != '\n')
        {
            ; // do nothing!
        }
    }

    void Utils::getChar(std::istream &is, char c)
    {
        if (is.peek() == c)
            is.get();
    }
    void Utils::getChar(std::istream &is)
    {
        if (isdigit(is.peek()))
        {
            is.setstate(std::ios::failbit);
        }
        else
        {
            is.get();
        }
    }
    int Utils::getInt(std::istream &is, int minimum, int maximum)
    {
        int a;
        bool flag = false;
        while (!flag)
        {
            is >> a;
            if (is && is.peek() == '\n')
            {
                if (a >= minimum && a <= maximum)
                {
                    flag = true;
                }
                else
                {
                    std::cout << "Invalid Selection, try again: ";
                }
            }
            else
            {
                is.clear();
                std::cout << "Invalid Selection, try again: ";
            }
            is.ignore(1000, '\n');
        }
        return a;
    }
    void Utils::copyStr(char *&desc, const char *src)
    {
        delete[] desc;
        desc = new char[strlen(src) + 1];
        strcpy(desc, src);
    }
    char *Utils::readInput(std::istream &is, char del)
    {
        char *str{};
        std::string toRead;
        getline(is, toRead, del);
        if (is)
        {
            str = new char[strlen(toRead.c_str()) + 1];
            strcpy(str, toRead.c_str());
        }
        return str;
    }
}
