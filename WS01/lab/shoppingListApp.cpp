/*************************************************************************

Name			: Nishit Gaurang Shah
Student number	: 130 176 217
Email Id		: ngshah3@myseneca.ca
Section			: OOP244NFF

Autheticity Declaraition :
I declare that I have done all the coding by myself and only copied the
code that my professor provided to complete my workshops and assignments.

*************************************************************************/

#define _CTR_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdlib>
#include "File.h"
#include "ShoppingList.h"
#include "Utils.h"

using namespace std;
using namespace sdds;

// SET TO FALSE WHEN COMLING ON LINUX
const bool APP_OS_WINDOWS = true;

//////////////////////////
// FUNCTION PROTOTYPES 
//////////////////////////
int listMenu();

// MAIN: Entry-point to the application 
int main() {
    bool done = false;
    loadList();
    while (!done) {
        //system(APP_OS_WINDOWS ? "cls" : "clear");
        // I commented this function out because I was not able to submit my work using terminal on my MacBook
	switch (listMenu()) {
        case 1:
            toggleBought();
            break;
        case 2:
            addItemToList();
            break;
        case 3:
            removeItemfromList();
            break;
        case 4:
            removeBoughtItems();
            break;
        case 5:
            clearList();
            break;
        default:
            done = true;
        }
    }
    saveList();
    return 0;
}

//////////////////////////
// FUNCTION DEFINITIONS 
//////////////////////////
int listMenu() {
    cout << "-->>> My Shopping List <<<--" << endl;
    displayList();
    cout << "----------------------------" << endl
        << "1- Toggle bought Item" << endl
        << "2- Add Shopping Item" << endl
        << "3- Remove Shopping Item" << endl
        << "4- Remove bought Items" << endl
        << "5- Clear List" << endl
        << "0- Exit" << endl << "> ";
    return readInt(0, 5);
}