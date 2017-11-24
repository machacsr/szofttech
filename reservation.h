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

public:
    Reservation();
    Reservation(int s, int e, string name);
    bool Reservable();
    void Reserving();
    void ListCalendar() const;
    void AddComment(const string comment);
    void ListComments() const;

    int getCost() const;
};

#endif // RESERVATION_H
