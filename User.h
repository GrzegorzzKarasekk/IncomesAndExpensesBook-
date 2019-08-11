#ifndef USER_H
#define USER_H

#include <iostream>

using namespace std;

class User
{
    int userId;
	string name;
	string surname;
    string login;
    string password;

public:
    User(int userId = 0,string name = "",string surname = "", string login = "", string password = "")
    {
        this -> userId = userId;
		this -> name = name;
		this -> surname = surname;
        this -> login = login;
        this -> password = password;
    }

    void setUserId(int newUserId);
    void setName(string newName);
    void setSurname(string newSurname);
    void setLogin(string newLogin);
    void setPassword(string newPassword);

    int getUserId();
    string getName();
    string getSurname();
    string getLogin();
    string getPassword();

};

#endif
