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
