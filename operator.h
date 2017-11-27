#ifndef OPERATOR_H
#define OPERATOR_H
#include <iostream>
#include <vector>
#include "custom.h"
#include "bike.h"
#include "reservation.h"

using namespace std;

class Operator
{
    vector<Bike> *bikes;
    vector<Reservation> *reservations;

public:
    Operator(vector<Bike> *bikes, vector<Reservation> *reservations);
    void listReservations();
    void searchReservation();
    void addReservation();
    void editReservation();
    void deleteReservation();
    void sendBikeToRepair();
};

#endif // OPERATOR_H
