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
    }
    while(!(choice == 'y' || choice =='n'));

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
            cout << incomes[i].getAmount() << endl;
        }
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
    }
    while(!(choice == 'y' || choice =='n'));

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
            cout << expenses[i].getAmount() << endl;
        }
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
    int currentDate =0;

    currentDate = DateManager::conversionDateFromSTRINGToINT(DateManager::getCurrentTime());

    vector<Income> sortedIncomes(selectingIncomesFromVector(incomes, currentDate, 1, 0 , 0));
    vector<Expense> sortedExpenses(selectingExpensesFromVector(expenses,currentDate, 1, 0 , 0));


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
        cout << "ALL OF AMOUNT INCOMES: " << incomesAmount << endl << endl;

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
        cout << "ALL OF AMOUNT EXPENSES: " << expensesAmount << endl << endl;

    }
    else
    {
        cout << endl << "No Expenses in this Month" << endl << endl;
    }
    cout << "             >>> BALANCE <<<" << endl;
    cout << "-----------------------------------------------" << endl << endl;
    cout << "BALANCE OF THIS MONTH : " << incomesAmount - expensesAmount << endl << endl;
    system("pause");
}

void BilanceManager::showTheBilanceFromPreviousMonth()
{
    system("cls");

    double incomesAmount = 0;
    double expensesAmount = 0;
    int currentDate =0;

    currentDate = DateManager::conversionDateFromSTRINGToINT(DateManager::getCurrentTime());

    vector<Income> sortedIncomes(selectingIncomesFromVector(incomes, currentDate, 2, 0 , 0));
    vector<Expense> sortedExpenses(selectingExpensesFromVector(expenses,currentDate, 2, 0 , 0));


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
        cout << "ALL OF AMOUNT INCOMES: " << incomesAmount << endl << endl;

    }
    else
    {
        cout << endl << "No Incomes in previous Month" << endl << endl;
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
        cout << "ALL OF AMOUNT EXPENSES: " << expensesAmount << endl << endl;

    }
    else
    {
        cout << endl << "No Expenses in previous Month" << endl << endl;
    }
    cout << "             >>> BALANCE <<<" << endl;
    cout << "-----------------------------------------------" << endl << endl;
    cout << "BALANCE OF THIS MONTH : " << incomesAmount - expensesAmount << endl << endl;
    system("pause");
}

void BilanceManager::showTheBilanceFromPeroid()
{
    system("cls");

    double incomesAmount = 0;
    double expensesAmount = 0;
    int currentDate = 0;
    int beginningOfThePeriod = 0;
    int endOfPeriod = 0;

    currentDate = DateManager::conversionDateFromSTRINGToINT(DateManager::getCurrentTime());

    string beginningOfThePeriodInString = "";
    string endOfPeriodInString = "";

    cout << "Set Beginning of The Peroid (YYYY-MM-DD): ";
    beginningOfThePeriodInString = AuxiliaryMethods::loadTheLine();
    while(!DateManager::isTheDateGood(beginningOfThePeriodInString,currentDate))
    {
        cout << "Set date(YYYY-MM-DD): ";
        beginningOfThePeriodInString = AuxiliaryMethods::loadTheLine();
    }
    beginningOfThePeriod = DateManager::conversionDateFromSTRINGToINT(beginningOfThePeriodInString);
    cout << endl;
    cout << "Set End of The Peroid (YYYY-MM-DD): ";
    endOfPeriodInString = AuxiliaryMethods::loadTheLine();
    while(!DateManager::isTheDateGood(endOfPeriodInString,currentDate))
    {
        cout << "Set date(YYYY-MM-DD): ";
        endOfPeriodInString = AuxiliaryMethods::loadTheLine();
    }
    endOfPeriod = DateManager::conversionDateFromSTRINGToINT(endOfPeriodInString);

    vector<Income> sortedIncomes(selectingIncomesFromVector(incomes, currentDate, 3, beginningOfThePeriod, endOfPeriod));
    vector<Expense> sortedExpenses(selectingExpensesFromVector(expenses,currentDate, 3, beginningOfThePeriod, endOfPeriod));


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
        cout << "ALL OF AMOUNT INCOMES: " << incomesAmount << endl << endl;

    }
    else
    {
        cout << endl << "No Incomes in this Peroid" << endl << endl;
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
        cout << "ALL OF AMOUNT EXPENSES: " << expensesAmount << endl << endl;

    }
    else
    {
        cout << endl << "No Expenses in this Peroid" << endl << endl;
    }
    cout << "             >>> BALANCE <<<" << endl;
    cout << "-----------------------------------------------" << endl << endl;
    cout << "BALANCE OF PEROID : " << incomesAmount - expensesAmount << endl << endl;
    system("pause");
}

vector <Income> BilanceManager::selectingIncomesFromVector(vector <Income> incomes, int currentDate, char choice, int beginningOfThePeriod, int endOfPeriod)
{
    vector<Income> selectedIncomes;
    int currentMonthDate = 0, previousMonthDate = 0;


    currentMonthDate = currentDate/100;
    currentMonthDate *= 100;
    currentMonthDate += 1;

    if (choice == 1)
    {
        if (!incomes.empty())
        {
            for (int i = 0; i < incomes.size(); i++)
            {
                if(incomes[i].getDate() >=currentMonthDate && incomes[i].getDate() < (currentMonthDate +31))
                    selectedIncomes.push_back(incomes[i]);
            }
        }
        return selectedIncomes;
    }
    else if (choice == 2)
    {
        string currentStringDate ="";
        currentStringDate = DateManager::conversionINTToDateInString(currentDate);
        if(currentStringDate[5] == 0 && currentStringDate[6] == 1 )
        {
            previousMonthDate = currentMonthDate - 8900;
            previousMonthDate +=1;
        }
        else
            previousMonthDate = currentMonthDate - 100;
        previousMonthDate +=1;

        if (!incomes.empty())
        {
            for (int i = 0; i < incomes.size(); i++)
            {
                if(incomes[i].getDate() >= previousMonthDate && incomes[i].getDate() < (previousMonthDate +31))
                    selectedIncomes.push_back(incomes[i]);
            }
        }
        return selectedIncomes;
    }
    else if (choice == 3)
    {
        if (!incomes.empty())
        {
            for (int i = 0; i < incomes.size(); i++)
            {
                if(incomes[i].getDate() >= beginningOfThePeriod && incomes[i].getDate() <= endOfPeriod)
                    selectedIncomes.push_back(incomes[i]);
            }
        }
        return selectedIncomes;
    }
    else
    {
        cout << endl << "There was a problem with selected Incomes"  << endl << endl;
        system("pause");
        return selectedIncomes;
    }
}

vector <Expense> BilanceManager::selectingExpensesFromVector(vector <Expense> expenses, int currentDate, char choice, int beginningOfThePeriod, int endOfPeriod)
{
    vector<Expense> selectedExpenses;
    int currentMonthDate = 0, previousMonthDate = 0;


    currentMonthDate = currentDate/100;
    currentMonthDate *= 100;
    currentMonthDate += 1;

    if(choice == 1)
    {
        if (!expenses.empty())
        {
            for (int i = 0; i < expenses.size(); i++)
            {
                if(expenses[i].getDate() >=currentMonthDate && expenses[i].getDate() < (currentMonthDate +31))
                    selectedExpenses.push_back(expenses[i]);
            }
        }
        return selectedExpenses;
    }
    else if(choice == 2)
    {
        string currentStringDate = "";
        currentStringDate = DateManager::conversionINTToDateInString(currentDate);
        if(currentStringDate[5] == 0 && currentStringDate[6] == 1 )
        {
            previousMonthDate = currentDate - 8900;
            previousMonthDate +=1;
        }
        else
        {
            previousMonthDate = currentDate - 100;
            previousMonthDate +=1;
        }

        if (!expenses.empty())
        {
            for (int i = 0; i < expenses.size(); i++)
            {
                if(expenses[i].getDate() >= previousMonthDate && expenses[i].getDate() < (previousMonthDate +31))
                    selectedExpenses.push_back(expenses[i]);
            }
        }
        return selectedExpenses;
    }
    else if (choice == 3)
    {
        if (!expenses.empty())
        {
            for (int i = 0; i < expenses.size(); i++)
            {
                if(expenses[i].getDate() >=beginningOfThePeriod && expenses[i].getDate() <= endOfPeriod)
                        selectedExpenses.push_back(expenses[i]);
            }
    }
    return selectedExpenses;
}
else
{

    cout << endl << "There was a problem with selected Incomes"  << endl << endl;
    system("pause");
        return selectedExpenses;
    }
}


