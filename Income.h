#ifndef INCOME_H
#define INCOME_H

#include <iostream>
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
};

#endif
