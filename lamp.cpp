#include "lamp.h"

Lamp::Lamp(string m, string t, int i):
    Accessory(m,t,i,true)
{

}

void Lamp::Initialize()
{
    string f;
    string ty,ma;
    ifstream lampf("lamp.txt");
    int linenumber=0;
    if(lampf.is_open()){
        while(!lampf.eof()){
            linenumber++;
            getline(lampf,ty);

        }
        lampf.close();
        lampf.open("lamp.txt");
        int line=RandomNumber(linenumber);
        linenumber=0;
        while(!lampf.eof()){

            if(line==linenumber){
               lampf>>ma>>ty;
               break;
            }
            getline(lampf,f);
            linenumber++;
        }
    }else{
        cout<<"FATAL ERROR, lamp.txt file is not openable"<<endl;
    }
    lampf.close();
    this->setMaker(ma);
    this->setType(ty);
}

Lamp::Lamp()
{

}
