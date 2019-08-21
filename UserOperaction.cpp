#include "UserOperaction.h"

void UserOperaction::setUserId(int newUserId)
{
    if (newUserId >= 0)
        userId = newUserId;
}
void UserOperaction::setOperactionId(int newOperactionId)
{
    if (newOperactionId >= 0)
        operactionId = newOperactionId;
}
void UserOperaction::setDate(int newDate)
{
    date = newDate;
}
void UserOperaction::setAmount(float newAmount)
{
    amount = newAmount;
}
int UserOperaction::getUserId()
{
   return userId;
}
int UserOperaction::getOperactionId()
{
   return operactionId;
}
int UserOperaction::getDate()
{
   return date;
}
float UserOperaction::getAmount()
{
   return amount;
}
