#ifndef INCOME_H
#define INCOME_H

#include <iostream>
#include "UserOperaction.h"

using namespace std;

class Income : public UserOperaction
{
    string nameOfIncome;

public:
    Income(string nNameOfIncome = "", int nUserId = 0, int nOperactionId = 0,int nDate = 0, float nAmount = 0.0):
         UserOperaction(nUserId, nOperactionId, nDate, nAmount), nameOfIncome(nNameOfIncome)
         {
             this -> nameOfIncome = nNameOfIncome;
         }

    void setNameOfIncome(string newNameOfIncome);

    string getNameOfIncome();
};

bool operator<(Income &d1, Income &d2);

#endif

