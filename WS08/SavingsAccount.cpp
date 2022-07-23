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

#include <iomanip>
#include "SavingsAccount.h"
using namespace std;
namespace sdds {
	SavingsAccount::SavingsAccount(double balance, double rate) : Account(balance) {
		if (rate > 0) {
			iRate = rate;
		}
		else {
			iRate = 0.0;
		}
	}

	void SavingsAccount::monthEnd() {
		double interest = (balance() * iRate);
		credit(interest);
		return;
	}
	void SavingsAccount::display(std::ostream& ostr) const {
		ostr << "Account type: Savings" << endl;
		ostr << "Balance: $" << fixed << setprecision(2) << balance() << endl;
		ostr << "Interest Rate (%): " << fixed << setprecision(2) << iRate << endl;
		return;
	}
}