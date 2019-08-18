#ifndef BILANCEMANAGER_H
#define BILANCEMANAGER_H

#include <iostream>
#include <vector>
#include <conio.h>
#include <sstream>

#include "Income.h"
#include "AuxiliaryMethods.h"
#include "DateManager.h"
#include "FileWithIncomes.h"

using namespace std;

class BilanceManager
{
    int const ID_OF_LOGGED_USER;
    vector <Income> incomes;
    FileWithIncomes fileWithIncomes;

	Income addDataNewIncome();

public:
    BilanceManager(string nameOfFileWithIncomes, int idOfLoggedUser )
    : fileWithIncomes(nameOfFileWithIncomes), ID_OF_LOGGED_USER(idOfLoggedUser)
    {
        incomes = fileWithIncomes.loadTheIncomesOfLoggedUser(ID_OF_LOGGED_USER);
    }
    void addIncome();
	void showAllIncomes();

};

#endif
