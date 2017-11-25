#ifndef OWNER_H
#define OWNER_H
#include "employee.h"

class Owner
{
public:
    Owner();

    /*  addUser()   -   Alkalmazottak felvétele
     *  createStatistics()  -   Statisztika
     *  repairList()    -   Karbantartások listázása
     *  totalRevenue()  -   Bevételek összesítése
     * */

    Employee* addUser();
    void createStatistics();
    void repairList();
    int totalRevenue();
};

#endif // OWNER_H
