#include <iostream>
#include "ManagementOfBilancesBook.h"

using namespace std;

int main()
{
    ManagementOfBilancesBook managementOfBilancesBook("Users.xml");
    managementOfBilancesBook.userRegistration();
    managementOfBilancesBook.userRegistration();

    return 0;
}
