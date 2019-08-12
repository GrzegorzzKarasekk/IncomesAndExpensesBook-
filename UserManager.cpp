#include "UserManager.h"

void UserManager::userRegistration()
{
    User user = setDataNewUser();
    users.push_back(user);
    fileWithUsers.addUserOnToFile(user);

    cout << endl << "Account has been successfully created " << endl << endl;
    system("pause");
}

User UserManager::setDataNewUser()
{
    User user;

    user.setUserId(getIdNewUser());
    string login;
    do
    {
        cout << "SET LOGIN: ";
        login = AuxiliaryMethods::loadTheLine();
        user.setLogin(login);

    } while (isTheLoginExist(user.getLogin()) == true || isTheFieldEmpty(login) == true);

    string password;
    do
    {
        cout << "SET PASSWORD: ";
        password = AuxiliaryMethods::loadTheLine();
        user.setPassword(password);
    } while (isTheFieldEmpty(password) == true || isThisSamePassword(password) == false);

    string name;
    do
    {
        cout << "GIVE YOUR NAME: ";
        name = AuxiliaryMethods::loadTheLine();
        name = AuxiliaryMethods::changeTheFirstLetterToCapitalAndTheRestToLower(name);
        user.setName(name);
    } while (isTheFieldEmpty(name) == true);

    string surname;
    do
    {
        cout << "GIVE YOUR SURNAME: ";
        surname = AuxiliaryMethods::loadTheLine();
        surname = AuxiliaryMethods::changeTheFirstLetterToCapitalAndTheRestToLower(surname);
        user.setSurname(surname);
    } while (isTheFieldEmpty(surname) == true);

    return user;
}

int UserManager::getIdNewUser()
{
    if (users.empty() == true)
        return 1;
    else
        return users.back().getUserId() + 1;
}

bool UserManager::isTheLoginExist(string login)
{
    for (int i = 0; i < users.size(); i++)
    {
        if(users[i].getLogin() == login)
        {
            cout << endl << "There's a account with this login" << endl;
            return true;
        }
    }
    return false;
}

bool UserManager::isTheFieldEmpty(string field)
{
    if(field == "")
        {
            cout << endl << "This field is empty!!!" << endl;
            return true;
        }
    return false;
}

bool UserManager::isThisSamePassword(string password)
{
    string password2 = "";
    cout << "RAPEAT THE PASSWORD: ";

    password2 = AuxiliaryMethods::loadTheLine();

    if(password != password2)
        {
            cout << endl << "Passwords are different!!!" << endl;
            return false;
        }
    else
        return true;
}

