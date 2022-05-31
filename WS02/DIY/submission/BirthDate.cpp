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
#include<string.h>
#include"BirthDate.h"
#include"Utils.h"

using namespace std;

namespace sdds {

	//////////////////////////
	// GLOBAL VARIABLES 
	//////////////////////////
	BirthDateData* strptr = nullptr;
	BirthDateData* monthptr = nullptr;
	int userMonth = 0;
	int noOfBirthDates = 0;
	int monthMatched = 0;

	//////////////////////////
	// FUNCTION DEFINITIONS 
	//////////////////////////
	bool beginSearch(const char* filename)
	{
		bool returnValue = true;

		if (openFile(filename))
		{
			cout << "Birthdate search program" << endl;
			
			noOfBirthDates = noOfRecords();
			strptr = new BirthDateData[noOfBirthDates];

			char localString[LOCAL_ARRAY_SIZE + 1] = "\0";

			for (int i = 0; i < noOfBirthDates; i++)
			{
				//read name
				read(localString);
				strptr[i].name = new char[(strlen(localString) + 1)];
				strcpy(strptr[i].name, localString);

				//read Birth Date
				read(strptr[i].month);
				read(strptr[i].date);
				read(strptr[i].year,1); // year
			}
			closeFile();
		}
		else
		{
			cout << "Data file " << filename << " not found!" << endl;
			returnValue = false;
		}

		return returnValue;
	}

	bool readBirthDate(int month)
	{	
		userMonth = month;

		bool returnValue = false;
		int matchCounter = 0;
		int copyMatched = 0;

		for (int i = 0; i < noOfBirthDates; i++)
		{
			if (strptr[i].month == month)
			{
				matchCounter++;
			}
		}
		
		monthMatched = matchCounter;
		monthptr = new BirthDateData[monthMatched];

		for (int i = 0; i < noOfBirthDates; i++)
		{
			if (strptr[i].month == month)
			{
				monthptr[copyMatched].name = new char[(strlen(strptr[i].name) + 1)];
				strcpy(monthptr[copyMatched].name, strptr[i].name);

				monthptr[copyMatched].date = strptr[i].date;
				monthptr[copyMatched].month = strptr[i].month;
				monthptr[copyMatched].year = strptr[i].year;

				copyMatched++;
			}
		}

		if (matchCounter != 0)
		{
			returnValue = true;
		}

		return returnValue;
	}

	void sort()
	{
		BirthDateData tempData = {};
		for (int i = (noOfBirthDates - 1); i > 0; i--)
		{
			for (int j = 0; j < i; j++)
			{
				if (strptr[j].year > strptr[j + 1].year)
				{
					tempData = strptr[j];
					strptr[j] = strptr[j + 1];
					strptr[j + 1] = tempData;
				}
				else if (strptr[j].year == strptr[j + 1].year)
				{
					if (strptr[j].month > strptr[j + 1].month)
					{
						tempData = strptr[j];
						strptr[j] = strptr[j + 1];
						strptr[j + 1] = tempData;
					}
					else if (strptr[j].month == strptr[j + 1].month)
					{
						if (strptr[j].date > strptr[j + 1].date)
						{
							tempData = strptr[j];
							strptr[j] = strptr[j + 1];
							strptr[j + 1] = tempData;
						}
					}
				}
			}
		}
		tempData = {};
		return;
	}

	void displayBirthdays()
	{
		int matchCounter = 0;
		int i = 0;

		for (i = 0; i < noOfBirthDates; i++)
		{
			if (strptr[i].month == userMonth)
			{
				matchCounter++;
			}
		}

		cout << matchCounter << " birthdates found:" << endl;

		for (i = 0; i < monthMatched; i++)
		{
			cout << (i+1) << ") " << monthptr[i].name << ":" << endl;
			cout << monthptr[i].year << "-" << monthptr[i].month << "-" << monthptr[i].date << endl;
			cout << "===================================" << endl;
		}

		return;
	}

	void deallocate()
	{
		for (int i = 0; i < monthMatched; i++)
		{
			delete[] monthptr[i].name;
			cout << "deallocating" << i + 1 << endl;
		}
		delete[] monthptr;
		cout << "deallocated" << endl;
		return;
	}

	void endSearch()
	{
		closeFile();

		for (int i = 0; i < noOfBirthDates; i++)
		{
			delete[] strptr[i].name;
		}
		delete[] strptr;

		cout << "Birthdate Search Program Closed." << endl;

		return;
	}
}