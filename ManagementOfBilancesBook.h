#ifndef MANAGEMENTOFBILANCESBOOK_H
#define MANAGEMENTOFBILANCESBOOK_H

#include <iostream>
#include "UserManager.h"
#include "BilanceManager.h"

using namespace std;

class ManagementOfBilancesBook
{
    UserManager userManager;
    const string NAME_OF_THE_FILE_WITH_INCOMES;
    const string NAME_OF_THE_FILE_WITH_EXPENSES;
    BilanceManager *bilanceManager;

public:
    ManagementOfBilancesBook(string nameOfTheFileWithUsers, string nameOfTheFileWithIncomes, string nameOfTheFileWithExpenses)
    : userManager(nameOfTheFileWithUsers), NAME_OF_THE_FILE_WITH_INCOMES(nameOfTheFileWithIncomes),  NAME_OF_THE_FILE_WITH_EXPENSES(nameOfTheFileWithExpenses)
    {
        bilanceManager = NULL;
    };

    ~ManagementOfBilancesBook()
    {
        delete bilanceManager;
        bilanceManager = NULL;
    };
    void userRegistration();
    void userLogging();
    void showAllUsers();
    void logOffTheUser();
    char choseTheOptionFromMainMenu();
    bool isTheUserLogged();
    bool isTheVectorOfUsersEmpty();
    char choseTheOptionFromTheUserMenu();
    void addIncome();
    void showAllIncomes();
    void addExpense();
    void showTheBilanceFromThisMonth();
    void showTheBilanceFromPreviousMonth();
    void showTheBilanceFromPeroid();

};

#endif
