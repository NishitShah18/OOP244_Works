/*
Final Project Milestone 1
Module      : Menu
Filename    : Menu.cpp
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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Menu.h"
#include <iomanip>

using namespace std;

namespace sdds {
    MenuItem::MenuItem() {
        m_menuItem = nullptr;
    }

    MenuItem::MenuItem(const char* item) {
        delete[] m_menuItem;
        m_menuItem = new char[strlen(item) + 1];
        strcpy(m_menuItem, item);
    }

    MenuItem::operator bool()const {
        if (m_menuItem != nullptr) return true;
        return false;
    }

    MenuItem::operator const char*()const { 
        return m_menuItem;
    }

    void MenuItem::displayMit(ostream& os)const {
        os << m_menuItem;
        return;
    }

    MenuItem::~MenuItem() {
        delete[] m_menuItem;
    }

    Menu::Menu() {
        m_menuTitle.m_menuItem = nullptr;
        m_numberOfItems = 0;
        for (int i = 0; i < m_numberOfItems; i++) {
            m_itemList[i]->m_menuItem = nullptr;
        }
    }

    Menu::Menu(const char* menuTitle) {
        if (menuTitle != nullptr && menuTitle[0] != '\0') {
            m_menuTitle.m_menuItem = new char[strlen(menuTitle) + 1];
            strcpy(m_menuTitle.m_menuItem, menuTitle);
            for (int i = 0; i < m_numberOfItems; i++) {
                m_itemList[i] = nullptr;
            }
            m_numberOfItems = 0;
        }
        else {
            delete[] m_menuTitle.m_menuItem;
            m_menuTitle.m_menuItem = nullptr;
            for (int i = 0; i < m_numberOfItems; i++) {
                m_itemList[i] = nullptr;
            }
            m_numberOfItems = 0;
        }
    }

    void Menu::printTitle(ostream& os)const {
        if (m_menuTitle != nullptr) {
            os << m_menuTitle.m_menuItem;
        }
        return;
    }

    void Menu::display() const {
        if (m_menuTitle != nullptr) {
            cout << m_menuTitle.m_menuItem << ':' << endl;
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
    }

    int Menu::run()const{
        display();
        int i = inputIntRange(0, m_numberOfItems);
        return i;
    }

    int Menu::operator~()const{
        // I really can't think onther way to do this. But I will try next time.
        return run();
    }

    Menu& Menu::operator<< (const char* menuitemConent) {
        if (menuitemConent != nullptr && m_numberOfItems < MAX_MENU_ITEMS) {
            m_itemList[m_numberOfItems] = new MenuItem(menuitemConent); // i tried to do this : m_itemList[m_numberOfItems++] = new MenuItem(menuitemConent); but it did not work, idk why?
            m_numberOfItems++;
        }
        return *this;
    }

    Menu::operator int()const { return m_numberOfItems; }

    Menu::operator unsigned int()const { return m_numberOfItems; }
    
    Menu::operator bool()const {
        return m_menuTitle != nullptr;
    }

    const char* Menu::operator[](int i)const {
        if (i >= m_numberOfItems) {
            i = i % m_numberOfItems;
        }
        return m_itemList[i]->m_menuItem;
    }

    Menu::~Menu() {
        delete[] m_menuTitle;
        m_menuTitle.m_menuItem = nullptr;
        for (int i = 0; i < m_numberOfItems; i++) {
            delete m_itemList[i]->m_menuItem;
            m_itemList[i] = nullptr;
        }
    }

    std::ostream& operator<<(std::ostream& os, const Menu& menu) {
        menu.printTitle(os);
        return os;
    }
}
