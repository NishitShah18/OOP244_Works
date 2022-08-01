/*
Final Project Milestone 4
Module      : Book
Filename    : Book.h
Version 1.0

Author	    : Nishit Gaurang Shah
Student ID# : 130 176 217
Email       : ngshah3@myseneca.ca
Section     : OOP244NFF

Date : 1st August 2022

Autheticity Declaraition :
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Book.h"
#include "Utils.h"
#include <iomanip>
using namespace std;
namespace sdds {
	Book::Book() : Publication()
	{
		m_authorName = nullptr;
	}
	Book::Book(const Book& src) 
	{
		operator=(src);
	}
	Book& Book::operator=(const Book& src) 
	{
		if (this != &src && src) { 
			Publication::operator=(src);
			Utils::copyStr(m_authorName, src.m_authorName);
		}
		return *this;
	}
	Book::~Book() 
	{
		delete[] m_authorName;
		m_authorName = nullptr;
	}
	void Book::set(int member_id) 
	{
		Publication::set(member_id);
		Publication::resetDate();
	}
	char Book::type()const 
	{
		return 'B';
	}
	void Book::deleteAll() 
	{
		delete[] m_authorName;
		m_authorName = nullptr;
		Publication::deleteAll();
	}
	ostream& Book::write(ostream& ostr)const 
	{
		Publication::write(ostr);
		if (conIO(ostr)) {
			char author[SDDS_AUTHOR_WIDTH + 1] = { 0 };
			strncpy(author, m_authorName, SDDS_AUTHOR_WIDTH);
			ostr << " ";
			ostr << std::setw(SDDS_AUTHOR_WIDTH) << std::left << std::setfill(' ') << author << " |";
		}
		else {
			ostr << '\t' << m_authorName;
		}
		return ostr;
	}
	istream& Book::read(istream& istr) 
	{
		char author[256] = {0};
		deleteAll();
		Publication::read(istr);
		if (conIO(istr)) {
			Utils::getChar(istr, '\n');
			cout << "Author: ";
			istr.getline(author, 256);
		}
		else {
			Utils::getChar(istr, '\t');
			istr.get(author, 256);
		}
		if (!author) istr.setstate(ios::failbit);
		if (istr) {
			Utils::copyStr(m_authorName, author);
		}
		else {
			deleteAll();
		}
		return istr;
	}
	bool Book::conIO(std::ios& io)const 
	{
		return Publication::conIO(io);
	}
	Book::operator bool()const 
	{
		return (m_authorName && Publication::operator bool());
	}
}
