#ifndef ACCESSORY_H
#define ACCESSORY_H
#include <iostream>
#include "custom.h"
using namespace std;


class Accessory
{
    string type;
    string maker;
    int id;
    bool state;

protected:
    void setType(string s);
    void setMaker(string s);
public:
    Accessory();
    Accessory(string m, string t, int i, bool w);
    const string getType() const;
    const string getMaker()const ;
    const int getId()const ;
    const bool getState()const ;
    void ChangeState();
    virtual void Initialize();
    virtual void setId(int num);
    int RandomNumber(int num);

};

#endif // ACCESSORY_H
