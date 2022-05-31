#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string.h>
#include"BirthDate.h"
#include"Utils.h"

using namespace std;

namespace sdds {

	BirthDateData* strptr = nullptr;
	int userMonth = 0;
	int noOfBirthDates = 0;
	char* fileName = nullptr;

	bool beginSearch(const char* filename)
	{
		bool returnValue = true;
		fileName = new char[(strlen(filename) + 1)];
		strcpy(fileName,filename);

		if (openFile(filename))
		{
			returnValue = true;
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
		load();

		userMonth = month;

		bool returnValue = false;
		int matchCounter = 0;

		for (int i = 0; i < noOfBirthDates; i++)
		{
			if (strptr[i].month == month)
			{
				matchCounter++;
			}
		}

		if (matchCounter != 0)
		{
			returnValue = true;
		}

		return returnValue;
	}

	void load()
	{
		openFile(fileName);

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
			read(strptr[i].year, 1); // year
		}
		closeFile();
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
		int index = 1;

		for (i = 0; i < noOfBirthDates; i++)
		{
			if (strptr[i].month == userMonth)
			{
				matchCounter++;
			}
		}

		cout << matchCounter << " birthdates found:" << endl;

		for (i = 0; i < noOfBirthDates; i++)
		{
			if (strptr[i].month == userMonth)
			{
				string tempString;
				for (int s = 0; s < (int)strlen(strptr[i].name); s++)
				{
					tempString = tempString + strptr[i].name[s];
				}
				cout << index << ") " << tempString << ":" << endl;
				cout << strptr[i].year << "-" << strptr[i].month << "-" << strptr[i].date << endl;
				cout << "===================================" << endl;
				index++;
			}
		}

		return;
	}

	void deallocate()
	{
		for (int i = 0; i < noOfBirthDates; i++)
		{
			delete[] strptr[i].name;
		}
		delete[] strptr;
	}

	void endSearch()
	{
		delete fileName;

		cout << "Birthdate Search Program Closed." << endl;
	}
}