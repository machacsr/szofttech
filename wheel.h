#ifndef WHEEL_H
#define WHEEL_H

#include<fstream>
#include<iostream>
#include "accessory.h"
using namespace std;
class Wheel:public Accessory
{
public:
    Wheel(string m, string t, int i);
    virtual void Initialize();
    Wheel();
};

#endif // WHEEL_H
