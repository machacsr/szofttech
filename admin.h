#ifndef ADMIN_H
#define ADMIN_H
#include <iostream>
#include <vector>
#include "bike.h"


using namespace std;


class Admin
{
    vector<Bike> *bikes;
public:
    Admin(vector<Bike> *bikes);
    void testFunc(){
        cout << "Admin Test function, torolheto!";
    }
    void setBikePrice();
};

#endif // ADMIN_H
