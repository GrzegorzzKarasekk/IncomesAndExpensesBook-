#ifndef INCOME_H
#define INCOME_H

#include <iostream>
//#include <tuple>//tie

#include "UserOperaction.h"

using namespace std;

class Income : public UserOperaction
{
    string nameOfIncome;

public:
    Income(string nameOfIncome = "")
    {
        this -> nameOfIncome = nameOfIncome;
    }

    void setNameOfIncome(string newNameOfIncome);

    string getNameOfIncome();
    //friend bool operator<(const Income &s1, const Income &s2);
};

#endif
