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

#ifndef SDDS_SAVINGSACCOUNT_H__
#define SDDS_SAVINGSACCOUNT_H__
#include "Account.h"
namespace sdds {
	class SavingsAccount : public Account {
	private:
		double iRate;
	public:
		//constructor initializes balance and interest rate
		SavingsAccount(double, double);
		//perform month end transactions
		void monthEnd();
		//display inserts the account information into an ostream
		void display(std::ostream&) const;
	};
}
#endif