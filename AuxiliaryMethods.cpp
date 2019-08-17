#include "AuxiliaryMethods.h"

string AuxiliaryMethods::conversionINTToSTRING(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

string AuxiliaryMethods::loadTheLine()
{
    string enter = "";
    getline(cin, enter);
    return enter;
}

char AuxiliaryMethods::loadTheSign()
{
    string enter = "";
    char sign = {0};

    while (true)
    {
        getline(cin, enter);

        if (enter.length() == 1)
        {
            sign = enter[0];
            break;
        }
        cout << "It's not a single char!!!. Please enter again." << endl;
    }
    return sign;
}

string AuxiliaryMethods::changeTheFirstLetterToCapitalAndTheRestToLower(string text)
{
    if (!text.empty())
    {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}

float AuxiliaryMethods::conversionSTRINGToFLOAT(string text)
{
    float numberFloat;
    numberFloat = (float)atof(text.c_str());

    return numberFloat;
}

string AuxiliaryMethods::findAndChangeCommaToPeroidInText(string text)
{
    string peroid = ".";
    int position = 0;

    if(text.find(","))
    {
        position = text.find( ',' );
        text.replace(position, 1, peroid);
        return text;
    }
    else
        return text;

}


/*
string MetodyPomocnicze::pobierzLiczbe(string tekst, int pozycjaZnaku)
{
    string liczba = "";
    while(isdigit(tekst[pozycjaZnaku]) == true)
    {
        liczba += tekst[pozycjaZnaku];
        pozycjaZnaku ++;
    }
    return liczba;
}
*/
int AuxiliaryMethods::conversionSTRINGToINT(string text)
{
    //int numberInt;
    //numberInt = atoi(text.c_str());

    //return numberInt;
    int numberInt;
	istringstream iss(text);
    iss >> numberInt;

    return numberInt;
}
/*
int MetodyPomocnicze::wczytajLiczbeCalkowita()
{
    string wejscie = "";
    int liczba = 0;

    while (true)
    {
        getline(cin, wejscie);

        stringstream myStream(wejscie);
        if (myStream >> liczba)
            break;
        cout << "To nie jest liczba. Wpisz ponownie. " << endl;
    }
    return liczba;
}
*/
