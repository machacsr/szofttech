#include "bike.h"

Bike::Bike(int bike_id, int price, string type, string color, string status, vector<Accessory *> accessories):
    bike_id(bike_id),
    price(price),
    type(type),
    color(color),
    status(status),
    accessories(accessories)
{

}

void Bike::setStatus(string status)
{
    this->status = status;
}

void Bike::setPrice(int price)
{
    this->price = price;
}

int Bike::getBikeId()
{
    return bike_id;
}

int Bike::getPrice()
{
    return price;
}

string Bike::getType()
{
    return type;
}

string Bike::getColor()
{
    return color;
}

string Bike::getStatus()
{
    return status;
}
