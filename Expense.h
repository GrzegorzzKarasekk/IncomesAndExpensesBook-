#ifndef EXPENSE_H
#define EXPENSE_H

#include <iostream>
#include "UserOperaction.h"
using namespace std;

class Expense: public UserOperaction
{
    string nameOfExpense;

public:
    Expense(string nameOfExpense = "")
    {
        this -> nameOfExpense = nameOfExpense;
    }

    void setNameOfExpense(string newNameOfExpense);

    string getNameOfExpense();
};

#endif
