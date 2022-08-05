/*
Workshop 10
Filename    : templateFunctions.h
Version 2.0

Author	    : Nishit Gaurang Shah
Student ID# : 130 176 217
Email       : ngshah3@myseneca.ca
Section     : OOP244NFF

Date : 5 August 2022

Autheticity Declaraition :
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------
*/

#ifndef SDDS_TEMPLATEFUNCTIONS_H_
#define SDDS_TEMPLATEFUNCTIONS_H_
#include <iostream>
#include "Collection.h"
using namespace std;
namespace sdds {
	//Function template checks if a key value matches an array item at a provided index Arguments.
	template <typename type1, typename type2>
	bool find(type1 arrayOfTemplatedObjects[], type2 keyTemplatedValue, int i) {
		bool returnValue = false;
		if (arrayOfTemplatedObjects[i] == keyTemplatedValue)
		{
			returnValue = true;
		}
		return returnValue;
	}
	/*
		Code needed to use this function :
		find(Object of either Book, Card or Pet, cString, integer)
	*/

	//Function template accepts four arguments in any order you prefer
	template <typename type1, typename type2, typename type3>
	int find(const type1 arrayOfTemplatedObjects[], int numberOfElements, const type2 keyTemplatedValue, const type3 anotherKeyTemplatedValue) {
		int result = 0, count = 0;
		for (int i = 0; i < numberOfElements && count == 0; i++) {
			if ((arrayOfTemplatedObjects[i] == keyTemplatedValue) && (arrayOfTemplatedObjects[i] == anotherKeyTemplatedValue)) {
				count++;
				result = i;
			}
		}
		if (count == 0)
		{
			result = -1;
		}
		return result;
	}

	//Lists all the elements of an array.
	template <typename type1>
	ostream& operator<<(ostream& ostr, Collection<type1>& collectionTemplate) {
		int length = collectionTemplate.size();
		
		for (int i = 0; i < length; i++) {
			ostr << collectionTemplate[i] << endl;
		}

		return ostr;
	}

	//Loads Collection
	template <typename type1>
	const Collection<type1>& loadCollection(Collection<type1>& collectionTemplate, type1 object) {
		collectionTemplate += object;
		return collectionTemplate;
	}

}
#endif // !SDDS_SEARCH_H_
