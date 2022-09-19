/*************************************************************************
Workshop 3 Part 2
Full Name   : Nishit Gaurang Shah
Student ID# : 130 176 217
Email       : ngshah3@myseneca.ca
Section     : OOP244NFF
Date : 5th June 2022
Autheticity Declaraition :
I declare that I have done all the coding by myself and only copied the
code that my professor provided to complete my workshops and assignments.
*************************************************************************/

#ifndef SDDS_BARCHART_H
#define SDDS_BARCHART_H

#include "Bar.h"

namespace sdds {

    class BarChart {
        char* m_title;
        Bar* m_bar;
        char m_fillCharacter; 
        int m_noOfSamples; 
        int m_addSamples;
        
        void setEmpty();
        bool isValid() const;

    public:

        void init(const char* title, int noOfSamples, char fill);
        void add(const char* bar_title, int value);
        void draw() const;
        void deallocate();
    };

}

#endif 
