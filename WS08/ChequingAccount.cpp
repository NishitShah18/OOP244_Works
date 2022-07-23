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
#include "ChequingAccount.h"
using namespace std;
namespace sdds {
	ChequingAccount::ChequingAccount(double balance, double transF, double monthF) : Account(balance) {
		if (transF > 0) {
			transFee = transF;
		}
		else {
			transFee = 0;
		}
		if (monthF > 0) {
			monthFee = monthF;
		}
		else {
			monthFee = 0;
		}
	}

	bool ChequingAccount::credit(double balance) {
		bool returnValue = false;
		if (Account::credit(balance)) {
			Account::debit(transFee);
			returnValue = true;
		}
		return returnValue;
	}

	bool ChequingAccount::debit(double balance) {
		bool returnValue = false;
		if (Account::debit(balance)) {
			Account::debit(transFee);
			returnValue = true;
		}
		return returnValue;
	}

	void ChequingAccount::monthEnd() {
		ChequingAccount::debit(monthFee);
	}

	void ChequingAccount::display(ostream& ostr) const {
		ostr << "Account type: Chequing" << endl;
		ostr << "Balance: $" << fixed << setprecision(2) << balance() << endl;
		ostr << "Per Transaction Fee: " << fixed << setprecision(2) << transFee << endl;
		ostr << "Monthly Fee: " << fixed << setprecision(2) << monthFee << endl;
	}
}
