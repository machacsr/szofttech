#ifndef MAINAPP_H
#define MAINAPP_H
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include "custom.h"
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

    // Ezt írjátok át majd a megfelelő értékre magatoknak és a többit kommentezzétek ki.
    string file_location = "d:\\suli\\szofttech\\Project\\szofttech\\"; //Botond
   // string file_location = "d:\\suli\\szofttech\\Project\\szofttech\\"; //Dani
   // string file_location = "d:\\suli\\szofttech\\Project\\szofttech\\"; //Miki
   // string file_location = "d:\\suli\\szofttech\\Project\\szofttech\\"; //Roli

public:
    MainApp();
    void loadMenu();
    void runTest();
    void clearScreen();
    void loadData();
    void loadReservations();
    void saveData();
    void listBikes();
    void findBikes();
    void printRes();
};

#endif // MAINAPP_H
