/*
Final Project Milestone 5
Module      : Utils
Filename    : Utils.cpp
Version 4.0

Author	    : Nishit Gaurang Shah
Student ID# : 130 176 217
Email       : ngshah3@myseneca.ca
Section     : OOP244NFF

Date : 2nd August 2022

Autheticity Declaraition :
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------
*/

// Revision History
// ---------------------------------------------------------------------
// Name               Date                 Reason
// Nishit             2022/07/29		   Implementation of Utils Class
// Nishit             2022/08/02           Implementation of suspend(), inputInt() and inputIntRange().
// Nishit             2022/08/02           Created new functions for custom error messages

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
    void Utils::suspend(void)
    {
        printf("< Press [ENTER] key to continue >");
        clearInputBuffer();
        putchar('\n');
    }

    int Utils::inputInt(void)
    {
        int number = 0, exitPrompt = 0;
        char newLine = '\0';

        do
        {
            //cpp problems :(
            exitPrompt = scanf(" %d%c", &number, &newLine);
            exitPrompt = 0;
            if (newLine != '\n')
            {
                clearInputBuffer();
                printf("Invalid Selection, try again: ");
            }
            else
            {
                exitPrompt = 1;
            }
        } while (exitPrompt != 1);
        exitPrompt = 0;

        return number;
    }

    int Utils::inputIntWithMessage(char* message)
    {
        int number = 0, exitPrompt = 0;
        char newLine = '\0';

        do
        {
            //cpp problems :(
            exitPrompt = scanf(" %d%c", &number, &newLine);
            exitPrompt = 0;
            if (newLine != '\n')
            {
                clearInputBuffer();
                cout << message;
            }
            else
            {
                exitPrompt = 1;
            }
        } while (exitPrompt != 1);
        exitPrompt = 0;

        return number;
    }

    int Utils::inputIntRange(int lowerBound, int upperBound)
    {
        int number = 0, exitPrompt = 0;

        do
        {
            number = inputInt();
            if (number < lowerBound || number > upperBound)
            {
                printf("Invalid Selection, try again: ");
            }
            else
            {
                exitPrompt = 1;
            }
        } while (exitPrompt != 1);
        exitPrompt = 0;

        return number;
    }

    int Utils::inputIntRangeWithMessage(int lowerBound, int upperBound, char *message)
    {
        int number = 0, exitPrompt = 0;

        do
        {
            number = inputIntWithMessage(message);
            if (number < lowerBound || number > upperBound)
            {
                cout << message;
            }
            else
            {
                exitPrompt = 1;
            }
        } while (exitPrompt != 1);
        exitPrompt = 0;

        return number;
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
