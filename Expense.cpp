#include "Expense.h"

void Expense::setNameOfExpense(string newNameOfExpense)
{
    nameOfExpense = newNameOfExpense;
}
string Expense::getNameOfExpense()
{
   return nameOfExpense;
}

bool operator<(Expense &d1, Expense &d2)
{
    return d1.getDate() < d2.getDate();
}


