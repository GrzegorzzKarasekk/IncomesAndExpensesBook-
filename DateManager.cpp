#include "DateManager.h"

int DateManager::conversionDateFromSTRINGToINT(string dateTemp)
{
    int numberInt;
	dateTemp.erase( 4,1 );
	dateTemp.erase( 6,1 );
    istringstream iss(dateTemp);
    iss >> numberInt;

    return numberInt;
}

string DateManager::getCurrentTime()
{
    SYSTEMTIME st;
    GetSystemTime(&st);
    int tempDate;
    string currentTempDate = "", currentDate = "";

    tempDate = st.wYear;
    currentTempDate = AuxiliaryMethods::conversionINTToSTRING(tempDate);
    currentDate = currentTempDate;
    currentDate += "-";

    tempDate = st.wMonth;
    currentTempDate = AuxiliaryMethods::conversionINTToSTRING(tempDate);
    if(currentTempDate.length() == 1)
    {
        currentTempDate.insert( 0, "0" );
    }
    currentDate.append(currentTempDate);
    currentDate += "-";

    tempDate = st.wDay;
    currentTempDate = AuxiliaryMethods::conversionINTToSTRING(tempDate);
    if(currentTempDate.length() == 1)
    {
        currentTempDate.insert( 0, "0" );
    }
    currentDate.append(currentTempDate);

    return currentDate;
}

bool DateManager::isTheDateGood(string dateTemp)
{
    char char1;
    char char2;
    string yearTemp = "";
    string monthTemp = "";
    string dayTemp ="";
    int year, month, day;
    int daysInMonth;

    yearTemp.insert( 0, dateTemp, 0, 4 );
    monthTemp.insert( 0, dateTemp, 5, 2 );
    dayTemp.insert( 0, dateTemp, 8, 2 );
    int stringLenght;
    char1 = dateTemp[4];
    char2 = dateTemp[7];
    stringLenght = dateTemp.length();
    if( !char1 == '-' && !char2 == '-' && !stringLenght == 10)
    {
        return false;
    }

    if( monthTemp[0] == 0)
        monthTemp = monthTemp[1];

    if( dayTemp[0] == 0)
        dayTemp = dayTemp[1];

    year = AuxiliaryMethods::conversionSTRINGToINT(yearTemp);
    month = AuxiliaryMethods::conversionSTRINGToINT(monthTemp);
    day = AuxiliaryMethods::conversionSTRINGToINT(dayTemp);

    daysInMonth = howManyDaysAMonth(year, month, day);


    if(year >= 2000 && month <= 12 && month >= 1 && day >= 1 )
    {
        if (month == 1 ||  month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        {
            if(day > daysInMonth)
                return false;
            else
                return true;
        }
        else if (month == 2 && (year%4 ==0 && year%100 !=0 || year%400 ==0))
        {
            if(day > daysInMonth)
                return false;
            else
                return true;
        }
        else if (month == 2 && !(year%4 ==0 && year%100 !=0 || year%400 ==0))
        {
            if(day > daysInMonth)
                return false;
            else
                return true;
        }
        else if(daysInMonth = 30)
        {
            if(day > daysInMonth)
                return false;
            else
                return true;
        }
        else
            return false;
}
}

int DateManager::howManyDaysAMonth(int year, int month, int day)
{
    int daysInMonth;

    if (month == 1 ||  month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
    {
        daysInMonth = 31;
    }
    else if ( month == 2)
    {
        if(year%4 ==0 && year%100 !=0 || year%400 ==0)
            daysInMonth = 29;
        else
            daysInMonth = 28;
    }
    else
    {
        daysInMonth = 30;
    }

    return daysInMonth;
}
