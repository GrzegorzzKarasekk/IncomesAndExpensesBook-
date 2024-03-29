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
       bilanceManager = new BilanceManager(NAME_OF_THE_FILE_WITH_INCOMES,NAME_OF_THE_FILE_WITH_EXPENSES, userManager.getIdOfLoggedUser());
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
    return userManager.chooseTheOptionFromTheUserMenu();
}

char ManagementOfBilancesBook::choseTheOptionFromTheEditMenu()
{
    bilanceManager->editTheOperaction();
}

void ManagementOfBilancesBook::logOffTheUser()
{
    userManager.logOffTheUser();
}

void ManagementOfBilancesBook::showTheBilanceFromThisMonth()
{
    bilanceManager->showTheBilanceFromThisMonth();
}

void ManagementOfBilancesBook::showTheBilanceFromPreviousMonth()
{
    bilanceManager->showTheBilanceFromPreviousMonth();
}

void ManagementOfBilancesBook::showTheBilanceFromPeroid()
{
    bilanceManager->showTheBilanceFromPeroid();
}

void ManagementOfBilancesBook::addIncome()
{
    if( userManager.isTheUserLogged())
    {
        bilanceManager->addIncome();
    }
    else
    {
        cout << "To add operaction you must log in ;) " << endl;
    }
}

void ManagementOfBilancesBook::addExpense()
{
    if( userManager.isTheUserLogged())
    {
        bilanceManager->addExpense();
    }
    else
    {
        cout << "To add operaction you must log in ;) " << endl;
    }
}

void ManagementOfBilancesBook::changeTheUserPassword()
{
    userManager.changeUserPassword();
}

