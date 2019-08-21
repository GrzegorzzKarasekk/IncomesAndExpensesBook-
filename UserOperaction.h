#ifndef USEROPERACTION_H
#define USEROPERACTION_H
//#include <>
#include <iostream>

using namespace std;

class UserOperaction
{
    int userId;
	int operationId;
	int date;
    float amount;

public:

    UserOperaction(int userId = 0,int operationId = 0,int date = 0, float amount = 0.0)
    {
        this -> userId = userId;
		this -> operationId = operationId;
		this -> date = date;
        this -> amount = amount;
    }

    void setUserId(int newUserId);
    void setOperationId(int newOperationId);
    void setDate(int newDate);
    void setAmount(float newAmount);

    int getUserId();
    int getOperationId();
	int getDate();
	float getAmount();

};

#endif
