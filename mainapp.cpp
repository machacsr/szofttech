#include "mainapp.h"

MainApp::MainApp()
{
    bikes=new vector<Bike>;
    reservations=new vector<Reservation>;
    repairlist=new vector<Comment>;
    bikes->push_back(Bike(1,1000,"BMX","red","need",{nullptr}));
    bikes->push_back(Bike(2,2000,"Monti","black","don't need",{nullptr}));
    admin=new Admin(bikes);
    repairman=new Repairman(bikes,repairlist);


}

void MainApp::loadMenu(){
    int level = 0;
    int cmd = 0; //selected_item
    string menu_title;

    while(true){
        clearScreen();
        int selected = 0;
        bool valid_cmd = true;
        int i=0;
        list<string> menu;

        if(level == 0){
            menu_title = "Main menu";
            menu.push_back("Admin");     if(cmd==++i){selected=cmd;}
            menu.push_back("Repairman"); if(cmd==++i){selected=cmd;}
            menu.push_back("Operator");  if(cmd==++i){selected=cmd;}
            menu.push_back("Owner");     if(cmd==++i){selected=cmd;}
            if(!selected && selected!=cmd){valid_cmd = false;}
        }
        if(level == 1){
            menu_title = "Admin menu";
            menu.push_back("Add Bike");    if(cmd==++i) admin->testFunc();
            menu.push_back("Search Bike"); if(cmd==++i) admin->testFunc();
            menu.push_back("Edit Bikes");  if(cmd==++i) admin->setBikePrice();
            menu.push_back("Delete Bike"); if(cmd==++i) admin->testFunc();
            if((int)menu.size() < cmd){valid_cmd = false;}
        }
        if(level == 2){
            menu_title = "Repairman menu";
            menu.push_back("Repair Bike");    if(cmd==++i){this->listBikes(); repairman->repairBike();}
            menu.push_back("Search Bike"); if(cmd==++i) repairman->testFunc();
            if((int)menu.size() < cmd){valid_cmd = false;}
        }
        if(level == 3){
            menu_title = "Operator menu";
            menu.push_back("List Bikes");         if(cmd==++i) this->listBikes();
            menu.push_back("Search Reservation"); if(cmd==++i) op->searchReservation();
            menu.push_back("Add Reservation");    if(cmd==++i) op->addReservation();
            menu.push_back("Edit Reservation");   if(cmd==++i) op->editReservation();
            menu.push_back("Delete Reservation"); if(cmd==++i) op->deleteReservation();
            menu.push_back("Search Reservation"); if(cmd==++i) op->sendBikeToRepair();
            if((int)menu.size() < cmd){valid_cmd = false;}
        }
        if(level == 4){
            menu_title = "Owner menu";
            menu.push_back("Add Bike");    if(cmd==++i) owner->testFunc();
            menu.push_back("Search Bike"); if(cmd==++i) owner->testFunc();
            menu.push_back("Search Bike"); if(cmd==++i) owner->testFunc();
            menu.push_back("Search Bike"); if(cmd==++i) owner->testFunc();
            menu.push_back("Search Bike"); if(cmd==++i) owner->testFunc();
            if((int)menu.size() < cmd){valid_cmd = false;}
        }

        if(cmd>0 && valid_cmd){
            if(level == 0){
                level = selected;
                cmd = 0;
                continue;
            }
            pause();
            cmd = 0;
            continue;
        }

        //print menu:
        cout << "  " << menu_title << endl << endl;
        i = 0;
        for(auto option : menu){
            cout << "   " << ++i << ". " << option << endl;
        }
        cout << "   ---------------------" << endl;
        if(level == 0) cout << "   9. Exit program" << endl;
        else           cout << "   9. Back to main menu" << endl;

        if(valid_cmd) cout << endl << "Choose an option: ";
        else          cout << endl << "Please choose a valid option: ";

        cmd = getInt();
        if(cmd == 9){
           if(level == 0) break; // exit menu;
           level = 0; // back to main menu
           cmd = 0;
        }
    }
}

void MainApp::loadData()
{

}

void MainApp::saveData()
{

}

void MainApp::listBikes()
{
    for(auto i :*bikes)
    {
        cout <<"ID: "<<i.getBikeId()<<" Price: "<< i.getPrice()<<" Status: "<<i.getStatus()<<endl;
    }
}

void MainApp::pause(){
    cout << endl << endl << endl << "Press ENTER to return to menu...";
    string tmp;
    getline(cin,tmp);
}

int MainApp::getInt(){
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

string MainApp::getString(){
    string inputString="";
    getline(cin,inputString);
    return inputString;
}

void MainApp::clearScreen(){
    #if defined(_WIN32) //if windows
        system("cls");
    #else
        system("clear");    //if other
    #endif  //finish
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "       __@                              " << endl;
    cout << "    _`\\<,_      Bike Rental v1.0       " << endl;
    cout << "   (*)/ (*)                             " << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
}
