#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <iostream>
#include <windows.h>
#include <string.h>
#include "AuxiliaryMethods.h"

using namespace std;

class DateManager
{
	public:
	static int conversionDateFromSTRINGToINT(string dateTemp);
    static string getCurrentTime();
    static bool isTheDateGood(string dateTemp);
    static int howManyDaysAMonth(int year, int month, int day);
};

#endif
