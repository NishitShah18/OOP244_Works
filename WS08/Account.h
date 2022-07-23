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

#ifndef SDDS_ACCOUNT_H__
#define SDDS_ACCOUNT_H__
#include "iAccount.h"
namespace sdds {
	class Account : public iAccount {
	private:
		double accBalance;
	protected:
		double balance() const;
	public:
		//constructor initializes account balance, defaults to 0.0
		Account(double);
		//credit adds +ve amount to the balance
		bool credit(double);
		//debit subtracts a +ve amount from the balance
		bool debit(double);
	};
}
#endif
