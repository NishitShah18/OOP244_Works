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

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string.h>
#include"File.h"
#include"Student.h"

using namespace std;

namespace sdds {

    //////////////////////////
    // GLOBAL VARIABLES 
    //////////////////////////
    int noOfStudents = 0;
    struct Student* students = nullptr;

    //////////////////////////
    // FUNCTION DEFINITIONS 
    //////////////////////////
    void sort() {
        int i, j;
        Student temp;
        for (i = noOfStudents - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (students[j].m_grade > students[j + 1].m_grade) {
                    temp = students[j];
                    students[j] = students[j + 1];
                    students[j + 1] = temp;
                }
            }
        }
    }

    bool load(Student& student)
    {
        int returnValue = 0;
        char localString[LOCAL_ARRAY_SIZE + 1] = "\0";

        if (read(localString))
        {
            student.m_name = new char[(strlen(localString) + 1)];
            strcpy(student.m_name, localString);

            if (read(student.m_studentNumber) && read(student.m_grade))
            {
                returnValue = 1;
            }

        }

        return returnValue;
    }

    bool load(const char* filename)
    {
        int loadCounter = 0;
        int returnValue = 0;

        openFile(filename);

        noOfStudents = noOfRecords();
        students = new Student[noOfStudents];

        for (int i = 0; i < noOfStudents; i++) 
        {
            if (load(students[i]))
            {
                loadCounter++;
            }
        }

        if (loadCounter == noOfStudents)
        {
            returnValue = 1;
        }
        else
        {
            cout << "Error: incorrect number of records read; the data is possibly corrupted." << endl;
        }

        return returnValue;
    }

    void display(const Student& student)
    {
        cout << student.m_name << ", " << student.m_studentNumber << ": " << student.m_grade << endl;
    }

    void display()
    {
        sort();

        for (int i = 0; i < noOfStudents; i++)
        {
            cout << (i + 1) << ": ";
            display(students[i]);
        }

        return;
    }

    void deallocateMemory()
    {
        for (int i = 0; i < noOfStudents; i++)
        {
            delete[] students[i].m_name;
        }
        delete[] students;

        return;
    }
}