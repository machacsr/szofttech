#ifndef RESERVATION_H
#define RESERVATION_H

#define MAX_DURATION 30
#include <iostream>
#include <string>
#include <vector>


using namespace std;

class Reservation
{
    string name;
    string calendar[MAX_DURATION]; // minden nap ami re már van foglalás egy nevet tartalmaz aki lefoglalta, a többi pedig egy *-ot
    vector<string> comments; //lehet hogy tárolnunk kellene a dátumot is, amikor hozzáadtuk a megjegyzést(Dani)
    int start;
    int end; //ezeket is tároljuk hátha jól jön(Dani)
    int cost; //ennyibe került a foglalás (Owner - Bevételek összesítéséhez kell)

    //static int numOfReservation; // Owner - statisztikához kell

public:
    Reservation();
    Reservation(int s, int e, string name);
    bool Reservable();
    void Reserving();
    void ListCalendar() const;
    void AddComment(const string comment);
    void ListComments() const;
<<<<<<< HEAD:_OLD20171124/reservation.h
=======

    int getCost() const;
>>>>>>> 33a478979e3047f9dcfa8d3e10bfcc55c5238991:reservation.h
};

#endif // RESERVATION_H
