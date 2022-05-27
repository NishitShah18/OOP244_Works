/*************************************************************************
Workshop 2 Part 1
Full Name   : Nishit Gaurang Shah
Student ID# : 130 176 217
Email       : ngshah3@myseneca.ca
Section     : OOP244NFF

Date : 27th May 2022

Autheticity Declaraition :
I declare that I have done all the coding by myself and only copied the
code that my professor provided to complete my workshops and assignments.

*************************************************************************/

// SAFE-GAURD
#ifndef SDDS_STUDENTS_H
#define SDDS_STUDENTS_H

namespace sdds {

    //////////////////////////
    // CONSTANT VARIABLE(S) 
    //////////////////////////
    const int LOCAL_ARRAY_SIZE = 128;

    //////////////////////////
    // STRUCTURE(S) 
    //////////////////////////
    struct Student {
        char* m_name;
        int m_studentNumber;
        char m_grade;
    };

    //////////////////////////
    // FUNCTION PROTOTYPES 
    //////////////////////////
    void sort();

    bool load(Student& student);
    bool load(const char* filename);

    void display(const Student& student);
    void display();

    void deallocateMemory();
}

#endif // !SDDS_STUDENTS_H