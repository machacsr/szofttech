#ifndef REPAIRMAN_H
#define REPAIRMAN_H
#include <iostream>
#include <vector>
#include <algorithm>
#include "bike.h"
#include "comment.h"
using namespace std;


class Repairman
{
    vector<Bike> *bikes;
    vector<Comment> *repairlist;

public:
    Repairman(vector<Bike> *bikes,vector<Comment> *repairlist);
    void repairBike();
    void testFunc(){
        cout << "Repairman Test function, torolheto!";
    }
};

#endif // REPAIRMAN_H
