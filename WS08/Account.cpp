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

#include "Account.h"
namespace sdds {
	Account::Account(double balance) {
		if (balance > 0) {
			accBalance = balance;
		}
		else {
			accBalance = 0.0;
		}
	}
	bool Account::credit(double balance) {
		bool returnValue = false;
		if (balance > 0) {
			accBalance = accBalance + balance;
			returnValue = true;
		}
		return returnValue;
	}
	bool Account::debit(double balance) {
		bool returnValue = false;
		if (balance > 0) {
			accBalance = accBalance - balance;
			returnValue = true;
		}
		return returnValue;
	}
	double Account::balance() const {
		return accBalance;
	}
}