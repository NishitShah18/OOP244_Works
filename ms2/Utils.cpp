/*
Final Project Milestone 2
Module      : Utils
Filename    : Utils.h
Version 1.0
Author	    : Nishit Gaurang Shah
Student ID# : 130 176 217
Email       : ngshah3@myseneca.ca
Section     : OOP244NFF

Date : 22nd July 2022

Autheticity Declaraition :
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------
*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
using namespace std;
#include "Utils.h"
namespace sdds {
    void clearInputBuffer(void)
    {
        // Discard all remaining char's from the standard input buffer:
        while (getchar() != '\n')
        {
            ; // do nothing!
        }
    }

    void suspend(void)
    {
        printf("< Press [ENTER] key to continue >");
        clearInputBuffer();
        putchar('\n');
    }

    int inputInt(void)
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

    int inputIntRange(int lowerBound, int upperBound)
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
}
