#include "Income.h"

void Income::setNameOfIncome(string newNameOfIncome)
{
    nameOfIncome = newNameOfIncome;
}
string Income::getNameOfIncome()
{
   return nameOfIncome;
}

/*bool Income:: operator<(const Income &s1)//, const Skyscraper &s2)
{
    return (s1.getDate() < this.getDate());
}

/*bool Income::operator>(const Income &a, const Income &b)
{
    int tempDate1 = a.getDate();
    int tempDate2 = b.getDate();

    if (tempDate1 < tempDate2) return true;
    if (tempDate1 > tempDate1) return false;

    //return tie(a.date) < tie(b.date);
}
*/
