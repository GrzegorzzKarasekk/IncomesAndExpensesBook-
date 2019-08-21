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

    int date = 0, currentINTDate = 0;
    string nameOfIncome = "", currentDate = "", dateTemp = "";
    string amountTemp = "";
    double amount;
    char choice;

    if(fileWithIncomes.getIdOfLastOperaction() > fileWithExpenses.getIdOfLastOperaction())
        income.setOperactionId((fileWithIncomes.getIdOfLastOperaction()+1));
    else
        income.setOperactionId((fileWithExpenses.getIdOfLastOperaction()+1));

    income.setUserId(ID_OF_LOGGED_USER);

    currentDate = DateManager::getCurrentTime();
    cout << "Current date: " << currentDate << endl;
    currentINTDate = DateManager::conversionDateFromSTRINGToINT(currentDate);

    cout << "Is that your today's income? y - Yes, n - No" << endl;
    do
    {
        cout << "y - Yes, n - No" << endl;
        choice = AuxiliaryMethods::loadTheSign();

        if(choice == 'y' )
        {
            income.setDate(currentINTDate);
        }

        if(choice == 'n')
        {

            cout << "Set date(YYYY-MM-DD): ";
            dateTemp = AuxiliaryMethods::loadTheLine();

            while(!DateManager::isTheDateGood(dateTemp, currentINTDate))
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
            cout << incomes[i].getOperactionId() << endl;
            cout << incomes[i].getDate() << endl;
            cout << incomes[i].getNameOfIncome() << endl;
            cout << incomes[i].getAmount() << endl;}
    }
    else
    {
        cout << endl << "THE INCOMES FILE IS EMPTY" << endl << endl;
    }
    system("pause");
}

void BilanceManager::addExpense()
{
    Expense expense;

    system("cls");
    cout << " >>> ADDING NEW EXPENSE <<<" << endl << endl;
    expense = addDataNewExpense();
    expenses.push_back(expense);

    if(fileWithExpenses.addExpenseToFile(expense))
        cout << "New Expense has been added" << endl;
    else
        cout << "Error. The Expense hasn't been added" << endl;
    system("pause");
}


Expense BilanceManager::addDataNewExpense()
{
    Expense expense;

    int date = 0, currentINTDate = 0;
    string nameOfExpense = "", currentDate = "", dateTemp = "";
    string amountTemp = "";
    double amount;
    char choice;

    if(fileWithExpenses.getIdOfLastOperaction() > fileWithIncomes.getIdOfLastOperaction())
        expense.setOperactionId((fileWithExpenses.getIdOfLastOperaction()+1));
    else
        expense.setOperactionId((fileWithIncomes.getIdOfLastOperaction()+1));

    expense.setUserId(ID_OF_LOGGED_USER);

    currentDate = DateManager::getCurrentTime();
    cout << "Current date: " << currentDate << endl;
    currentINTDate = DateManager::conversionDateFromSTRINGToINT(currentDate);

    cout << "Is that your today's expense? y - Yes, n - No" << endl;
    do
    {
        cout << "y - Yes, n - No" << endl;
        choice = AuxiliaryMethods::loadTheSign();

        if(choice == 'y' )
        {
            expense.setDate(currentINTDate);
        }
        if(choice == 'n')
        {

            cout << "Set date(YYYY-MM-DD): ";
            dateTemp = AuxiliaryMethods::loadTheLine();
            while(!DateManager::isTheDateGood(dateTemp, currentINTDate))
            {
                cout << "Set date(YYYY-MM-DD): ";
                dateTemp = AuxiliaryMethods::loadTheLine();
            }
            date = DateManager::conversionDateFromSTRINGToINT(dateTemp);
            expense.setDate(date);
        }
    }while(!(choice == 'y' || choice =='n'));

    cout << "Set name of expense: ";
    nameOfExpense = AuxiliaryMethods::loadTheLine();
    nameOfExpense = AuxiliaryMethods::changeTheFirstLetterToCapitalAndTheRestToLower(nameOfExpense);
    expense.setNameOfExpense(nameOfExpense);

    cout << "Set amount(For example 20.25): ";
    cin >> amountTemp;
    amountTemp = AuxiliaryMethods::findAndChangeCommaToPeroidInText(amountTemp);
    amount = AuxiliaryMethods::conversionSTRINGToDOUBLE(amountTemp);

    expense.setAmount(amount);

    return expense;
}

void BilanceManager::showAllExpenses()
{
    system("cls");
    if (!expenses.empty())
    {
        cout << "             >>> EXPENSES <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (int i = 0; i < expenses.size(); i++)
        {
            cout << expenses[i].getOperactionId() << endl;
            cout << expenses[i].getDate() << endl;
            cout << expenses[i].getNameOfExpense() << endl;
            cout << expenses[i].getAmount() << endl;}
    }
    else
    {
        cout << endl << "THE EXPENSES FILE IS EMPTY" << endl << endl;
    }
    system("pause");
}


void BilanceManager::showTheBilanceFromThisMonth()
{
    system("cls");

    double incomesAmount = 0;
    double expensesAmount = 0;


    vector<Income> sortedIncomes(incomes);
    vector<Expense> sortedExpenses(expenses);

    sort(sortedIncomes.begin(), sortedIncomes.end());
    sort(sortedExpenses.begin(), sortedExpenses.end());

    cout << "             >>> INCOMES <<<" << endl;
    cout << "-----------------------------------------------" << endl;
    if (!sortedIncomes.empty())
    {
        for (int i = 0; i < sortedIncomes.size(); i++)
        {
            cout << "ID of Operaction: " << sortedIncomes[i].getOperactionId() << endl;
            cout << "Date of INCOME: " << DateManager::conversionINTToDateInString(sortedIncomes[i].getDate()) << endl;
            cout << "Name of INCOME: " << sortedIncomes[i].getNameOfIncome() << endl;
            cout << "Amount of INCOME: " << sortedIncomes[i].getAmount() << endl << endl;
            incomesAmount += sortedIncomes[i].getAmount();
        }
    }
    else
    {
        cout << endl << "No Incomes in this Month" << endl << endl;
    }

    cout << "             >>> EXPENSES <<<" << endl;
    cout << "-----------------------------------------------" << endl;
    if (!sortedExpenses.empty())
    {
        for (int i = 0; i < sortedExpenses.size(); i++)
        {
            cout << "ID of Operaction: " << sortedExpenses[i].getOperactionId() << endl;
            cout << "Date of EXPENSE: " << DateManager::conversionINTToDateInString(sortedExpenses[i].getDate()) << endl;
            cout << "Name of EXPENSE: " << sortedExpenses[i].getNameOfExpense() << endl;
            cout << "Amount of EXPENSE: " << sortedExpenses[i].getAmount() << endl << endl;
            expensesAmount += sortedExpenses[i].getAmount();
        }
    }
    else
    {
        cout << endl << "No Expenses in this Month" << endl << endl;
    }
    cout << "             >>> BALANCE <<<" << endl;
    cout << "-----------------------------------------------" << endl;
    cout << "BALANCE OF THIS MONTH : " << incomesAmount - expensesAmount << endl << endl;
    system("pause");
}
