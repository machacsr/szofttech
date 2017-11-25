#ifndef MAINAPP_H
#define MAINAPP_H
#include <iostream>
#include <vector>
#include <list>
#include "bike.h"
#include "reservation.h"
#include "comment.h"
#include "owner.h"
#include "operator.h"
#include "admin.h"
#include "repairman.h"

using namespace std;
class MainApp
{
    vector<Bike> *bikes;
    vector<Reservation> *reservations;
    vector<Comment> *repairlist;
    Owner *owner;
    Operator *op;
    Admin *admin;
    Repairman *repairman;
public:
    MainApp();
    void loadMenu();
    string getString();
    void clearScreen();
    int getInt();
    void pause();
    void loadData();
    void saveData();
    void listBikes();
    void findBikes();
    void printRes();
};

#endif // MAINAPP_H
