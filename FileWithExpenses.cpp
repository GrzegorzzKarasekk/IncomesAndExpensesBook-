#include "FileWithExpenses.h"

bool FileWithExpenses::addExpenseToFile(Expense expense)
{
    CMarkup xml;

    bool fileExist = xml.Load("expenses.xml");
    if(!fileExist)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Expenses");
        xml.IntoElem();
    }
    else
    {
        xml.FindElem();
        xml.IntoElem();
    }
    xml.AddElem("Expense");
    xml.IntoElem();
    xml.AddElem("OperactionId",AuxiliaryMethods::conversionINTToSTRING(expense.getOperactionId()));
    xml.AddElem("UserId",AuxiliaryMethods::conversionINTToSTRING(expense.getUserId()));
    xml.AddElem("Date",DateManager::conversionINTToDateInString(expense.getDate()));
    xml.AddElem("NameOfExpense",expense.getNameOfExpense());
    xml.AddElem("Amount",AuxiliaryMethods::conversionDOUBLEToSTRING(expense.getAmount()));
    if(xml.Save("expenses.xml"))
    {
        idOfLastExpenseOperaction ++;
        return true;
    }
    else
    {
        cout << "The expense hasn't beend saved" << endl;
        return false;
    }
}

vector <Expense> FileWithExpenses::loadTheExpensesOfLoggedUser(int idOfLoggedUser)
{
    CMarkup xml;
    Expense expense;
    vector <Expense> expenses;
    bool fileExist = xml.Load("expenses.xml");
    if(!fileExist)
    {
        cout << endl << "The file expenses.xml don't exist or is empty. No expenses, but you can add ;) " << endl;
        system("pause");
    }
    else
    {
        int userId = 0;
        int lastUserOperactionId = 0;
        int operactionId = 0;
        int date = 0;
        string nameOfExpense = "", operactionIdString = "";
        double amount;

        while(xml.FindChildElem("Expense"))
        {
            xml.IntoElem();

            xml.FindChildElem( "OperactionId" );
            operactionIdString = xml.GetChildData();
            operactionId = atoi( xml.GetChildData().c_str() );
            expense.setOperactionId(operactionId);

            xml.FindChildElem( "UserId" );
            userId = atoi( xml.GetChildData().c_str() );
            expense.setUserId(userId);


            xml.FindChildElem( "Date" );
            date = DateManager::conversionDateFromSTRINGToINT(xml.GetChildData().c_str() );
            expense.setDate(date);

            xml.FindChildElem( "NameOfExpense" );
            nameOfExpense = xml.GetChildData();
            expense.setNameOfExpense(nameOfExpense);

            xml.FindChildElem( "Amount" );
            amount = AuxiliaryMethods::conversionSTRINGToDOUBLE(xml.GetChildData());
            expense.setAmount(amount);

            if(userId == idOfLoggedUser)
            {
                lastUserOperactionId = expense.getOperactionId();
                expenses.push_back(expense);
            }
            xml.OutOfElem();
        }

        if (operactionIdString != "")
        {
            idOfLastExpenseOperaction = lastUserOperactionId;
        }
    }

    return expenses;
}

int FileWithExpenses::getIdOfLastExpenseOperaction()
{
    return idOfLastExpenseOperaction;
}
