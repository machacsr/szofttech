#include "break.h"

Break::Break()
{

}
Break::Break(string m, string t, int i):
    Accessory(m,t,i,true)
{

}

void Break::Initialize()
{
    string ty,ma;
    ifstream breakf("break.txt");
    int linenumber=0;
    if(breakf.is_open()){
        while(!breakf.eof()){
            linenumber++;
            getline(breakf,ty);

        }
        breakf.close();
        breakf.open("break.txt");
        int line=RandomNumber(linenumber);
        linenumber=0;
        string f;
        while(!breakf.eof()){

            if(line==linenumber){
               breakf>>ma>>ty;
               break;
            }
            getline(breakf,f);
            linenumber++;
        }
    }else{
        cout<<"FATAL ERROR, break.txt file is not openable"<<endl;
    }
    breakf.close();
    this->setMaker(ma);
    this->setType(ty);
}
