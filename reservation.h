#ifndef RESERVATION_H
#define RESERVATION_H
#include <iostream>
#include <vector>
#include "custom.h"

using namespace std;


class Reservation
{
    int res_id;
    string status;
    string name;
    string idnumber;
    string date_current;  //yyyy-mm-dd
    string date_from;
    string date_to;
    vector<int> bike_ids;
    string comment;
public:
    Reservation();
    Reservation(int res_id, string status, string name, string idnumber, string date_current, string date_from, string date_to, vector<int> bike_ids, string comment);
    int getRes_id() const;
    string getName() const;
    string getIdnumber() const;
    string getDate_current() const;
    string getDate_from() const;
    void setDate_from(const string &value);
    string getDate_to() const;
    void setDate_to(const string &value);
    vector<int> getBike_ids() const;
    void setBike_ids(const vector<int> &value);
    string getComment() const;
    void setComment(const string &value);
    string getStatus() const;
    void setStatus(const string &value);
};

#endif // RESERVATION_H
