#ifndef BIKE_H
#define BIKE_H

#include <iostream>
#include <string>
#include "reservation.h"

using namespace std;
class Bike
{
    string type;
    string color;
    bool need_to_repair; // Az Operátornak úgy kell majd megírni a foglaló függvényét, hogy csak akkor legyen elérhető ha need_to_repair==0
    //Reservation res_infos;
    int prize;
    /*lehet h reservation pointer kellene tárolnunk
     * és akkor elég lenne a pointernek a metódusait meghívni, nem kellene az osztálynak letárolni a reservation osztály metódusait is
     * */
    Reservation* res_infos;
public:
    Bike(string _type, string _color, int _prize);
    void PrintBike() const; // Kiírja egy bicikli adatait. <---//De itt csak ennek az egynek írja ki az adatait, nem?(Dani)
                                                               //De igazad van, csak egy bicikli adatait írja ki javítottam a commentet.
    void Need_to_Repair(); // ezzel állítjuk be hogy javításra szorul egy bicikli.
    void Repair();          //ezzel javítjuk a bicikliket.
    void setPrize(int value);
    string getType();
    Reservation* getReservation();
    void SetReservation(Reservation * r);
//    //Reservation functions
//    bool Reservable(int start, int end);
//    void Reserving(int start, int end, const string name);
//    void ListCalendar() const;
//    void AddComment(const string comment);
//    void ListComments() const;

};

#endif // BIKE_H
