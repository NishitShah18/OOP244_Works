/*************************************************************************
Workshop 3 Part 1
Full Name   : Nishit Gaurang Shah
Student ID# : 130 176 217
Email       : ngshah3@myseneca.ca
Section     : OOP244NFF

Date : 3rd June 2022

Autheticity Declaraition :
I declare that I have done all the coding by myself and only copied the
code that my professor provided to complete my workshops and assignments.

*************************************************************************/

#ifndef SDDS_ARMY_H
#define SDDS_ARMY_H


namespace sdds {
    //////////////////////////
    // CLASS(ES) 
    //////////////////////////
    class Army {
    public:
        static const int MAX_NAME_LEN = 50;
    private:
        char nationality[MAX_NAME_LEN + 1];
        int unitsCount;
        double power;
    public:
        /////////////////////////////
        // CLASS FUNCTION PROTOTYPES 
        /////////////////////////////
        void setEmpty();
        void createArmy(const char* country, double pow, int troops);
        void updateUnits(int troops);
        const char* checkNationality() const;
        int checkCapacity() const;
        double checkPower() const;
        bool isEmpty() const;
        bool isStrongerThan(const Army& army)const;
    };

    //////////////////////////
    // FUNCTION PROTOTYPES 
    //////////////////////////
    void battle(Army& arm1, Army& arm2);
    void displayDetails(const Army* armies, int size);
}
#endif //!SDDS_ARMY_H