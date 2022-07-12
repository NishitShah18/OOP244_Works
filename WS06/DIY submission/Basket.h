/*************************************************************************
Workshop 6 Part 2
Full Name   : Nishit Gaurang Shah
Student ID# : 130 176 217
Email       : ngshah3@myseneca.ca
Section     : OOP244NFF
Date : 11th July 2022
Autheticity Declaraition :
I declare that I have done all the coding by myself and only copied the
code that my professor provided to complete my workshops and assignments.
*************************************************************************/

#ifndef SDDS_BASKET_H
#define SDDS_BASKET_H

#include <iostream>
using namespace std;

namespace sdds {
	struct Fruit
	{
		char m_name[30 + 1];	// the name of the fruit
		double m_qty;			// quantity in kilograms
	};
	class Basket
	{
		Fruit* m_fruits;		// a dynamically allocated array of objects of type Fruit
		int m_cnt;				// the size of the m_fruits array.
		double m_price;			// the price of the basket.
	public:
		//the default constructor
		Basket();
		//a custom constructor
		Basket(Fruit* n_fruits, int n_cnt, double n_price);
		//the copy constructor
		Basket(const Basket& basket);
		//the copy assignment operator
		Basket& operator=(const Basket& basket);
		//void setPrice(double price): updates the m_price attribute to the value received as parameter
		void setPrice(double price);
		//the conversion to bool operator: returns true if the basket contains any fruits, false otherwise.
		operator bool()const;
		//an overload of the +=
		Basket& operator+=(Fruit fruit);
		//the destructor
		~Basket();
		//overload the insertion operator (operator<<)
		friend std::ostream& operator<<(std::ostream& out, const Basket& basket);
	};
}
#endif // !SDDS_BASKET_H
