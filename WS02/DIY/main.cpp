/* ------------------------------------------------------
Workshop 2 part 2
Module: N/A
Filename: main.cpp
Version 1.1
Revision History
-----------------------------------------------------------
Date       Reason
may 25th   Data file had bad records and are fixed now.
-----------------------------------------------------------*/
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

#include <iostream>
#include "BirthDate.h"
using namespace std;
using namespace sdds;
int main() {
   bool done = false;
   int month = 0;
   char filename[256];
   cout << "V1.1 corrected the data file records" << endl;
   cout << "Enter data file name: ";
   cin >> filename;
   if (beginSearch(filename)) {
      while (!done) {
         cout << "Enter a month of birth or 0 to exit: ";
         cin >> month;
         if (month == 0) {
            done = true;
         }
         else {
            if (readBirthDate(month)) {
               sort();
               displayBirthdays();
               deallocate();
            }
            else {
               cout << "No match found!" << endl;
            }
         }
      }
      endSearch();
   }
   return 0;
}