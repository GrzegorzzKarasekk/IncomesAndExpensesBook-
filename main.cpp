#include <iostream>
#include "ManagementOfBilancesBook.h"

using namespace std;

int main()
{
    char choice;
    ManagementOfBilancesBook managementOfBilancesBook("Users.xml","Incomes.xml","Expenses.xml");

    while (true)
    {
        if (managementOfBilancesBook.isTheUserLogged() == false)
        {
            choice = managementOfBilancesBook.choseTheOptionFromMainMenu();

            switch (choice)
            {
            case '1':
                managementOfBilancesBook.userRegistration();
                managementOfBilancesBook.showAllUsers();
                system("pause");
                break;
            case '2':
                if (managementOfBilancesBook.isTheVectorOfUsersEmpty() == true)
                    break;
                else
                managementOfBilancesBook.userLogging();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "This option not exist in this menu" << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {
            choice = managementOfBilancesBook.choseTheOptionFromTheUserMenu();

            switch (choice)
            {
            case '1':
                managementOfBilancesBook.addIncome();
                break;
            case '2':
                managementOfBilancesBook.addExpense();
                break;
            case '3':
                cout << endl << "This fuction isn't presently available" << endl << endl;
                system("pause");
                break;
            case '4':
                cout << endl << "This fuction isn't presently available" << endl << endl;
                system("pause");
                break;
            case '5':
                cout << endl << "This fuction isn't presently available" << endl << endl;
                system("pause");
                break;
            case '6':
                cout << endl << "This fuction isn't presently available" << endl << endl;
                system("pause");
                break;
            case '7':
                cout << endl << "This fuction isn't presently available" << endl << endl;
                system("pause");
                break;
            case '8':
                cout << endl << "This fuction isn't presently available" << endl << endl;
                system("pause");
                break;
            case '9':
                managementOfBilancesBook.logOffTheUser();
                break;
            default:
                cout << endl << "This option not exist in this menu"  << endl << endl;
                system("pause");
                break;
            }
        }
    }
    return 0;
}
