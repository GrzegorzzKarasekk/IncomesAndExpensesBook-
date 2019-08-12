#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

class AuxiliaryMethods
{
public:
    static string conversionINTToSTRING(int number);
    static string loadTheLine();
    static char loadTheSign();
    static string changeTheFirstLetterToCapitalAndTheRestToLower(string text);
    //static string pobierzLiczbe(string tekst, int pozycjaZnaku);
    //static int konwersjaStringNaInt(string liczba);
    //static int wczytajLiczbeCalkowita();

};

#endif
