#include "BilanceManager.h"

void BilanceManager::addIncome()
{
    Income income;

    system("cls");
    cout << " >>> ADDING NEW INCOME <<<" << endl << endl;
    income = addDataNewIncome();
    incomes.push_back(income);

    if(fileWithIncomes.addIncomeToFile(income))
        cout << "New Income has been added" << endl;
    else
        cout << "Error. The Income hasn't been added" << endl;
    system("pause");
}


Income BilanceManager::addDataNewIncome()
{
    Income income;

    int date = 0;
    string nameOfIncome = "", dateTemp = "";
    string amountTemp = "";
    double amount;
    char choice;

    income.setOperationId((fileWithIncomes.getIdOfLastOperaction()+1));
    income.setUserId(ID_OF_LOGGED_USER);

    cout << "Is that your today's income? y - Yes, n - No" << endl;
    do
    {
        cout << "y - Yes, n - No" << endl;
        choice = AuxiliaryMethods::loadTheSign();

        if(choice == 'y' )
        {
            dateTemp = DateManager::getCurrentTime();
            cout << "Current date: " << dateTemp << endl;
            date = DateManager::conversionDateFromSTRINGToINT(dateTemp);
            income.setDate(date);
        }
        if(choice == 'n')
        {

            cout << "Set date(YYYY-MM-DD): ";
            dateTemp = AuxiliaryMethods::loadTheLine();
            while(!DateManager::isTheDateGood(dateTemp))
            {
                cout << "Set date(YYYY-MM-DD): ";
                dateTemp = AuxiliaryMethods::loadTheLine();
            }
            date = DateManager::conversionDateFromSTRINGToINT(dateTemp);
            income.setDate(date);
        }
    }while(!(choice == 'y' || choice =='n'));

    cout << "Set name of income: ";
    nameOfIncome = AuxiliaryMethods::loadTheLine();
    nameOfIncome = AuxiliaryMethods::changeTheFirstLetterToCapitalAndTheRestToLower(nameOfIncome);
    income.setNameOfIncome(nameOfIncome);

    cout << "Set amount(For example 20.25): ";
    cin >> amountTemp;
    amountTemp = AuxiliaryMethods::findAndChangeCommaToPeroidInText(amountTemp);
    amount = AuxiliaryMethods::conversionSTRINGToDOUBLE(amountTemp);

    income.setAmount(amount);

    return income;
}

void BilanceManager::showAllIncomes()
{
    system("cls");
    if (!incomes.empty())
    {
        cout << "             >>> INCOMES <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (int i = 0; i < incomes.size(); i++)
        {
            cout << incomes[i].getOperationId() << endl;
            cout << incomes[i].getDate() << endl;
            cout << incomes[i].getNameOfIncome() << endl;
            cout << incomes[i].getAmount() << endl;}
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    system("pause");
}

