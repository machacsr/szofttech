#ifndef BIKE_H
#define BIKE_H
#include <iostream>
#include <string>
#include <vector>
#include "custom.h"
#include "accessory.h"

using namespace std;

class Bike
{
    int bike_id;
    int price;
    string type;
    string color;
    string status;
    vector<Accessory*> accessories;
public:
    Bike(int bike_id,int price,string type,string color,string status,vector<Accessory*> accessories);

    void setStatus(string status);
    void setPrice(int price);
    int getBikeId();
    int getPrice();
    string getType();
    string getColor();
    string getStatus();

};

#endif // BIKE_H
