#include "XmlFile.h"

string XmlFile::getFileName()
{
    return FILE_NAME;
}
/*
bool XmlFile::isTheFileEmpty()
{
    bool isEmpty = true;
    fstream plikTekstowy;
    plikTekstowy.open(pobierzNazwePliku().c_str(), ios::app);

    if (plikTekstowy.good() == true)
    {
        plikTekstowy.seekg(0, ios::end);
        if (plikTekstowy.tellg() != 0)
            pusty = false;
    }

    plikTekstowy.close();
    return pusty;
}
*/
