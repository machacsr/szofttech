#ifndef BREAK_H
#define BREAK_H

#include<fstream>
#include<iostream>
#include "accessory.h"
using namespace std;
class Break:public Accessory
{
public:
    Break();
    Break(string m, string t, int i);
    virtual void Initialize();
};

#endif // BREAK_H
