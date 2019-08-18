#include "UserOperaction.h"

void UserOperaction::setUserId(int newUserId)
{
    if (newUserId >= 0)
        userId = newUserId;
}
void UserOperaction::setOperationId(int newOperationId)
{
    if (newOperationId >= 0)
        operationId = newOperationId;
}
void UserOperaction::setDate(int newDate)
{
    date = newDate;
}
void UserOperaction::setAmount(double newAmount)
{
    amount = newAmount;
}
int UserOperaction::getUserId()
{
   return userId;
}
int UserOperaction::getOperationId()
{
   return operationId;
}
int UserOperaction::getDate()
{
   return date;
}
double UserOperaction::getAmount()
{
   return amount;
}
