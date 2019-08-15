#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include <iostream>
#include <vector>
//#include <fstream>
//#include <sstream>
#include <cstdlib>

#include "AuxiliaryMethods.h"
#include "User.h"
#include "XmlFile.h"
#include "Markup.h"


using namespace std;

class FileWithUsers : public XmlFile
{

public:
    FileWithUsers(string nameTheFileWithUsers) : XmlFile(nameTheFileWithUsers) {};
    void addUserOnToFile(User user);
    vector <User> loadUsersFromTheFile();
    //void zapiszWszystkichUzytkownikowDoPliku(vector <Uzytkownik> &uzytkownicy);

};

#endif
