/*************************************************************************
Workshop 4 Part 1
Full Name   : Nishit Gaurang Shah
Student ID# : 130 176 217
Email       : ngshah3@myseneca.ca
Section     : OOP244NFF

Date : 10th June 2022

Autheticity Declaraition :
I declare that I have done all the coding by myself and only copied the
code that my professor provided to complete my workshops and assignments.

*************************************************************************/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <string.h>
#include "Car.h"

using namespace std;

namespace sdds {
	//////////////////////////////////////
	// CLASS FUNCTION DEFINITIONS 
	//////////////////////////////////////
	void Car::resetInfo() {
		delete[] m_type;
		delete[] m_brand;
		delete[] m_model;
		m_type = nullptr;
		m_brand = nullptr;
		m_model = nullptr;
		m_year = 0;
		m_code = 0;
		m_price = 0;
	}

	Car::Car() {
		m_type = nullptr;
		m_brand = nullptr;
		m_model = nullptr;
		resetInfo();
	}

	Car::Car(const char* type, const char* brand, const char* model) {
		if (type == nullptr || brand == nullptr || model == nullptr)
		{
			resetInfo();
		}
		else
		{
			m_type = new char[strlen(type) + 1];
			strcpy(m_type, type);
			m_brand = new char[strlen(brand) + 1];
			strcpy(m_brand, brand);
			m_model = new char[strlen(model) + 1];
			strcpy(m_model, model);
			m_year = 2022;
			m_code = 100;
			m_price = 1;
		}
	}

	Car::Car(const char* type, const char* brand, const char* model, int year, int code, double price) {
		if (type == nullptr || brand == nullptr || model == nullptr || year < 1990 || code < 100 || code > 999 || price <= 0)
		{
			resetInfo();
		}
		else
		{
			m_type = new char[strlen(type) + 1];
			strcpy(m_type, type);
			m_brand = new char[strlen(brand) + 1];
			strcpy(m_brand, brand);
			m_model = new char[strlen(model) + 1];
			strcpy(m_model, model);
			m_year = year;
			m_code = code;
			m_price = price;
		}
	}

	Car::~Car() {
		delete[] m_type;
		delete[] m_brand;
		delete[] m_model;
		m_type = nullptr;
		m_brand = nullptr;
		m_model = nullptr;
	}

	Car& Car::setInfo(const char* type,
		const char* brand,
		const char* model,
		int year,
		int code,
		double price) {
		this->resetInfo();
		if (type == nullptr || brand == nullptr || model == nullptr || year < 1990 || code < 100 || code > 999 || price <= 0)
		{
			// illegal value(s)!
			// this is already null
		}
		else
		{
			m_type = new char[strlen(type) + 1];
			strcpy(m_type, type);
			m_brand = new char[strlen(brand) + 1];
			strcpy(m_brand, brand);
			m_model = new char[strlen(model) + 1];
			strcpy(m_model, model);
			m_year = year;
			m_code = code;
			m_price = price;
		}
		return *this;
	}

	void Car::printInfo() const {
		if (isValid()) {
			cout << "| " << setw(10) << left << m_type << " | " << setw(16) << left << m_brand << " | " << setw(16) << left << m_model << " | " << setw(4) << m_year << " | " << setw(4) << right << m_code << " | " << setw(9) << right << fixed << setprecision(2) << m_price << " |" << endl;
		}
		return;
	}

	bool Car::isValid() const {
		bool returnValue = true;
		if (m_type == nullptr || m_brand == nullptr || m_model == nullptr || m_year < 1990 || m_code < 100 || m_code > 999 || m_price <= 0)
		{
			returnValue = false;
		}
		return returnValue;
	}

	bool Car::isSimilarTo(const Car& car) const {
		bool returnValue = false;
		if (m_type == car.m_type && m_brand == car.m_brand && m_model == car.m_model && m_year == car.m_year) {
			returnValue = true;
		}
		return returnValue;
	}

	//////////////////////////////
	// GLOBAL FUNCTION DEFINITIONS 
	//////////////////////////////
	bool has_similar(const Car car[], const int num_cars) {
		bool returnValue = false;
		for (int i = 0; i < num_cars; i++) {
			for (int j = i + 1; j < num_cars; j++) {
				if (car[i].isSimilarTo(car[j])) {
					returnValue = true;
				}
			}
		}
		return returnValue;
	}

	bool has_invalid(const Car car[], const int num_cars) {
		bool returnValue = false;
		int invalidCounter = 0;
		for (int i = 0; i < num_cars; i++) {
			if (!car[i].isValid()) {
				invalidCounter++;
			}
		}
		if (invalidCounter != 0)
		{
			returnValue = true;
		}
		return returnValue;
	}

	void print(const Car car[], const int num_cars) {
		for (int i = 0; i < num_cars; i++) {
			car[i].printInfo();
		}
		return;
	}
}
