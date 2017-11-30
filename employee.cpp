#include "employee.h"

Employee::Employee()
{

}

Bike Employee::BikeSearch(vector<Bike > *bikes) const
{
    cout<<"Give me a type:";
    string type;
    getline(cin,type);
    for(auto i:*bikes){
        if(i.getType()==type){
            return i;
        }
    }
    cout<<"There is no such bike!!!"<<endl;
    return;
}

void Employee::BikeList(vector<Bike > *bikes) const
{
    for(auto i:*bikes){
        i.PrintBike();
    }

}

void Employee::WriteToFile(string filename, vector<Bike > *bikes)
{
    fstream file;
    file.open(filename, ios::out);
    for(auto i:*bikes){
        file<<i.getInfo();
    }
    file.close();
}
