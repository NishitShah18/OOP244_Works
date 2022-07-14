/*
Final Project Milestone 1
Module      : Utils
Filename    : Utils.h
Version 1.0
Author	    : Nishit Gaurang Shah
Student ID# : 130 176 217
Email       : ngshah3@myseneca.ca
Section     : OOP244NFF

Date : 8th July 2022

Autheticity Declaraition :
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------
*/

#ifndef SDDS_UTILS_H__
#define SDDS_UTILS_H__
#include <iostream>
namespace sdds {
	void clearInputBuffer(void);
	void suspend(void);
	int inputInt(void);
	int inputIntRange(int lowerBound, int upperBound);
}
#endif // !SDDS_UTILS_H__
