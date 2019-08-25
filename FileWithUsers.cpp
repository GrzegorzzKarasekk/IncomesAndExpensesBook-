#include "FileWithUsers.h"

void FileWithUsers::addUserOnToFile(User user)
{
    CMarkup xml;

    bool fileExist = xml.Load("users.xml");
    if(!fileExist)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
        xml.IntoElem();
    }
    else
    {
        xml.FindElem();
        xml.IntoElem();
    }
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("UserId",AuxiliaryMethods::conversionINTToSTRING(user.getUserId()));
    xml.AddElem("Login",user.getLogin());
    xml.AddElem("Password",user.getPassword());
    xml.AddElem("Name",user.getName());
    xml.AddElem("Surname",user.getSurname());

    xml.Save("users.xml");
}

vector <User> FileWithUsers::loadUsersFromTheFile()
{
    CMarkup xml;
    User user;
    vector <User> users;
    bool fileExist = xml.Load("users.xml");
    if(!fileExist)
    {
        cout << endl << "The file users.xml don't exist. No users :( " << endl;
        system("pause");
    }
    else
    {
        int userId = 0;
        string login = "", password = "", name = "", surname = "";

        while(xml.FindChildElem("User"))
        {
            xml.IntoElem();
            xml.FindChildElem( "UserId" );
            userId = atoi( xml.GetChildData().c_str() );
            user.setUserId(userId);

            xml.FindChildElem( "Login" );
            login = xml.GetChildData();
            user.setLogin(login);

            xml.FindChildElem( "Password" );
            password = xml.GetChildData();
            user.setPassword(password);

            xml.FindChildElem( "Name" );
            name = xml.GetChildData();
            user.setName(name);

            xml.FindChildElem( "Surname" );
            surname = xml.GetChildData();
            user.setSurname(surname);

            users.push_back(user);
            xml.OutOfElem();

        }
        return users;

    }
}

void FileWithUsers::changeThePassword(int idLoggedUser)
{
    CMarkup xml;
    User user;

    int idOfCheckUser = 0;
    string password = "";

    bool fileExist = xml.Load("users.xml");
    if(!fileExist)
    {
        cout << endl << "The file users.xml don't exist. No users :( " << endl;
        system("pause");
    }
    else
    {
        while(xml.FindChildElem("User"))
        {
            xml.IntoElem();
            xml.FindChildElem( "UserId" );
            idOfCheckUser = atoi( xml.GetChildData().c_str() );

            if( idOfCheckUser ==  idLoggedUser)
            {
                do
                {
                    cout << "SET PASSWORD: ";
                    password = AuxiliaryMethods::loadTheLine();
                    user.setPassword(password);
                }
                while (isThisSamePassword(password) == false);

                xml.FindChildElem("Password");
                xml.SetChildData(user.getPassword());

                xml.Save("users.xml");
            }
        }
    cout << endl << "The password was changed successfully :D " << endl;
    system("pause");
    }
}

bool FileWithUsers::isThisSamePassword(string password)
{
    string password2 = "";
    cout << "RAPEAT THE PASSWORD: ";

    password2 = AuxiliaryMethods::loadTheLine();

    if(password != password2)
        {
            cout << endl << "Passwords are different!!!" << endl;
            return false;
        }
    else
        return true;
}
