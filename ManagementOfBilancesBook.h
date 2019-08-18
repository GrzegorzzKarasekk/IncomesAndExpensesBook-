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
    BilanceManager *bilanceManager;

public:
    ManagementOfBilancesBook(string nameOfTheFileWithUsers, string nameOfTheFileWithIncomes)
    : userManager(nameOfTheFileWithUsers), NAME_OF_THE_FILE_WITH_INCOMES(nameOfTheFileWithIncomes)
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

};

#endif
