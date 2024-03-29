/*
Final Project Milestone 1
Module      : Date
Filename    : Date.cpp
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
#include <iomanip>
#include <iostream>
#include <ctime>
#include <Utils.h>
using namespace std;
#include "Date.h"
namespace sdds {
   bool Date::validate() {
      errCode(NO_ERROR);
      if (m_year < MIN_YEAR || m_year > m_CUR_YEAR + 1) {
         errCode(YEAR_ERROR);
      }
      else if (m_mon < 1 || m_mon > 12) {
         errCode(MON_ERROR);
      }
      else if (m_day < 1 || m_day > mdays()) {
         errCode(DAY_ERROR);
      }
      return !bad();
   }
   int Date::mdays()const {
      int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
      int mon = m_mon >= 1 && m_mon <= 12 ? m_mon : 13;
      mon--;
      return days[mon] + int((mon == 1) * ((m_year % 4 == 0) && (m_year % 100 != 0)) || (m_year % 400 == 0));
   }
   int Date::systemYear()const {
      time_t t = time(NULL);
      tm lt = *localtime(&t);
      return lt.tm_year + 1900;
   }
   void Date::setToToday() {
      time_t t = time(NULL);
      tm lt = *localtime(&t);
      m_day = lt.tm_mday;
      m_mon = lt.tm_mon + 1;
      m_year = lt.tm_year + 1900;
      errCode(NO_ERROR);
   }
   int Date::daysSince0001_1_1()const { // Rata Die day since 0001/01/01
      int ty = m_year;
      int tm = m_mon;
      if (tm < 3) {
         ty--;
         tm += 12;
      }
      return 365 * ty + ty / 4 - ty / 100 + ty / 400 + (153 * tm - 457) / 5 + m_day - 306;
   }
   Date::Date() :m_CUR_YEAR(systemYear()) {
      setToToday();
   }
   Date::Date(int year, int mon, int day) : m_CUR_YEAR(systemYear()) {
      m_year = year;
      m_mon = mon;
      m_day = day;
      validate();
   }
   const char* Date::dateStatus()const {
      return DATE_ERROR[errCode()];
   }
   int Date::currentYear()const {
      return m_CUR_YEAR;
   }
   void Date::errCode(int readErrorCode) {
      m_ErrorCode = readErrorCode;
   }
   int Date::errCode()const {
      return m_ErrorCode;
   }
   bool Date::bad()const {
      return m_ErrorCode != 0;
   }

   std::istream& Date::read(std::istream& is) {
       //Clears the error code by setting it NO_ERROR
       errCode(NO_ERROR);

       // Reads the year using istream 
       is >> m_year;
       // Ignores a single character after the year value to bypass the Slash.
       is.ignore();
       // Reads the month using istream
       is >> m_mon;
       // Ignores a single character after the month value to bypass the Slash.
       is.ignore();
       // Reads the day using istream
       is >> m_day;

       // Checks if istream has failed.  . If not, it will validate the values entered.
       if (is.fail()) {
           // If it did fail, 
           // It will set the error code to CIN_FAILED
           errCode(CIN_FAILED);
           // And clears the istream
           is.clear();
       }
       else {
           // If not, it will validate the values entered.
           this -> validate();
       }

       // Flushes the keyboard
       clearInputBuffer();
       
       // Returns the istream object
       return is;
   }

   std::ostream& Date::write(std::ostream& os)const {
       // If the Date object is in a “bad” state (it is invalid) print the “dateStatus()”.
       if (bad()) {
           os << dateStatus();
       }

       // Otherwise, the function should write the date using the ostream object
       else {
           // Prints the year
           os << m_year;
           // Prints a Slash “/”
           os << '/';
           // Prints the month in two spaces, padding the left digit with zero if the month is a single-digit number
           os.fill('0');
           os << right << setw(2) << m_mon;
           // Prints a Slash “/”
           os << '/';
           // Prints the day in two spaces, padding the left digit with zero if the day is a single-digit number
           os << right << setw(2) << m_day;
           // Makes sure the padding is set back to spaces from zero
           os.fill(' ');
       }

       // Returns the ostream object
       return os;
   }
   
   // Comparison operator overload methods
   bool Date::operator== (const Date& rhs)const {
       return (this->daysSince0001_1_1() == rhs.daysSince0001_1_1());
   }

   bool Date::operator!= (const Date& rhs)const {
       return (this->daysSince0001_1_1() != rhs.daysSince0001_1_1());
   }
   bool Date::operator>= (const Date& rhs)const {
       return (this->daysSince0001_1_1() >= rhs.daysSince0001_1_1());
   }

   bool Date::operator<= (const Date& rhs)const {
       return (this->daysSince0001_1_1() <= rhs.daysSince0001_1_1());
   }

   bool Date::operator< (const Date& rhs)const {
       return (this->daysSince0001_1_1() < rhs.daysSince0001_1_1());
   }

   bool Date::operator> (const Date& rhs)const {
       return (this->daysSince0001_1_1() > rhs.daysSince0001_1_1());
   }

   int Date::operator- (const Date& rhs)const {
       return (daysSince0001_1_1() - rhs.daysSince0001_1_1());
   }

   // Bool type conversion operator
   Date::operator bool()const {
       return (m_year >= 1500 && m_year <= m_CUR_YEAR &&
           m_mon >= 1 && m_mon <= 12 &&
           m_day >= 1 && m_day <= mdays());
   }

   ostream& operator<<(ostream& os, const Date& RO) {
      return RO.write(os);
   }
   istream& operator>>(istream& is, Date& RO) {
      return RO.read(is);
   }

}
