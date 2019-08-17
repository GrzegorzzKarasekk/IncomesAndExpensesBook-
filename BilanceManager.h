#ifndef BILANCEMANAGER_H
#define BILANCEMANAGER_H

#include <iostream>
#include <vector>
#include <conio.h>
//#include <windows.h>
#include <sstream>

#include "Income.h"
#include "AuxiliaryMethods.h"
#include "DateManager.h"
//#include "FileWithIncomes.h"

using namespace std;

class BilanceManager
{
    int const ID_OF_LOGGED_USER;
    vector <Income> incomes;
    //FileWithIncomes fileWithIncomes;

	Income addDataNewIncome();

public:
    BilanceManager(int idOfLoggedUser) : ID_OF_LOGGED_USER(idOfLoggedUser)
    {
        ;
    }
    void addIncome();
	void showIncomes();

};

#endif
