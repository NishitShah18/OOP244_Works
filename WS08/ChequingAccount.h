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

#ifndef SDDS_CHEQUINGACCOUNT_H__
#define SDDS_CHEQUINGACCOUNT_H__
#include "Account.h"
namespace sdds {
	class ChequingAccount : public Account {
		double transFee;
		double monthFee;
	public:
		//constructor initializes account balance and transaction fee
		ChequingAccount(double, double, double);
		//credit adds +ve amount to the balance
		bool credit(double);
		//debit subtracts a +ve amount from the balance
		bool debit(double);
		//month end
		void monthEnd();
		//display inserts the account information into an ostream
		void display(std::ostream&) const;
	};
}
#endif