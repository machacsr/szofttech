#include "owner.h"

Owner::Owner(vector<Bike> *bikes, vector<Reservation> *reservations, vector<Comment> *repairlist):
    bikes(bikes),
    reservations(reservations),
    repairlist(repairlist)
{

}

void Owner::todayIncome() {
    printTitle("Today Income");
    int sum = 0;
    for (auto i:*reservations) {
        vector<string> reservationDate = splitString(i.getDate_current(), ' ');
        if (getToday() == reservationDate[0]) {
            vector<int> bicajok = i.getBike_ids();
            for (auto &bicajID:bicajok) {
                for (auto &BIKE:*bikes) {
                    if (bicajID == BIKE.getBikeId()) {
                        sum += BIKE.getPrice();
                    }
                }
            }
        }
    }
    cout << sum << " ft" << endl;
}

void Owner::monthlyIncome() {
    printTitle("Monthly Income");
    int sum = 0;
    for (auto i:*reservations) {
        vector<string> reservationDate = splitString(SplitEgymasAgyazasSeged(splitString(i.getDate_current(), ' ')), '-');
        vector<string> currentDate = splitString(getToday(), '-');
        if (currentDate[0] == reservationDate[0] && currentDate[1] == reservationDate[1]) {
            vector<int> bicajok = i.getBike_ids();
            for (auto &bicajID:bicajok) {
                for (auto &BIKE:*bikes) {
                    if (bicajID == BIKE.getBikeId()) {
                        sum += BIKE.getPrice();
                    }
                }
            }
        }
    }
    cout << sum << " ft" << endl;
}

void Owner::showRepairList() {
    printTitle("Show Repair List <v0.1>");
    int sum = 0;
    printTitle("Kell valami változó ami apalján azonosítani tudom, hogy a javítás megtörtént..");
    for (auto i:*repairlist) {
    }
}
