
#include <iostream>
#include <vector>
#include "bike.h"
#include "employee.h"
#include "owner.h"
#include "admin.h"
#include "repairman.h"
#include "operator.h"
using namespace std;
void MainMenu(){
    cout<<"1. Admin"<<endl;
    cout<<"2. Repairman"<<endl;
    cout<<"3. Operator"<<endl;
    cout<<"4. Owner"<<endl;
    cout<<"5. Exit"<<endl;
}
void SubMenu_Operator(){
    cout<<"1. Add Reservation"<<endl;
    cout<<"2. Search Reservation"<<endl;
    cout<<"3. Edit Reservation"<<endl;
    cout<<"4. Delete Reservation"<<endl;
    cout<<"5. Exit"<<endl;
}
int getBikeIndex(string type, vector<Bike*> b){
    for(int i=0;i<b.size();i++){
        if(b[i]->getType()==type){
            return i;
        }
    }
}

int main()
{
    bool mainmenu_cycle_running=true;
    bool command_valid=true;
    //vector<Bike> bikes;
    vector<Bike*> bikes; // tároljuk pointerbe
    Operator*  operat; //operator nem lehet a neve mert programozási kulcsszó
    Repairman* repairman;
    Owner*     owner;
    Admin*     admin;
    vector<Reservation*> reservations;
//  bikes.push_back(Bike("BMX","Red",1000));
//  bikes.push_back(Bike("Mountainbike","Black",1500));
//  bikes.push_back(Bike("Dirt","Green",3000));
    bikes.push_back(new Bike("BMX","Red",1000));
    bikes.push_back(new Bike("Mountainbike","Black",1500));
    bikes.push_back(new Bike("Dirt","Green",3000));
    do{
        MainMenu();
        string command="";
        int command_int=0;
        getline(cin,command);
        try{
            command_int=stoi(command);
        }catch(exception &e){
            command_valid=false;
        }
        if(command_valid)
        switch(command_int){
            case 1:
            case 2:
            case 3:
                bool sub_op_men_run=true;
                bool op_command_valid=true;
                do{
                    SubMenu_Operator();
                    string op_command="";
                    int op_command_int=0;
                    getline(cin,op_command);
                    try{
                        op_command_int=stoi(op_command);
                    }catch(exception &e){
                        op_command_valid=false;
                    }
                    if(op_command_valid)
                    switch(op_command_int){
                    case 1:
                        bool values_valid=true;
                        cout<<"Adja meg a bicikli tipusat"<<endl;
                        string type;
                        getline(cin,type);
                        int index=getBikeIndex(type,bikes);
                        int start,end;
                        string st,en,na;
                        cout<<"Adja meg a start idopontot"<<endl;
                        getline(cin,st);
                        cout<<"Adja meg a veg idopontot"<<endl;
                        getline(cin,en);
                        cout<<"Adja meg a vendeg nevet"<<endl;
                        getline(cin,na);
                        try{
                            start=stoi(st);
                            end=stoi(en);
                        }catch(exception &e){
                            values_valid=false;
                        }catch(exception &e){
                            values_valid=false;
                        }
                        if(values_valid){
                            if(bikes[index]->getReservation()==nullptr){

                            }else{
                                reservations.push_back(new Reservation(start,end,na));
                                bikes[index]->SetReservation(reservations[reservations.size()-1]);
                            }

                        }

//                    case 2:
//                    case 3:
//                    case 4:
//                    case 5:
                        sub_op_men_run=false;
                        break;

                    }
                }while(sub_op_men_run);
//            case 4:

//            case 5:
            mainmenu_cycle_running=false;
            break;

        }
    }while(mainmenu_cycle_running);
//    bool asd =bikes[1].Reservable(20,30);
//    if(asd==1)
//    {
//        cout << "reservable\n";
//    }
//    else{
//        cout << "not reservable\n";
//    }
//    bikes[1].ListCalendar();
//    bikes[1].AddComment("FASZ");
//    bikes[1].Reserving(19,23,"ASD");
//    asd =bikes[1].Reservable(20,30);
//    if(asd==1)
//    {
//        cout << "reservable\n";
//    }
//    else{
//        cout << "not reservable\n";
//    }
//    bikes[1].ListCalendar();
//    bikes[1].ListComments();



    return 0;
}
