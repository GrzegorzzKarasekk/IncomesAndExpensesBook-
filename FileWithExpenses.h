#ifndef FILEWITHEXPENSES_H
#define FILEWITHEXPENSES_H

#include <iostream>
#include <vector>

#include "Expense.h"
#include "AuxiliaryMethods.h"
#include "XmlFile.h"
#include "Markup.h"
#include "DateManager.h"

using namespace std;

class FileWithExpenses : public XmlFile
{

    int idOfLastOperaction;

public:
    FileWithExpenses(string nameOfFileWithExpenses) : XmlFile(nameOfFileWithExpenses) {
    idOfLastOperaction = 0;
    };
    bool addExpenseToFile(Expense expense);
    vector <Expense> loadTheExpensesOfLoggedUser(int idOfLoggedUser);
    int getIdOfLastOperaction();
};

#endif
