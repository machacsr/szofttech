#include "reservation.h"

int Reservation::getRes_id() const
{
    return res_id;
}

string Reservation::getName() const
{
    return name;
}

string Reservation::getIdnumber() const
{
    return idnumber;
}

string Reservation::getDate_current() const
{
    return date_current;
}

string Reservation::getDate_from() const
{
    return date_from;
}

void Reservation::setDate_from(const string &value)
{
    date_from = value;
}

string Reservation::getDate_to() const
{
    return date_to;
}

void Reservation::setDate_to(const string &value)
{
    date_to = value;
}

vector<int> Reservation::getBike_ids() const
{
    return bike_ids;
}

void Reservation::setBike_ids(const vector<int> &value)
{
    bike_ids = value;
}

string Reservation::getComment() const
{
    return comment;
}

void Reservation::setComment(const string &value)
{
    comment = value;
}

string Reservation::getStatus() const
{
    return status;
}

void Reservation::setStatus(const string &value)
{
    status = value;
}

void Reservation::print()
{
    cout << "Reservation ID: " << res_id << " Status: " << status << endl;
    cout << "Date:  " << date_current << endl;
    cout << "Name: " << name << "       ID number: " << idnumber << endl;
    cout << "From: " << date_from;
    cout << " to: " << date_to;
    cout << endl;
    cout << "Comment: " << comment << endl;
    cout << "Bike(s): " << endl;
    for(auto bike_id: bike_ids){
        cout << "Bike ID: " << bike_id << endl;
    }
    cout << "--------------------------------------------------------------------" << endl;
}

Reservation::Reservation()
{

}

Reservation::Reservation(int res_id, string status, string name, string idnumber, string date_current, string date_from, string date_to, vector<int> bike_ids, string comment):
    res_id(res_id),
    status(status),
    name(name),
    idnumber(idnumber),
    date_current(date_current),
    date_from(date_from),
    date_to(date_to),
    bike_ids(bike_ids),
    comment(comment)
{

}
