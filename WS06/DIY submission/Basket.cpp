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

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <iomanip>
#include "Basket.h"

using namespace std;

namespace sdds {

	//the default constructor
	Basket::Basket()
	{
		m_fruits = nullptr;
		m_cnt = 0;
		m_price = 0.00;
	}

	//the custom constructor
	Basket::Basket(Fruit* n_fruits, int n_cnt, double n_price)
	{
		if ((n_fruits != nullptr) && (n_cnt > 0))
		{
			m_cnt = n_cnt;
			m_price = n_price;
			m_fruits = new Fruit[m_cnt];
			for (int i = 0; i < m_cnt; i++)
			{
				m_fruits[i] = n_fruits[i];
			}
		}
		else
		{
			m_fruits = nullptr;
			m_cnt = 0;
			m_price = 0.00;
		}
	}

	//the copy constructor
	Basket::Basket(const Basket& basket)
	{
		m_cnt = basket.m_cnt;
		m_price = basket.m_price;

		if (basket.m_fruits != nullptr)
		{
			m_fruits = new Fruit[m_cnt];
			for (int i = 0; i < m_cnt; i++)
			{
				m_fruits[i] = basket.m_fruits[i];
			}
		}
		else
		{
			m_fruits = nullptr;
		}
	}

	//the copy assignment operator
	Basket& Basket::operator=(const Basket& basket)
	{
		if (this != &basket) 
		{
			delete[] m_fruits;
			m_cnt = basket.m_cnt;
			m_price = basket.m_price;

			if (basket.m_fruits != nullptr) 
			{
				m_fruits = new Fruit[basket.m_cnt];
				for (int i = 0; i < m_cnt; i++) 
				{
					strcpy(m_fruits[i].m_name, basket.m_fruits[i].m_name);
					m_fruits[i].m_qty = basket.m_fruits[i].m_qty;
				}
			}
			else
			{
				m_fruits = nullptr;
			}
		}
		return *this;
	}

	//updates the m_price attribute to the value received as parameter
	void Basket::setPrice(double price)
	{
		m_price = price;
		return;
	}

	//returns true if the basket contains any fruits, false otherwise.
	Basket::operator bool()const 
	{
		return m_fruits != nullptr;
	}

	//receives an object of type Fruit (by value) as a parameter and adds it to the attribute m_fruits 
	//(resize the array-attribute; check previous workshops if you need a refresh on resizing a dynamic array)
	Basket& Basket::operator+=(Fruit fruit) 
	{
		m_cnt++;
		int index = m_cnt;
		Fruit* tempFruit = new Fruit[index];
		for (int i = 0; i < index-1; i++) {
			tempFruit[i] = m_fruits[i];
		}
		tempFruit[index-1] = fruit;
		delete[] m_fruits;
		m_fruits = tempFruit;

		return *this;
	}
	
	//the destructor
	Basket::~Basket() 
	{
		delete[] m_fruits;
		m_fruits = nullptr;
		m_cnt = 0;
		m_price = 0.00;
	}

	//overloads the insertion operator (operator<<) to insert into the stream
	std::ostream& operator<< (std::ostream& out, const Basket& b) 
	{
		if (b.m_fruits == nullptr || b.m_price == 0 || b.m_cnt == 0) 
		{
			out << "The basket is empty!" << endl;
		}
		else 
		{
			out << "Basket Content:" << endl;
			cout << fixed << setprecision(2);
			for (int i = 0; i < b.m_cnt; i++)
			{
				out << setw(10) << b.m_fruits[i].m_name << ": " << b.m_fruits[i].m_qty << "kg" << endl;
			}
			out << "Price: " << b.m_price << endl;
		}
		return out;
	}
}
