#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <cstdlib>

using namespace std;

class AuxiliaryMethods
{
public:
    static string conversionINTToSTRING(int number);
    static string loadTheLine();
    static char loadTheSign();
    static string changeTheFirstLetterToCapitalAndTheRestToLower(string text);
	static float conversionSTRINGToFLOAT(string text);
	static int conversionSTRINGToINT(string text);
    static string findAndChangeCommaToPeroidInText( string text);
    //static string pobierzLiczbe(string tekst, int pozycjaZnaku);
    //static int wczytajLiczbeCalkowita();

};

#endif
