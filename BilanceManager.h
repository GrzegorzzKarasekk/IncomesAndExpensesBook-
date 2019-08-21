#ifndef BILANCEMANAGER_H
#define BILANCEMANAGER_H

#include <iostream>
#include <vector>
#include <conio.h>
#include <sstream>
#include <algorithm>//sort

#include "Income.h"
#include "Expense.h"
#include "AuxiliaryMethods.h"
#include "DateManager.h"
#include "FileWithIncomes.h"
#include "FileWithExpenses.h"


using namespace std;

class BilanceManager
{
    int const ID_OF_LOGGED_USER;
    vector <Income> incomes;
    vector <Expense> expenses;
    FileWithIncomes fileWithIncomes;
    FileWithExpenses fileWithExpenses;
	Income addDataNewIncome();
    Expense addDataNewExpense();

    void showAllIncomes();
	void showAllExpenses();
    vector <Income> selectingIncomesFromCurrentlyMonth(vector <Income> incomes, int currentlyDate);
    vector <Expense> selectingExpensesFromCurrentlyMonth(vector <Expense> expenses, int currentlyDate);

public:
    BilanceManager(string nameOfFileWithIncomes, string nameOfFileWithExpenses, int idOfLoggedUser )
    : fileWithIncomes(nameOfFileWithIncomes),fileWithExpenses(nameOfFileWithExpenses), ID_OF_LOGGED_USER(idOfLoggedUser)
    {
        incomes = fileWithIncomes.loadTheIncomesOfLoggedUser(ID_OF_LOGGED_USER);
        expenses = fileWithExpenses.loadTheExpensesOfLoggedUser(ID_OF_LOGGED_USER);
    }
    void addIncome();
    void addExpense();
    void showTheBilanceFromThisMonth();
};

#endif
