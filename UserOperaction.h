#ifndef USEROPERACTION_H
#define USEROPERACTION_H
#include <iostream>

using namespace std;

class UserOperaction
{
    int userId;
	int operactionId;
	int date;
    float amount;

public:

    UserOperaction( int nUserId = 0, int nOperactionId = 0,int nDate = 0, float nAmount = 0.0) :
        userId(nUserId), operactionId(nOperactionId), date(nDate), amount(nAmount)
        {
            this -> userId = nUserId;
            this -> operactionId = nOperactionId;
            this -> date = nDate;
            this -> amount = nAmount;
        }

    void setUserId(int newUserId);
    void setOperactionId(int newOperactionId);
    void setDate(int newDate);
    void setAmount(float newAmount);

    int getUserId();
    int getOperactionId();
	int getDate();
	float getAmount();

};

#endif
