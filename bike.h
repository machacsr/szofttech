#ifndef BIKE_H
#define BIKE_H
#include <iostream>
#include <string>
#include <vector>
#include "custom.h"
#include "accessory.h"
#include "break.h"
#include "steering_wheel.h"
#include "wheel.h"
#include "lamp.h"
#include "comment.h"
using namespace std;

class Bike
 {
    static int bike_id;
    int price;
    string type;
    string color;
    string status;
    vector<Comment> *comments;
    vector<Accessory*> accessories;
protected:
    void setId(int n);
    void setColor(string s);
    void setType(string t);
public:
    Bike(int price,string type,string color,string status,vector<Accessory*> accessories);
    Bike();
    void PrintBike() const;
    void setStatus(string status);
    void setPrice(int price);
    int getBikeId();
    int getPrice();
    string getInfo();
    void AddComment();
    string getType();
    string getColor();
    string getStatus();
    vector<Comment>* getComments();
    vector<Accessory *> getAccessories();

};

#endif // BIKE_H
