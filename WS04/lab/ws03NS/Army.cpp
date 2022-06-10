/*************************************************************************
Workshop 3 Part 1
Full Name   : Nishit Gaurang Shah
Student ID# : 130 176 217
Email       : ngshah3@myseneca.ca
Section     : OOP244NFF

Date : 3rd June 2022

Autheticity Declaraition :
I declare that I have done all the coding by myself and only copied the
code that my professor provided to complete my workshops and assignments.

*************************************************************************/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <string.h>
#include "Army.h"

using namespace std;

namespace sdds {
    //////////////////////////
    // FUNCTION DEFINITIONS 
    //////////////////////////
	void Army::setEmpty() {
        *nationality = '\0';
		unitsCount = 0;
		power = 0.0;

        return;
	}

    void Army::createArmy(const char* country, double pow, int troops) {
        if ((country != nullptr && strlen(country) >= 1) && pow > 0 && troops > 0) 
        {
            strcpy(nationality, country);
            nationality[strlen(country) + 1] = '\0';
            power = pow;
            unitsCount = troops;
        }
        else
        {
            setEmpty();
        }

        return;
    }

    void Army::updateUnits(int troops) {
        unitsCount = unitsCount + troops;
        power = power + (((double)troops * 25)/100);

        return;
    }

    const char* Army::checkNationality() const {
        return nationality;
    }

    int Army::checkCapacity() const {
        return unitsCount;
    }

    double Army::checkPower() const {
        return power;
    }

    bool Army::isEmpty() const {
        bool returnValue = true;
        if (*nationality == '\0' && unitsCount == 0 && power == 0)
        {
            // its empty
        }
        else
        {
            returnValue = false;
        }

        return returnValue;
    }

    bool Army::isStrongerThan(const Army& army) const {
        bool returnValue = true;
        if (power <= army.power) 
        {
            returnValue = false;
        }
        return returnValue;
    }

    void battle(Army& arm1, Army& arm2) {
        cout << "In battle of " << arm1.checkNationality() << " and " << arm2.checkNationality() << ", ";
        
        if (!(arm1.isEmpty() || arm2.isEmpty()))
        {
            int decrement = -1;
            if (arm2.isStrongerThan(arm1))
            {
                cout << arm2.checkNationality() << " is victorious!" << endl;
                decrement = decrement * (int)((arm1.checkCapacity() * 50) / 100);
                arm1.updateUnits(decrement);
            }
            else
            {
                cout << arm1.checkNationality() << " is victorious!" << endl;
                decrement = decrement * (int)((arm2.checkCapacity() * 50) / 100);
                arm2.updateUnits(decrement);
            }
        }
        return;
    }

    void displayDetails(const Army* armies, int size) {
        
        int i = 0;
        if (armies != nullptr && size > 0)
        {
            cout << "Armies reporting to battle:" << endl;
            for (i = 0; i < size; i++)
            {
                if (!armies[i].isEmpty())
                {
                    cout << "Nationality: " << armies[i].checkNationality() << ", ";
                    cout << "Units Count: " << armies[i].checkCapacity() << ", ";
                    cout << "Power left: " << fixed << setprecision(1) << armies[i].checkPower() << endl;
                }
            }
        }
        return;
    }
}