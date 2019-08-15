#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>

#include "User.h"
#include "AuxiliaryMethods.h"
#include "FileWithUsers.h"

using namespace std;

class UserManager
{
    int idOfLoggedUser;
    vector <User> users;
    FileWithUsers fileWithUsers;

    User setDataNewUser();
    int getIdNewUser();
    bool isTheFieldEmpty(string field);
    bool isTheLoginExist(string login);
    bool isThisSamePassword(string password);

public:
    UserManager(string nameOfTheFileWithUsers) : fileWithUsers(nameOfTheFileWithUsers){
    idOfLoggedUser = 0;
    users = fileWithUsers.loadUsersFromTheFile();
    }
    void userRegistration();
    void userLogging();
    void logOffTheUser();
    void showAllUsers();
    char choseTheOptionFromTheUserMenu();
    bool isTheUserLogged();
    bool isTheVectorOfUsersEmpty();

};

#endif
