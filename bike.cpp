#include "bike.h"
#include"custom.h"
int Bike::bike_id=0;
Bike::Bike(int price, string type, string color, string status, vector<Accessory *> accessories):
    price(price),
    type(type),
    color(color),
    status(status),
    accessories(accessories)
{
    bike_id++;
}

void Bike::setStatus(string status)
{
    this->status = status;
}

void Bike::setPrice(int price)
{
    this->price = price;
}

int Bike::getBikeId()
{
    return bike_id;
}

int Bike::getPrice()
{
    return price;
}

string Bike::getInfo()
{
    string str("");
    str+="Bike id:"+to_string(bike_id)+" type: "+type+" color: "+color+" price:"+to_string( price)+"\n";
    str+="\tBreak id:"+to_string(accessories[0]->getId())
            +" maker: "+accessories[0]->getMaker()+" type: "+accessories[0]->getType()+"\n";
    str+="\tLamp id:"+to_string(accessories[1]->getId())
            +" maker: "+accessories[1]->getMaker()+" type: "+accessories[1]->getType()+"\n";
    str+="\tSteering_wheel id:"+to_string(accessories[2]->getId())
            +" maker: "+accessories[2]->getMaker()+" type: "+accessories[2]->getType()+"\n";
    str+="\tWheel id:"+to_string(accessories[3]->getId())
            +" maker: "+accessories[3]->getMaker()+" type: "+accessories[3]->getType()+"\n";
    str+="Status: "+this->getStatus()+"\n";
    return str;
}

string Bike::getType()
{
    return type;
}

string Bike::getColor()
{
    return color;
}

string Bike::getStatus()
{
    for(auto acc: accessories){
        if(acc->getState()==false){
            setStatus("bad");
            return "bad";
        }
    }
    return status;
}

vector<Comment >* Bike::getComments()
{
    return comments;
}
void Bike::AddComment()
{
    comments->push_back(Comment(getBikeId()));
}

vector<Accessory*> Bike::getAccessories()
{
    return accessories;
}
Bike::Bike()
{
    Accessory acc;
    string ty,co;
    int pri;
    ifstream bikef("bike_types.txt");
    int linenumber=0;
    if(bikef.is_open()){
        while(!bikef.eof()){
            getline(bikef,ty);
            linenumber++;
        }
        bikef.close();
        bikef.open("bike_types.txt");
        int line=acc.RandomNumber(linenumber);
        linenumber=0;
        while(!bikef.eof()){
            bikef>>bike_id>>ty>>co>>pri;
            if(line==linenumber){
               bikef>>bike_id>>ty>>co>>pri;
               break;
            }
            linenumber++;
        }
    }else{
        cout<<"FATAL ERROR, bike_types.txt file is not openable"<<endl;
    }
    bikef.close();
    accessories=GenerateAccessory();
    this->setPrice(pri);
    this->setType(ty);
    this->setColor(co);
    bike_id++;
}
void Bike::PrintBike() const
{
     cout<<"Bike id:"<<bike_id<<" type: "<<type<<" color: "<<color<<" getPrice: "<<price<<endl;
     cout<<"\tBreak id:"<<accessories[0]->getId()<<" maker: "<<accessories[0]->getMaker()<<" type: "<<accessories[0]->getType()<<endl;
     cout<<"\tLamp id:"<<accessories[1]->getId()<<" maker: "<<accessories[1]->getMaker()<<" type: "<<accessories[1]->getType()<<endl;
     cout<<"\tSteering_wheel id:"<<accessories[2]->getId()<<" maker: "<<accessories[2]->getMaker()<<" type: "<<accessories[2]->getType()<<endl;
     cout<<"\tWheel id:"<<accessories[3]->getId()<<" maker: "<<accessories[3]->getMaker()<<" type: "<<accessories[3]->getType()<<endl;
     if(comments->size()!=0){
         cout<<"Comments:"<<endl;
         for(auto i:*comments){
             cout<<i.getInfo()<<endl;
         }
     }
    cout<<"Status: "<<status<<endl;
}
