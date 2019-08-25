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

    int idOfLastExpenseOperaction;

public:
    FileWithExpenses(string nameOfFileWithExpenses) : XmlFile(nameOfFileWithExpenses) {
    idOfLastExpenseOperaction = 0;
    };
    bool addExpenseToFile(Expense expense);
    vector <Expense> loadTheExpensesOfLoggedUser(int idOfLoggedUser);
    int getIdOfLastExpenseOperaction();
};

#endif
