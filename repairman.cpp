#include "repairman.h"

Repairman::Repairman(vector<Bike> *bikes, vector<Comment> *c):
    bikes(bikes),
    comments(c)
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
            badbikes.push_back(i);
            cout << "Type the new status:"<<endl;
            status = getString();
            i.setStatus(status);
            i.AddComment();
        }
    }
    if(finder==false)
    {
        cout <<"Invalid input!"<<endl;
        repairBike();
    }

}

void Repairman::WriteBadBikesToFile()
{
        fstream file;
        int acc_num=0;
        file.open("repaired_bikes.txt", ios::out|ios::app);
        file<<"Datum: ";
        file<<getNow();
        file<<"\n";
        for(auto i:badbikes){
            file<<"Id: "+to_string(i->getId())+" type: "+i->getType()+ " price: "+to_string(i->getPrice())+"\n";
            for(auto al:i->getAccessory()){
                if(acc_num==0){
                    file<<"Break:\n";
                }
                if(acc_num==1){
                    file<<"Lamp:\n";
                }
                if(acc_num==2){
                    file<<"Steering Wheel:\n";
                }
                if(acc_num==3){
                    file<<"Wheel:\n";
                }
                file<<"Id: "+to_string(al->getId())+" type: "+al->getType()+ " maker: "+(al->getMaker())+"\n";

                acc_num++;
            }
            acc_num=0;
            file<<"---------------------------\n";
        }
        file.close();
}

void Repairman::WriteCommentsToFile()
{
    fstream file;
    file.open("_comments.txt");
    if(file.is_open()){
        for(auto i:*comments){
            file<<i.getInfo();
            file<<"\n";
            file<<"---------------------\n";
        }
    }else{
        cout<<"FATAL ERROR! _comments.txt file is missing."<<endl;
        return;
    }
    file.close();
}
