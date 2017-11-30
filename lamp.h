#ifndef LAMP_H
#define LAMP_H


#include<fstream>
#include<iostream>
#include "accessory.h"
using namespace std;
class Lamp:public Accessory
{
public:
    Lamp(string m, string t, int i);
    virtual void Initialize();
    Lamp();
};

#endif // LAMP_H
