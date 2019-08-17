#include "BilanceManager.h"

void BilanceManager::addIncome()
{
    Income income;

    system("cls");
    cout << " >>> ADDING NEW INCOME <<<" << endl << endl;
    income = addDataNewIncome();
    incomes.push_back(income);

    cout << endl << income.getUserId() << endl;
    cout << endl << income.getOperationId() << endl;
    cout << endl << income.getDate() << endl;
    cout << endl << income.getNameOfIncome() << endl;
    cout << endl << income.getAmount() << endl;


    //if(plikZAdresatami.dopiszAdresataDoPliku(adresat))
    //    cout << "Nowy adresat zostal dodany" << endl;
    //else
    //    cout << "Blad. Nie udalo sie dodac nowego adresata do pliku" << endl;
    system("pause");
}


Income BilanceManager::addDataNewIncome()
{
    Income income;

    int date;
    string nameOfIncome, dateTemp;
    string amountTemp;
    float amount;
    char choice;

    income.setOperationId(1);
    income.setUserId(ID_OF_LOGGED_USER);

    cout << "Is that your today's income? y - Yes, n - No" << endl;
    choice = AuxiliaryMethods::loadTheSign();
    while(!(choice == 'y' ||choice =='n'))
    {
        cout << "y - Yes, n - No" << endl;
        choice = AuxiliaryMethods::loadTheSign();
    }
    if(choice == 'y' )
    {
        dateTemp = DateManager::getCurrentTime();
        cout << "Current date: " << dateTemp << endl;
        date = DateManager::conversionDateFromSTRINGToINT(dateTemp);
    }
    else
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


    cout << "Set name of income: ";
    nameOfIncome = AuxiliaryMethods::loadTheLine();
    nameOfIncome = AuxiliaryMethods::changeTheFirstLetterToCapitalAndTheRestToLower(nameOfIncome);
    income.setNameOfIncome(nameOfIncome);

    cout << "Set amount: ";
    amountTemp = AuxiliaryMethods::loadTheLine();
    amountTemp = AuxiliaryMethods::findAndChangeCommaToPeroidInText(amountTemp);
    system("pause");
    amount = AuxiliaryMethods::conversionSTRINGToFLOAT(amountTemp);
    income.setAmount(amount);

    return income;
}

