#ifndef OWNER_H
#define OWNER_H
#include <iostream>
#include <vector>
#include "custom.h"
#include "bike.h"
#include "comment.h"
#include "reservation.h"
using namespace std;

class Owner
{
    vector<Bike> *bikes;
    vector<Reservation> *reservations;
    vector<Comment> *repairlist;

public:
    Owner(vector<Bike> *bikes,vector<Reservation> *reservations,vector<Comment> *repairlist);
    void testFunc(){
        cout << "Owner Test function, torolheto!";
    }
};

#endif // OWNER_H
