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

// SAFE-GUARD
#ifndef SDDS_CAR_H
#define SDDS_CAR_H

namespace sdds {
	//////////////////////////
	// CLASS(ES) 
	//////////////////////////
	class Car {
	private:
		char* m_type;
		char* m_brand;
		char* m_model;
		int m_year;
		int m_code;
		double m_price;
		//////////////////////////////////////
		// CLASS PRIVATE FUNCTION PROTOTYPE(S) 
		//////////////////////////////////////
		void resetInfo();
	public:
		///////////////////////////////////
		// CLASS PUBLIC FUNCTION PROTOTYPES 
		///////////////////////////////////
		Car();
		Car(const char* type, const char* brand, const char* model);
		Car(const char* type, const char* brand, const char* model, int year, int code, double price);
		~Car();
		Car& setInfo(const char* type,
			const char* brand,
			const char* model,
			int year,
			int code,
			double price);
		void printInfo() const;
		bool isValid() const;
		bool isSimilarTo(const Car& car) const;
	};

	/////////////////////////////
	// GLOBAL FUNCTION PROTOTYPES 
	/////////////////////////////
	bool has_similar(const Car car[], const int num_cars);
	bool has_invalid(const Car car[], const int num_cars);
	void print(const Car car[], const int num_cars);
}

#endif // !SDDS_CAR_H
