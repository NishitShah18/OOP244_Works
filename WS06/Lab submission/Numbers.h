/*************************************************************************
Workshop 5 Part 1
Full Name   : Nishit Gaurang Shah
Student ID# : 130 176 217
Email       : ngshah3@myseneca.ca
Section     : OOP244NFF

Date : 24th June 2022

Autheticity Declaraition :
I declare that I have done all the coding by myself and only copied the
code that my professor provided to complete my workshops and assignments.

*************************************************************************/

#ifndef SDDS_NUMBERS_H_
#define SDDS_NUMBERS_H_
#include <iostream>
using namespace std;
namespace sdds {
   class Numbers {
      double* m_numbers;
      char* m_filename;
      bool m_isOriginal;
      int m_numCount;
      bool isEmpty()const;
      void setEmpty();
      void setFilename(const char* filename);
      void sort();
   public:
      Numbers();
      Numbers(const char* filename);
      Numbers(const Numbers& n);
      Numbers& operator= (const Numbers& n);
      double average()const;
      double max()const;
      double min()const;
      ~Numbers();
      int numberCount() const;
      bool load();
      void save();
      Numbers& operator+=(const double& num);
      ostream& display(ostream& ostr) const;

      friend istream& operator>>(std::istream& istr, Numbers& N);
      friend ostream& operator<<(std::ostream& os, const Numbers& N);
   };   
}
#endif // !SDDS_NUMBERS_H_
