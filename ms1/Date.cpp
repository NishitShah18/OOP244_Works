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
            ostr << ":";
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
        int i = inputIntRange(0, m_numberOfItems);
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


/*
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <iomanip>
#include "Menu.h"
#include "Utils.h"

using namespace std;
using namespace sdds;

namespace sdds {
    MenuItem::MenuItem() {
        m_menuItem = nullptr;
    }
    MenuItem::MenuItem(const char* content) {
        if (content != nullptr) {
            m_menuItem = new char[strlen(content) + 1];
            strcpy(m_menuItem, content);
        }
        else
            m_menuItem = nullptr;
    }
    std::ostream& MenuItem::displayMit(std::ostream& ostr) const
    {
        if (*this)
            ostr << m_menuItem;
        return ostr;
    }
    MenuItem::operator bool() const {
        return m_menuItem != nullptr;
    }
    MenuItem::operator
        const char* () const {
        return m_menuItem;
    }
    MenuItem::~MenuItem() {
        delete[] m_menuItem;
        m_menuItem = nullptr;
    }
    Menu::Menu() {
        m_menuTitle.m_menuItem = nullptr;
        m_numberOfItems = 0;
    }
    Menu::Menu(const char* menuTitle) {
        if (menuTitle != nullptr && menuTitle[0] != '\0') {
            int length = strlen(menuTitle) + 1;
            m_menuTitle.m_menuItem = new char[length];
            strcpy(m_menuTitle.m_menuItem, menuTitle);
        }
        else {
            delete[] m_menuTitle.m_menuItem;
            m_menuTitle.m_menuItem = nullptr;
            for (int i = 0; i < m_numberOfItems; i++) {
                delete m_itemList[i];
                m_itemList[i] = nullptr;
            }
            m_numberOfItems = 0;
        }
    }
    void Menu::printTitle() const {
        if (m_menuTitle != nullptr)
            cout << m_menuTitle.m_menuItem;
    }
    void Menu::display() const {
        printTitle();
        if (m_menuTitle != nullptr) {
            cout << ':' << endl;
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
    std::ostream& Menu::display(ostream& os) const {
        printTitle();
        return os;
    }
    Menu& Menu::operator<<(const char* menuitemConent) {
        if (menuitemConent != nullptr && m_numberOfItems < MAX_MENU_ITEMS) {
            m_itemList[m_numberOfItems] = new MenuItem(menuitemConent);
            m_numberOfItems++;
        }
        return *this;
    }
    Menu::operator bool() const {
        return m_menuTitle != nullptr;
    }
    Menu::operator int() const {
        return m_numberOfItems;
    }
    Menu::operator unsigned int() const {
        return m_numberOfItems;
    }
    int Menu::run() const {
        display();
        int input = inputIntRange(0, m_numberOfItems);
        return input;
    }
    const char* Menu::operator[](int i) const {
        return *m_itemList[i % m_numberOfItems];
    }
    int Menu::operator~() const {
        return run();
    }
    std::ostream& operator<<(std::ostream& os, const Menu& menu) {
        menu.display(os);
        return os;
    }
    Menu::~Menu() {
        delete[] m_menuTitle;
        m_menuTitle.m_menuItem = nullptr;
        for (int i = 0; i < m_numberOfItems; i++) {
            delete m_itemList[i];
            m_itemList[i] = nullptr;
        }
    }
}


/*
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
    std::ostream &operator<<(std::ostream& os, const Menu& menu)
   {
      return menu.displayTitle(os);
   }
}
*/