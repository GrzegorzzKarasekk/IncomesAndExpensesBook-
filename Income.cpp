#include "Income.h"

void Income::setNameOfIncome(string newNameOfIncome)
{
    nameOfIncome = newNameOfIncome;
}
string Income::getNameOfIncome()
{
   return nameOfIncome;
}

bool operator<(Income &d1, Income &d2)
{
    return d1.getDate() < d2.getDate();
}
