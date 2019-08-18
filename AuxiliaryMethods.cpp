#include "AuxiliaryMethods.h"

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

string AuxiliaryMethods::conversionINTToSTRING(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

string AuxiliaryMethods::conversionDOUBLEToSTRING(double numberDouble)
{
    stringstream stream;
    stream << std::fixed << setprecision(2) << numberDouble;
    string str = stream.str();
        // print results
    return str;
}


double AuxiliaryMethods::conversionSTRINGToDOUBLE(string text)
{
    float numberDouble;
    string text2 = "";
    istringstream isstream(text);
    isstream >> numberDouble;
    numberDouble = precisionToTwoDecimalPlaces(numberDouble);
    if(isstream.fail())
    {
        // handle errors
        cout << "Error while converting string to double" << endl;
        cout << "Set correct amount (For example 20.25)" << endl;
        cin >> text2;

        conversionSTRINGToDOUBLE(text2);
    }
    else
        // print results
        return numberDouble;
}

double AuxiliaryMethods::precisionToTwoDecimalPlaces(double numberDouble)
{
    return round(numberDouble*100)/100;
}

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

string AuxiliaryMethods::findAndChangeCommaToPeroidInText(string text)
{
    string peroid = ".";
    int position = text.find(",");
    if(position == string::npos)
    {
        return text;
    }
    else
    {
        text.replace(position, 1, peroid);
		return text;
    }
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
