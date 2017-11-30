#include "accessory.h"

int Accessory::RandomNumber(int num)
{
    return (rand() % (num-2) + 1);
}

void Accessory::setType(string s)
{
    type=s;
}

void Accessory::setMaker(string s)
{
    maker=s;
}

Accessory::Accessory()
{

}

Accessory::Accessory(string m, string t, int i, bool w):
    maker(m),
    type(t),
    id(i), state(w)
{

}

const string Accessory::getType() const
{
    return type;
}

const string Accessory::getMaker() const
{
    return maker;
}

const int Accessory::getId() const
{
    return id;
}

const bool Accessory::getState() const
{
    return state;
}

void Accessory::ChangeState()
{
    state=!state;
}

void Accessory::Initialize()
{

}

void Accessory::setId(int num)
{
    id=num;
}
