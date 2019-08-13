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

void UserManager::userLogging()
{
    string login = "", password = "";
    cout << endl << "Enter the login: ";
    login = AuxiliaryMethods::loadTheLine();

    for(int i = 0; i < users.size(); i++)
    {
        if(users[i].getLogin() == login)
        {
            for (int iloscProb = 3; iloscProb > 0; iloscProb --)
            {
                cout << "Enter the password. You have " << iloscProb << " attempts: ";
                password = AuxiliaryMethods::loadTheLine();

                if (users[i].getPassword() == password)
                {
                    idOfLoggedUser = users[i].getUserId();
                    cout << endl << "You are log in." << endl <<endl;
                    system("pause");
                    return;
                }
            }
            cout << "Wrong password entered 3 times" << endl;
            system("pause");
            return;
        }
    }
    cout << "Bad login or missing user" << endl;
    system("pause");
    return;
}

void UserManager::showAllUsers()
{
    for (int i = 0; i < users.size(); i++)
    {
        cout << users[i].getUserId() << endl;
        cout << users[i].getLogin() << endl;
        cout << users[i].getPassword() << endl;
        cout << users[i].getName() << endl;
        cout << users[i].getSurname() << endl;
    }
}

void UserManager::logOffTheUser()
{
    idOfLoggedUser = 0;
}

bool UserManager::isTheUserLogged()
{
    if (idOfLoggedUser > 0)
        return true;
    else
        return false;
}

bool UserManager::isTheVectorOfUsersEmpty()
{
    if(users.empty() == true)
        {
            cout << "NO USERS :(" << endl;
            system("pause");
            return true;
        }
    else
        return false;
}

char UserManager::choseTheOptionFromTheUserMenu()
{
    char choice;

    system("cls");
    cout << " >>> USER MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. ADD INCOME" << endl;
    cout << "2. ADD EXPENSE" << endl;
    cout << "3. SHOW THE BILANCE FROM THIS MONTH" << endl;
    cout << "4. SHOW THE BILANCE FROM PREVIOUS MONTH" << endl;
    cout << "5. SHOW THE BILANCE FROM PEROID" << endl;
    cout << "6. EDIT THE INCOME" << endl;
    cout << "7. EDIT THE EXPENSE" << endl;
    cout << "---------------------------" << endl;
    cout << "8. CHANGE THE PASSWORD" << endl;
    cout << "9. LOG OFF" << endl;
    cout << "---------------------------" << endl;
    cout << "YOUR CHOICE: ";
    choice = AuxiliaryMethods::loadTheSign();

    return choice;
}

