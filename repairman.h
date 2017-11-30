#ifndef REPAIRMAN_H
#define REPAIRMAN_H
#include <iostream>
#include <vector>
#include <algorithm>
#include "bike.h"
#include "custom.h"
#include "comment.h"
#include "employee.h"
using namespace std;


class Repairman:public Employee
{
    vector<Bike> *bikes;
    vector<Comment> *comments;
    vector<Bike> badbikes;

public:
    Repairman(vector<Bike> *bikes,vector<Comment> *c);
    void repairBike();
    void AddComment();
    void WriteBadBikesToFile();
    void WriteCommentsToFile();
};

#endif // REPAIRMAN_H
