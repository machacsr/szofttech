#include "custom.h"

int getInt(){
    string inputString="";
    int inputInt=0;
    while(true){ //amíg nem kapunk számot, addig próbálkozunk.
        getline(cin,inputString);
        try{
            inputInt=stoi(inputString);
            break;
        }catch(exception &e){
            cout << "Invalid input. Please enter a number: ";
        }
    }
    return inputInt;
}

string getString(){
    string inputString="";
    getline(cin,inputString);
    return inputString;
}

void pause(){
    cout << endl << endl << endl << "Press ENTER to return to menu...";
    string tmp;
    getline(cin,tmp);
}

//Visszaadja a mai napot yyyy-mm-dd formátumban:
string getToday(){
    time_t rawtime;
    struct tm * timeinfo;
    char buffer[11];
    string today;
    time (&rawtime);
    timeinfo = localtime (&rawtime);
    strftime(buffer,11,"%Y-%m-%d",timeinfo);
    today.assign(buffer, 10);
    return today;
}

//Visszaadja az aktuális időpontot yyyy-mm-dd hh:mm:ss formátumban.
string getNow(){
    time_t rawtime;
    struct tm * timeinfo;
    char buffer[20];
    string now;
    time (&rawtime);
    timeinfo = localtime (&rawtime);
    strftime(buffer,20,"%Y-%m-%d %H:%M:%S",timeinfo);
    now.assign(buffer, 19);
    return now;
}

//visszaad egy string vektort, pl. split("one:two:three", ':');
vector<string> splitString(const string &s, char delim) {
    stringstream ss(s);
    string item;
    vector<string> tokens;
    while (getline(ss, item, delim)) {
        tokens.push_back(item);
    }
    return tokens;
}

//visszaad egy int vektort, pl. split("12,16,23", ',');
vector<int> splitInt(const string &s, char delim) {
    stringstream ss(s);
    string item;
    vector<int> tokens;
    while (getline(ss, item, delim)) {
        tokens.push_back(stoi(item));
    }
    return tokens;
}

void printTitle(string title)
{
    cout << "      " << title << endl;
    cout << "----------------------------------------" << endl << endl;
}

string SplitEgymasAgyazasSeged(vector<string> SplitStr) {
    return std::string(SplitStr[0]);
}

vector<Accessory *> GenerateAccessory()
{
    vector<Accessory*> accessories;
    Accessory* _break=new Break();
    _break->Initialize();
    _break->setId(0);
    Accessory* _lamp=new Lamp();
    _lamp->Initialize();
    _lamp->setId(0);
    Accessory* _stwheel=new Steering_Wheel();
    _stwheel->Initialize();
    _stwheel->setId(0);
    Accessory* _wheel= new Wheel();
    _wheel->Initialize();
    _wheel->setId(0);
    accessories.push_back(_break);
    accessories.push_back(_lamp);
    accessories.push_back(_stwheel);
    accessories.push_back(_wheel);
    return accessories;
}


