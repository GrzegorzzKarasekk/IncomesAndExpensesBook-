#ifndef XMLFILE_H
#define XMLFILE_H

//#include "AuxiliaryMethods.h"
//#include "User.h"
#include <fstream>
using namespace std;

class XmlFile
{
    const string FILE_NAME;

public:

    XmlFile(string fileName) : FILE_NAME(fileName){};

    string getFileName();
    //bool isTheFileEmpty();
};

#endif
