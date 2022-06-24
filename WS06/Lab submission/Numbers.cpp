/*************************************************************************
Workshop 5 Part 1
Full Name   : Nishit Gaurang Shah
Student ID# : 130 176 217
Email       : ngshah3@myseneca.ca
Section     : OOP244NFF

Date : 24th June 2022

Autheticity Declaraition :
I declare that I have done all the coding by myself and only copied the
code that my professor provided to complete my workshops and assignments.

*************************************************************************/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>

#include "Numbers.h"
#include "Numbers.h"  // intentional
using namespace std;
namespace sdds {

    Numbers::Numbers() {
        setEmpty();
        m_isOriginal = false;
    }

    Numbers::Numbers(const char* filename) {
        setEmpty();
        m_isOriginal = true;
        setFilename(filename);
        m_numCount = numberCount();
        if (m_numCount == 0 || !load()) {
            delete[] m_numbers;
            delete[] m_filename;
            setEmpty();
            m_isOriginal = false;
        }
        else {
            sort();
        }
    }

    //(implemented by ngshah3)
    Numbers::Numbers(const Numbers& n) {
        //Sets the object to safe empty state
        setEmpty();
        //Sets the object NOT to be original
        m_isOriginal = false;
        //Assigns the current object to the Numbers object that is being copied. (calls the Copy Assignment Operator)
        operator= (n);
    }

    Numbers::~Numbers() {
        save();
        delete[] m_numbers;
        delete[] m_filename;
    }

    //(implemented by ngshah3)
    Numbers& Numbers::operator= (const Numbers& n) {
        //deletes the current collection of the double values
        delete[] m_numbers;
        m_numCount = n.m_numCount;
        //Allocates new memory pointed by m_numbers to the number of the values in the object that is being copied.
        m_numbers = new double[m_numCount];
        //Copies all the double values in the object that is being copied into the newly allocated memory.
        for (int i = 0; i < m_numCount; i++) {
            m_numbers[i] = n.m_numbers[i];
        }
        //returns the reference of the current object.
        return *this;
    }

    bool Numbers::isEmpty() const {
        return m_numbers == nullptr;
    }

    void Numbers::setEmpty() {
        m_numbers = nullptr;
        m_filename = nullptr;
        m_numCount = 0;
    }

    void Numbers::setFilename(const char* filename) {
        delete[] m_filename;
        m_filename = new char[strlen(filename) + 1];
        strcpy(m_filename, filename);
    }

    void Numbers::sort() {
        int i, j;
        double temp;
        for (i = m_numCount - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (m_numbers[j] > m_numbers[j + 1]) {
                    temp = m_numbers[j];
                    m_numbers[j] = m_numbers[j + 1];
                    m_numbers[j + 1] = temp;
                }
            }
        }
    }

    double Numbers::average() const {
        double aver = 0.0;
        if (!isEmpty()) {
            for (int i = 0; i < m_numCount; i++)
                aver += m_numbers[i];
            aver = aver / m_numCount;
        }
        return aver;
    }

    double Numbers::max() const {
        double maxVal = 0.0;
        if (!isEmpty()) {
            maxVal = m_numbers[0];
            for (int i = 1; i < m_numCount; i++)
                if (maxVal < m_numbers[i]) maxVal = m_numbers[i];
        }
        return maxVal;
    }

    double Numbers::min() const {
        double minVal = 0.0;
        if (!isEmpty()) {
            minVal = m_numbers[0];
            for (int i = 1; i < m_numCount; i++)
                if (minVal > m_numbers[i]) minVal = m_numbers[i];
        }
        return minVal;
    }

    //(implemented by ngshah3)
    int Numbers::numberCount() const
    {
        int counter = 0;
        char ch = '\0';

        //Create an instance of ifstream to open the data file name.
        ifstream fileinst(m_filename);
        
        //While the ifstream object has not failed keep reading single characters from the file
        while (fileinst.get(ch))
        {
            if (ch == '\n') { counter++; }
        }

        return counter;
    }

    //(implemented by ngshah3)
    bool Numbers::load()
    {
        int readCounter = 0;
        bool returnValue = false;
        if (m_numCount > 0)
        {
            //Allocate memory to hold the double values in an array pointed by m_numbers.
            m_numbers = new double[(m_numCount)];
            //Create an instance of ifstream for the data file
            ifstream fileinst(m_filename);
            //While the ifstream object has not failed, keep reading double values from the file into the elements of m_numbers dynamic array (as you do with cin)
            while (readCounter < m_numCount && !fileinst.fail())
            {
                    fileinst >> m_numbers[readCounter];
                    readCounter++;
            }
        }
        //return true if the number of read doubles, is equal to the m_numCount member variable.
        if (readCounter == m_numCount)
        {
            returnValue = true;
        }
        return returnValue;
    }

    //(implemented by ngshah3)
    void Numbers::save()
    {
        //If the current object is the original and it is not in safe empty state
        if (m_isOriginal == true && !isEmpty())
        {
            //Create an instance of ofstream to overwrite the datafile
            ofstream fileinst(m_filename, ios::trunc);
            
            for (int i = 0; i < m_numCount; i++)
            {
                //Write all the elements of the m_numbers array using the ofstream object.
                //Write a newline after each double value.
                fileinst << m_numbers[i] << endl;
            }
        }
    }

    //(implemented by ngshah3)
    Numbers& Numbers::operator+=(const double& num)
    {
        //if the object is not in an empty state
        if (!isEmpty())
        {
            //Create a temp double pointer and allocate memory to the size: m_numCount + 1
            double* arr = nullptr;
            arr = new double[m_numCount + 1];

            //In a loop, copy all the double m_numbers elements to the double temp number elements(up to m_numCount)
            for (int i = 0; i <= m_numCount; i++)
            {
                //Add one to m_numCount (to update the number of double values)
                if (i == m_numCount)
                {
                    arr[i] = num;
                }
                else arr[i] = m_numbers[i];
            }
            //delete m_numbers to get rid of the original allocated memory
            delete[] m_numbers;
            //Set m_numbers to temp pointer; by doing this m_numbers will point to the newly allocated memory.
            m_numbers = arr;
            m_numCount += 1;
            //Set m_numbers to temp pointer; by doing this m_numbers will point to the newly allocated memory.
            sort();
        }
        //Regardless of the object being empty or not return the reference of the current object.
        return *this;
    }
   
    //(implemented by ngshah3)
    ostream& Numbers::display(ostream& ostr) const
    {
        //if the object is empty, write: "Empty list".
        if (isEmpty())
        {
            cout << "Empty list";
        }
        else
        {
            //if the object is not empty start by writing: "=========================" on ostr and then go to newline
            ostr << "=========================" << endl;
            //if the object is flagged as original, then write the file name 
            if (m_isOriginal)
            {
                ostr << m_filename << endl;
            }
            //otherwise write "*** COPY ***" and then go to new line
            else
            {
                ostr << "*** COPY ***" << endl;
            }
            //write all the double numbers seperated by ", " (A comma and a space) and then go to new line
            for (int i = 0; i < m_numCount; i++)
            {
                if (i == m_numCount - 1)
                {
                    ostr << m_numbers[i] << endl;
                }
                else ostr << m_numbers[i] << ", ";
            }
            //write "-------------------------" and go to new line
            ostr << "-------------------------" << endl;
            //Write "Total of " << m_numCount << " number(s)" and go to new line
            ostr << "Total of " << m_numCount << " number(s)" << endl;
            //write "Largest number: " and the largest number in the list and go to new line
            ostr << "Largest number:  " << max() << endl;
            //write "Smallest number: " and the smallest number in the list and go to new line
            ostr << "Smallest number: " << min() << endl;
            //write "Average : " and the average of all the numbers inthe list and go to new line
            ostr << "Average :        " << average() << endl;
            //write "=========================" and DO NOT GO TO NEWLINE
            ostr << "=========================";
        }
        //At the end return the ostr object.
        return ostr;
    }

    //(implemented by ngshah3)
    ostream& operator<<(ostream& os, const Numbers& N)
    {
        //ostream& operator<<(ostream& os, const Numbers& N);
        return N.display(os);
    }

    //(implemented by ngshah3)
    istream& operator>>(istream& istr, Numbers& N)
    {
        double read = 0.00;
        //read a double value using istr
        istr >> read;
        //add the double value to N using += operator
        N += read;
        //return istr;
        return istr;
    }
}
