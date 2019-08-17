#ifndef MANAGEMENTOFBILANCESBOOK_H
#define MANAGEMENTOFBILANCESBOOK_H

#include <iostream>
#include "UserManager.h"
#include "BilanceManager.h"

using namespace std;

class ManagementOfBilancesBook
{
    UserManager userManager;
    //const string NAME_OF_THE_FILE_WITH_USERS;
    BilanceManager *bilanceManager;

public:
    ManagementOfBilancesBook(string nameOfTheFileWithUsers)
    : userManager(nameOfTheFileWithUsers)
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

};

#endif
