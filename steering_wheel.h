#ifndef STEERING_WHEEL_H
#define STEERING_WHEEL_H

#include<fstream>
#include<iostream>
#include "accessory.h"
using namespace std;
class Steering_Wheel:public Accessory

{
public:
    Steering_Wheel(string m, string t, int i);
    virtual void Initialize();
    Steering_Wheel();
};

#endif // STEERING_WHEEL_H
