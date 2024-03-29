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
    vector <Income> selectingIncomesFromVector(vector <Income> incomes, int currentDate, char choice, int beginningOfThePeriod, int endOfPeriod);
    vector <Expense> selectingExpensesFromVector(vector <Expense> expenses, int currentDate, char choice, int beginningOfThePeriod, int endOfPeriod);
    char chooseTheOptionFromTheEditMenu();
    int setIdOfEditedOperaction();
    void showTheIncome(Income income);
    void showTheExpense(Expense expense);
    char selectAnOptionFromTheEditMenu();
    bool changeTheIncomeOperaction(int idOffEditedOperaction, int currentINTDate, bool isTheOprectionExist);
    bool changeTheExpenseOperaction(int idOffEditedOperaction, int currentINTDate, bool isTheOprectionExist);

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
    void showTheBilanceFromPreviousMonth();
    void showTheBilanceFromPeroid();
    void editTheOperaction();
};

#endif
