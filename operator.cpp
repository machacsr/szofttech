#include "operator.h"

Operator::Operator(vector<Bike> *bikes, vector<Reservation> *reservations):
    bikes(bikes), reservations(reservations)
{

}

void Operator::listReservations()
{
    printTitle("List of Reservations");
    for(auto res:*reservations)
        res.print();
}

void Operator::searchReservation()
{

}

void Operator::addReservation()
{
    printTitle("Add New Reservation");

    int res_id = 0;
    string status;
    string name;
    string idnumber;
    string date_current;
    string date_from;
    string date_to;
    vector<int> bike_ids;
    string comment;

    cout << "Name: ";
    name = getString();
    cout << "ID number: ";
    idnumber = getString();

    //Itt még validálni kéne a dátumokat:
    cout << "Date from (accepted format: YYYY-MM-DD): ";
    date_from = getString();
    cout << "Date to (accepted format: YYYY-MM-DD): ";
    date_to = getString();

    //Itt kéne egy lista az adott dátumok között elérhető biciklikről + validálás
    cout << "Select bike(s): ";
    int bike_id = getInt();
    bike_ids.push_back(bike_id);
    cout << "Select bike(s): ";
    bike_id = getInt();
    bike_ids.push_back(bike_id);
    cout << "Add comment (not required): ";
    comment = getString();

    //res_id automatikus megadása
    for(auto res : *reservations){
       if(res.getRes_id() >= res_id) res_id = res.getRes_id()+1;
    }

    date_current = getNow();
    status = "Reserved";
    reservations->push_back({res_id, status, name, idnumber, date_current, date_from, date_to, bike_ids, comment});
    cout << "The reservation has been created." << endl;
}

void Operator::editReservation()
{

}

void Operator::deleteReservation()
{

}

void Operator::sendBikeToRepair()
{

}
