#ifndef FILEWITHINCOMES_H
#define FILEWITHINCOMES_H

#include <iostream>
#include <vector>

#include "Income.h"
#include "AuxiliaryMethods.h"
#include "XmlFile.h"
#include "Markup.h"
#include "DateManager.h"

using namespace std;

class FileWithIncomes : public XmlFile
{

    int idOfLastOperaction;

public:
    FileWithIncomes(string nameOfFileWithIncomes) : XmlFile(nameOfFileWithIncomes) {
    idOfLastOperaction = 0;
    };
    bool addIncomeToFile(Income income);
    vector <Income> loadTheIncomesOfLoggedUser(int idOfLoggedUser);
    int getIdOfLastOperaction();
};

#endif
