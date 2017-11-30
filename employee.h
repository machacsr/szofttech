#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include<fstream>
#include"bike.h"
#include <iostream>
using namespace std;
class Employee
{
public:
    Employee();
    virtual Bike BikeSearch(vector<Bike> *bikes) const;
    virtual void BikeList( vector<Bike> *bikes) const;
    virtual void WriteToFile(string filename, vector<Bike> *bikes);
};

#endif // EMPLOYEE_H
