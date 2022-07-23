/*************************************************************************
Workshop 8
Full Name   : Nishit Gaurang Shah
Student ID# : 130 176 217
Email       : ngshah3@myseneca.ca
Section     : OOP244NFF
Date : 22nd July 2022
Autheticity Declaraition :
I declare that I have done all the coding by myself and only copied the
code that my professor provided to complete my workshops and assignments.
*************************************************************************/

#ifndef SDDS_IACCOUNT_H__
#define SDDS_IACCOUNT_H__
#include <iostream>
namespace sdds {
	class iAccount {
	public:
		virtual ~iAccount() {};
		//credit adds +ve amount to the balance
		virtual bool credit(double) = 0;
		//debit subtracts a +ve amount from the balance
		virtual bool debit(double) = 0;
		//month end adds month end costs
		virtual void monthEnd() = 0;
		//display inserts the account information into an ostream
		virtual void display(std::ostream&) const = 0;
	};
	//add prototype for Allocator function
	iAccount* CreateAccount(const char*, double);
}
#endif