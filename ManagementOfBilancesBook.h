#ifndef MANAGEMENTOFBILANCESBOOK_H
#define MANAGEMENTOFBILANCESBOOK_H

#include <iostream>
#include "UserManager.h"
#include "Markup.h"


using namespace std;

class ManagementOfBilancesBook
{
    UserManager userManager;
    //const string NAME_OF_THE_FILE_WITH_USERS;


public:
    ManagementOfBilancesBook(string nameOfTheFileWithUsers)
    : userManager(nameOfTheFileWithUsers){};
    ~ManagementOfBilancesBook()
    {};
    void userRegistration();
    void userLogging();
    void showAllUsers();
    void logOffTheUser();
    char choseTheOptionFromMainMenu();
    bool isTheUserLogged();
    bool isTheVectorOfUsersEmpty();
    char choseTheOptionFromTheUserMenu();

};

#endif
