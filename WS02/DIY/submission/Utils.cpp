/*************************************************************************
Workshop 2 Part 2
Full Name   : Nishit Gaurang Shah
Student ID# : 130 176 217
Email       : ngshah3@myseneca.ca
Section     : OOP244NFF

Date : 30th May 2022

Autheticity Declaraition :
I declare that I have done all the coding by myself and only copied the
code that my professor provided to complete my workshops and assignments.

*************************************************************************/

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include"Utils.h"
#include"BirthDate.h"

using namespace std;

namespace sdds {

    //////////////////////////
    // GLOBAL VARIABLE(S) 
    //////////////////////////
    FILE* fptr;

    //////////////////////////
    // FUNCTION DEFINITIONS 
    //////////////////////////
    bool openFile(const char filename[]) {
        bool returnValue = true;
        fptr = fopen(filename, "r");
        if (fptr == NULL)
        {
            returnValue = false;
        }
        return returnValue;
    }

    void closeFile() {
        if (fptr) fclose(fptr);
    }

    int noOfRecords() {
        int noOfRecs = 0;
        char ch;
        for (ch = getc(fptr); ch != EOF; ch = getc(fptr))
        {
            if (ch == '\n')
            {
                noOfRecs = noOfRecs + 1;
            }
        }
        rewind(fptr);
        return noOfRecs;
    }

    bool read(char* name)
    {
        int returnValue = (fscanf(fptr, "%[^,],", name) == 1);
        return returnValue;
    }
    bool read(int& monthOrDate)
    {
        int returnValue = (fscanf(fptr, "%d/", &monthOrDate) == 1);
        return returnValue;
    }
    bool read(int& year,int isYear)
    {
        int returnValue = (fscanf(fptr, "%d\n", &year) == 1);
        return returnValue;
    }
}