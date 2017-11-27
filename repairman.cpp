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
    bike_id = getInt();
    for(auto &i :*bikes)
    {
        if(i.getBikeId()==bike_id)
        {
            finder=true;
            cout << "Type the new status:"<<endl;
            status = getString();
            i.setStatus(status);
        }
    }
    if(finder==false)
    {
        cout <<"Invalid input!"<<endl;
        repairBike();
    }

}
