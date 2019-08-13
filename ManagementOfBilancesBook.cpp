#include "ManagementOfBilancesBook.h"

void ManagementOfBilancesBook::userRegistration()
{
    userManager.userRegistration();
}

void ManagementOfBilancesBook::userLogging()
{
    userManager.userLogging();
    if( userManager.isTheUserLogged())
    {
        ;
    }
}

void ManagementOfBilancesBook::showAllUsers()
{
    userManager.showAllUsers();
}

char ManagementOfBilancesBook::choseTheOptionFromMainMenu()
{
    char choise;

    system("cls");
    cout << "    >>> MAIN MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. REGISTRATION" << endl;
    cout << "2. LOGGING" << endl;
    cout << "9. EXIT" << endl;
    cout << "---------------------------" << endl;
    cout << "YOUR CHOICE: ";
    choise = AuxiliaryMethods::loadTheSign();

    return choise;
}

bool ManagementOfBilancesBook::isTheUserLogged()
{
    return userManager.isTheUserLogged();
}

bool ManagementOfBilancesBook::isTheVectorOfUsersEmpty()
{
    return userManager.isTheVectorOfUsersEmpty();
}

char ManagementOfBilancesBook::choseTheOptionFromTheUserMenu()
{
    return userManager.choseTheOptionFromTheUserMenu();
}

void ManagementOfBilancesBook::logOffTheUser()
{
    userManager.logOffTheUser();
}
