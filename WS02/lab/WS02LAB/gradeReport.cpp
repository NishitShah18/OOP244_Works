/* ------------------------------------------------------
Workshop 2 part 1
Module: N/A
Filename: gradeReport.cpp 
  in submission this file will be replaced with main_prof.cpp
  that loads "simpsons.csv" instead
Version 1
Revision History
-----------------------------------------------------------
Date       Reason
-----------------------------------------------------------*/

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

#include "Student.h"
using namespace sdds;
int main() {
   if (load("students.csv")) {
      display();
   }
   deallocateMemory();
   return 0;
}