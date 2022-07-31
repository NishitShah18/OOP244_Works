/*
Final Project Milestone 3
Module      : Publication
Filename    : Publication.cpp
Version 1.0

Author	    : Nishit Gaurang Shah
Student ID# : 130 176 217
Email       : ngshah3@myseneca.ca
Section     : OOP244NFF

Date : 29th July 2022

Autheticity Declaraition :
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <iomanip>
#include <cstring>
#include "Utils.h"
#include "Publication.h"
using namespace std;
namespace sdds
{
    Publication::Publication()
    {
        deleteAll();
    }
    Publication::Publication(const Publication &src)
    {
        operator=(src);
    }
    Publication &Publication::operator=(const Publication &src)
    {
        if (this != &src && src)
        {
            Utils::copyStr(m_title, src.m_title);
            m_membership = src.m_membership;
            strcpy(m_shelfId, src.m_shelfId);
            m_libRef = src.m_libRef;
            m_date = src.m_date;
        }
        return *this;
    }
    Publication::~Publication()
    {
        delete[] m_title;
    }

    void Publication::set(int member_id)
    {
        if (member_id == 0)
            m_membership = member_id;
        else
        {
            if (member_id >= 10000 && member_id <= 99999)
                m_membership = member_id;
        }
    }
    void Publication::setRef(int value)
    {
        m_libRef = value;
    }
    void Publication::resetDate()
    {
        m_date.resetDate();
    }
    char Publication::type() const
    {
        return 'P';
    }
    bool Publication::onLoan() const
    {
        return m_membership != 0;
    }
    Date Publication::checkoutDate() const
    {
        return m_date;
    }
    bool Publication::operator==(const char *title) const
    {
        return strstr(m_title, title) != nullptr;
    }
    Publication::operator const char* () const
    {
        return m_title;
    }
    int Publication::getRef() const
    {
        return m_libRef;
    }

    bool Publication::conIO(ios &io) const
    {
        return (&io == &cin || &io == &cout);
    }
    ostream &Publication::write(ostream &os) const
    {
        if (conIO(os))
        {
            os << "| " << m_shelfId << " | ";
            if (strlen(m_title) > SDDS_TITLE_WIDTH)
            {
                for (int i = 0; i < SDDS_TITLE_WIDTH; i++)
                    os << m_title[i];
            }
            else
            {
                os.setf(ios::left);
                os.fill('.');
                os.width(SDDS_TITLE_WIDTH);
                os << m_title;
                os.fill(' ');
                os.unsetf(ios::left);
            }
            os << " | ";
            if (m_membership != 0) os << m_membership;
            else os << " N/A ";
            os << " | " << m_date << " |";
        }
        else
        {
            os << type() << "\t" << m_libRef << "\t" << m_shelfId << "\t" << m_title << "\t" << m_membership << "\t" << m_date;
        }
        return os;
    }
    istream &Publication::read(istream &istr)
    {
        deleteAll();
        char shelfId[SDDS_SHELF_ID_LEN + 1];
        char *title{};
        Date date;
        int libRef = -1;
        int membership = 0;

        if (m_title) {
            delete[] m_title;
            m_title = nullptr;
        }

        if (conIO(istr))
        {
            cout << "Shelf No: ";
            istr.getline(shelfId, SDDS_SHELF_ID_LEN + 1, '\n');
            if (strlen(shelfId) < SDDS_SHELF_ID_LEN)
                istr.setstate(ios::failbit);
            cout << "Title: ";
            title = Utils::readInput(istr);
            cout << "Date: ";
            date.read(istr);
        }
        else
        {
            istr >> libRef;
            Utils::getChar(istr, '\t');
            istr >> shelfId;
            Utils::getChar(istr, '\t');
            title = Utils::readInput(istr, '\t');
            istr >> membership;
            Utils::getChar(istr, '\t');
            date.read(istr);
        }

        if (!date) istr.setstate(ios::failbit);

        if (istr)
        {
            Utils::copyStr(m_title, title);
            strcpy(m_shelfId, shelfId);
            set(membership);
            setRef(libRef);
            m_date = date;
        }
        delete[] title;
        return istr;
    }
    Publication::operator bool() const
    {
        bool returnValue = false;
        if (m_title != nullptr && m_shelfId[0] != '\0') {
            returnValue = true;
        }
        return returnValue;
    }
    void Publication::deleteAll()
    {
        delete[] m_title;
        m_libRef = -1;
        m_shelfId[0] = '\0';
        m_membership = 0;
        m_title = nullptr;
        m_date.resetDate();
    }
}
