#include "FileWithIncomes.h"

bool FileWithIncomes::addIncomeToFile(Income income)
{
    CMarkup xml;

    bool fileExist = xml.Load("incomes.xml");
    if(!fileExist)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
        xml.IntoElem();
    }
    else
    {
        xml.FindElem();
        xml.IntoElem();
    }
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem("OperactionId",AuxiliaryMethods::conversionINTToSTRING(income.getOperationId()));
    xml.AddElem("UserId",AuxiliaryMethods::conversionINTToSTRING(income.getUserId()));
    xml.AddElem("Date",DateManager::conversionINTToDateInString(income.getDate()));
    xml.AddElem("NameOfIncome",income.getNameOfIncome());
    xml.AddElem("Amount",AuxiliaryMethods::conversionDOUBLEToSTRING(income.getAmount()));
    if(xml.Save("incomes.xml"))
    {
        idOfLastOperaction ++;
        return true;
    }
    else
    {
        cout << "The income hasn't beend saved" << endl;
        return false;
    }
}

vector <Income> FileWithIncomes::loadTheIncomesOfLoggedUser(int idOfLoggedUser)
{
    CMarkup xml;
    Income income;
    vector <Income> incomes;
    bool fileExist = xml.Load("incomes.xml");
    if(!fileExist)
    {
        cout << endl << "The file incomes.xml don't exist or is empty. No incomes, but you can add ;) " << endl;
        system("pause");
    }
    else
    {
        int userId = 0;
        int lastUserOperactionId = 0;
        int operactionId = 0;
        int date = 0;
        string nameOfIncome = "", operactionIdString = "";
        double amount;

        while(xml.FindChildElem("Income"))
        {
            xml.IntoElem();

            xml.FindChildElem( "OperactionId" );
            operactionIdString = xml.GetChildData();
            operactionId = atoi( xml.GetChildData().c_str() );
            income.setOperationId(operactionId);

            xml.FindChildElem( "UserId" );
            userId = atoi( xml.GetChildData().c_str() );
            income.setUserId(userId);


            xml.FindChildElem( "Date" );
            date = DateManager::conversionDateFromSTRINGToINT(xml.GetChildData().c_str() );
            income.setDate(date);

            xml.FindChildElem( "NameOfIncome" );
            nameOfIncome = xml.GetChildData();
            income.setNameOfIncome(nameOfIncome);

            xml.FindChildElem( "Amount" );
            amount = AuxiliaryMethods::conversionSTRINGToDOUBLE(xml.GetChildData());
            income.setAmount(amount);

            if(userId == idOfLoggedUser)
            {
                lastUserOperactionId = income.getOperationId();
                incomes.push_back(income);
                //cout << income.getOperationId() << endl;
                // cout << income.getDate() << endl;
                //cout << income.getNameOfIncome() << endl;
                //cout << income.getAmount() << endl;
            }
            xml.OutOfElem();
        }

        if (operactionIdString != "")
        {
            idOfLastOperaction = lastUserOperactionId;
            //cout <<"idOfLastoperaction " <<idOfLastoperaction << endl;
            //system("pause");
        }
    }

    return incomes;
}

int FileWithIncomes::getIdOfLastOperaction()
{
    return idOfLastOperaction;
}
