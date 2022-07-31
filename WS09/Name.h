/*************************************************************************
Workshop 9
Full Name   : Nishit Gaurang Shah
Student ID# : 130 176 217
Email       : ngshah3@myseneca.ca
Section     : OOP244NFF
Date : 30th July 2022
Autheticity Declaraition :
I declare that I have done all the coding by myself and only copied the
code that my professor provided to complete my workshops and assignments.
*************************************************************************/

#ifndef SDDS_NAME_H__
#define SDDS_NAME_H__

#include <iostream>
using namespace std;
namespace sdds {
    class Name {
    private:
        char* m_name;
    public:
        // Constructors
        Name();
        Name(const char* name);
        
        void setEmpty();

        // Rule of three
        virtual ~Name();
        Name(const Name& name);
        Name& operator=(const Name& name);

        virtual operator const char* () const;  // Returns the address of the dynamic Cstring
        virtual operator bool() const;  // Return true if name is not empty, otherwise, it returns false.
        virtual ostream& display(ostream& ostr = cout) const;    // Inserts the Cstring value into ostr without going to new line if the Name is valid and then returns the ostr
        virtual istream& read(istream& istr = cin);  // Dynamically reads the Cstring from istr without any spaces (stops at space) and keeps the address in the m_value pointer
    };
    // Insertion and Extraction operator overloads
    ostream& operator<<(ostream& os, const Name& name);
    istream& operator>>(istream& is, Name& name);
};
#endif // !SDDS_NAME_H__