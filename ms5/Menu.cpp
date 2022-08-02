/*
Final Project Milestone 5
Module      : Menu
Filename    : Menu.cpp
Version 1.0

Author	    : Nishit Gaurang Shah
Student ID# : 130 176 217
Email       : ngshah3@myseneca.ca
Section     : OOP244NFF

Date : 2nd August 2022

Autheticity Declaraition :
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Menu.h"
#include "Utils.h"
using namespace std;
namespace sdds {
    MenuItem::MenuItem() {
        m_menuItem = nullptr;
    }

    MenuItem::MenuItem(const char* item)
    {
        if (item != nullptr) {
            m_menuItem = new char[strlen(item) + 1];
            strcpy(m_menuItem, item);
        }
        else {
            m_menuItem = nullptr;
        }
    }

    MenuItem::operator bool() const
    {
        return m_menuItem != nullptr;
    }

    MenuItem::operator const char* () const
    {
        return m_menuItem;
    }

    std::ostream& MenuItem::display(std::ostream& os) const
    {
        if (*this) {
            os << m_menuItem;
        }
        return os;
    }

    MenuItem::~MenuItem()
    {
        delete[] m_menuItem;
    }

    Menu::Menu() {
        m_menuTitle.m_menuItem = nullptr;
        m_numberOfItems = 0;
    }

    Menu::Menu(const char* menuTitle) : m_menuTitle(menuTitle), m_numberOfItems(0) {}

    std::ostream& Menu::displayTitle(std::ostream& os) const
    {
        return m_menuTitle.display(os);
    }

    std::ostream& Menu::displayMenu(std::ostream& ostr) const
    {
        if (m_menuTitle) {
            displayTitle(ostr);
            ostr << endl;
        }
        if (!(m_numberOfItems < 0)) {
            int i = 0;
            while (i < m_numberOfItems) {
                cout.width(2);
                cout.setf(ios::right);
                cout << i + 1;
                cout << "- ";
                cout << m_itemList[i]->m_menuItem << endl;
                i++;
            }
            cout << " 0- Exit" << endl;
            cout << "> ";
        }
        return ostr;
    }

    int Menu::run()const {
        displayMenu(cout);
        int i = Utils::inputIntRange(0, m_numberOfItems);
        return i;
    }

    int Menu::operator~() const {
        return run();
    }

    Menu& Menu::operator<<(const char* menuitemConent)
    {
        if (menuitemConent != nullptr && m_numberOfItems < MAX_MENU_ITEMS)
        {
            m_itemList[m_numberOfItems] = new MenuItem(menuitemConent);
            m_numberOfItems++;
        }
        return *this;
    }

    Menu::operator int() const { return m_numberOfItems; }
    Menu::operator unsigned int() const { return m_numberOfItems; }

    Menu::operator bool()const {
        return m_menuTitle != nullptr;
    }

    const char* Menu::operator[](int i)const {
        if (i >= m_numberOfItems) {
            i = i % m_numberOfItems;
        }
        return m_itemList[i]->m_menuItem;
    }

    Menu::~Menu()
    {
        for (int i = 0; i < m_numberOfItems; i++)
        {
            delete m_itemList[i];
        }
    }

    std::ostream& operator<<(std::ostream& os, const Menu& menu)
    {
        return menu.displayTitle(os);
    }
}

