#ifndef EXPENSE_H
#define EXPENSE_H

#include <iostream>
#include "UserOperaction.h"
using namespace std;

class Expense: public UserOperaction
{
    UserOperaction userOperaction;
    string nameOfExpense;

public:
    Expense(string nNameOfExpense = "", int nUserId = 0, int nOperactionId = 0,int nDate = 0, float nAmount = 0.0):
         UserOperaction(nUserId, nOperactionId, nDate, nAmount), nameOfExpense(nNameOfExpense)
         {
             this -> nameOfExpense = nNameOfExpense;
         }

    void setNameOfExpense(string newNameOfExpense);

    string getNameOfExpense();
};

bool operator<(Expense &d1, Expense &d2);

#endif
