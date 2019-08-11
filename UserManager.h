#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>

#include "User.h"
#include "AuxiliaryMethods.h"

using namespace std;

class UserManager
{
    int idOfLoggedUser;
    vector <User> users;

    User setDataNewUser();
    int getIdNewUser();
    bool isTheFieldEmpty(string field);
    bool isTheLoginExist(string login);
    bool isThisSamePassword(string password);

public:
    void userRegistration();

};

#endif
