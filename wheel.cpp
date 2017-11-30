#include "wheel.h"

Wheel::Wheel(string m, string t, int i):
    Accessory(m,t,i,true)
{

}

void Wheel::Initialize()
{
    string ty,ma;
    ifstream wheelf("wheel.txt");
    int linenumber=0;
    if(wheelf.is_open()){
        while(!wheelf.eof()){
            linenumber++;
            getline(wheelf,ty);

        }
        wheelf.close();
        wheelf.open("wheel.txt");
        int line=RandomNumber(linenumber);
        linenumber=0;
        string f;
        while(!wheelf.eof()){
            if(line==linenumber){
               wheelf>>ma>>ty;
               break;
            }
            getline(wheelf,f);
            linenumber++;
        }
    }else{
        cout<<"FATAL ERROR, wheel.txt file is not openable"<<endl;
    }
    wheelf.close();
    this->setMaker(ma);
    this->setType(ty);
}

Wheel::Wheel()
{

}
