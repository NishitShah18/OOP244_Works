/*************************************************************************
Workshop 2 Part 1
Full Name   : Nishit Gaurang Shah
Student ID# : 130 176 217
Email       : ngshah3@myseneca.ca
Section     : OOP244NFF

Date : 27th May 2022

Autheticity Declaraition :
I declare that I have done all the coding by myself and only copied the
code that my professor provided to complete my workshops and assignments.

*************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

namespace sdds {

    //////////////////////////
    // GLOBAL VARIABLE(S) 
    //////////////////////////
    FILE* fptr;

    //////////////////////////
    // FUNCTION DEFINITIONS 
    //////////////////////////
    bool openFile(const char filename[]) {
        fptr = fopen(filename, "r");
        return fptr != NULL;
    }

    int noOfRecords() {
        int noOfRecs = 0;
        char ch;
        while (fscanf(fptr, "%c", &ch) == 1) {
            noOfRecs += (ch == '\n');
        }
        rewind(fptr);
        return noOfRecs;
    }

    void closeFile() {
        if (fptr) fclose(fptr);
    }

    bool read(char* name)
    {
        int returnValue = (fscanf(fptr, "%[^,],", name) == 1);
        return returnValue;
    }

    bool read(int& studentNumber)
    {
        int returnValue = (fscanf(fptr, "%d,", &studentNumber) == 1);
        return returnValue;
    }

    bool read(char& grade)
    {
        int returnValue = (fscanf(fptr, "%c\n", &grade) == 1);
        return returnValue;
    }
}