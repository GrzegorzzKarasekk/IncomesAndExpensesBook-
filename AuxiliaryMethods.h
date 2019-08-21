#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <sstream> //sstream
#include <algorithm>
#include <string>
#include <cstdlib>
#include <stdio.h> //sprintf
#include <iomanip> //setprecision
#include <math.h> //round
using namespace std;

class AuxiliaryMethods
{
public:

    static string loadTheLine();
    static char loadTheSign();
    static string changeTheFirstLetterToCapitalAndTheRestToLower(string text);
	static string conversionINTToSTRING(int number);
	static double conversionSTRINGToDOUBLE(string text);
	static int conversionSTRINGToINT(string text);
    static double precisionToTwoDecimalPlaces(double numberDouble);
    static string findAndChangeCommaToPeroidInText( string text);
    static string conversionDOUBLEToSTRING(double number);
    //static string pobierzLiczbe(string tekst, int pozycjaZnaku);
    //static int wczytajLiczbeCalkowita();

};

#endif
