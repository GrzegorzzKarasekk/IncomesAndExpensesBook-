#ifndef USEROPERACTION_H
#define USEROPERACTION_H

#include <iostream>

using namespace std;

class UserOperaction
{
    int userId;
	int operationId;
	int date;
    double amount;

public:
    UserOperaction(int userId = 0,int operationId = 0,int date = 0, double amount = 0.0)
    {
        this -> userId = userId;
		this -> operationId = operationId;
		this -> date = date;
        this -> amount = amount;
    }

    void setUserId(int newUserId);
    void setOperationId(int newOperationId);
    void setDate(int newDate);
    void setAmount(double newAmount);

    int getUserId();
    int getOperationId();
	int getDate();
	double getAmount();

};

#endif
