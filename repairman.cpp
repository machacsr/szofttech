#include "repairman.h"

Repairman::Repairman(vector<Bike> *bikes, vector<Comment> *repairlist):
    bikes(bikes),
    repairlist(repairlist)
{

}

void Repairman::repairBike()
{
    int bike_id;
    string status;
    bool finder=false;
    cout << "Type a Bike ID to repair"<<endl;
    cin >> bike_id;
    for(auto &i :*bikes)
    {
        if(i.getBikeId()==bike_id)
        {
            finder=true;
            cout << "Type the new status:"<<endl;
            cin >> status;
            i.setStatus(status);
        }
    }
    if(finder==false)
    {
        cout <<"Invalid input!"<<endl;
        repairBike();
    }

}
