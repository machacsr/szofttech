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
    cout << "Type a Bike ID to repair"<<endl;
    cin >> bike_id;
    cout << "Type the new status:"<<endl;
    cin >> status;
    for(auto &i :*bikes)
    {
        if(i.getBikeId()==bike_id)
        {
            i.setStatus(status);
        }
    }
}
