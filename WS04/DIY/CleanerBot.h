/*************************************************************************
Workshop 4 Part 2
Full Name   : Nishit Gaurang Shah
Student ID# : 130 176 217
Email       : ngshah3@myseneca.ca
Section     : OOP244NFF
Date : 11th June 2022
Autheticity Declaraition :
I declare that I have done all the coding by myself and only copied the
code that my professor provided to complete my workshops and assignments.
*************************************************************************/

#ifndef SDDS_CLEANERBOT_H
#define SDDS_CLEANERBOT_H

#include <iostream>
#include <cstring>
#include <iomanip>

namespace sdds {

	class CleanerBot {
		char* m_location;
		double m_battery;
		int m_brush;
		bool m_active;

	public:
		CleanerBot();
		CleanerBot(const char* location, const double battery,
			const int brush, const bool active);
		~CleanerBot();
		CleanerBot& set(const char* location, const double battery,
			const int brush, const bool active);
		CleanerBot setLocation(const char* location);
		void setActive(const bool active);
		char* getLocation() const;
		double getBettery() const;
		int getBrush() const;
		bool isActive() const;
		bool isValid() const;
		void display();
	};
	int report(CleanerBot* bot, short num_bots);
}


#endif // !SDDS_CLEANERBOT_H
