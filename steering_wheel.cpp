#include "steering_wheel.h"

Steering_Wheel::Steering_Wheel(string m, string t, int i):
    Accessory(m,t,i,true)
{

}

void Steering_Wheel::Initialize()
{
    string ty,ma;
    ifstream steer_wheel_file("steering_wheel.txt");
    int linenumber=0;
    if(steer_wheel_file.is_open()){
        while(!steer_wheel_file.eof()){
            linenumber++;
            getline(steer_wheel_file,ty);

        }
        steer_wheel_file.close();
        steer_wheel_file.open("steering_wheel.txt");
        int line=RandomNumber(linenumber);
        linenumber=0;
        string f;
        while(!steer_wheel_file.eof()){


            if(line==linenumber){
               steer_wheel_file>>ma>>ty;
               break;
            }
            getline(steer_wheel_file,f);
            linenumber++;
        }
    }else{
        cout<<"FATAL ERROR, steering_wheel.txt file is not openable"<<endl;
    }
    steer_wheel_file.close();
    this->setMaker(ma);
    this->setType(ty);
}

Steering_Wheel::Steering_Wheel()
{

}
