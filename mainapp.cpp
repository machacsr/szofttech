#include "mainapp.h"

MainApp::MainApp()
{
    bikes=new vector<Bike>;
    reservations=new vector<Reservation>;
//    bikes->push_back(Bike(1,1000,"BMX","red","need",{nullptr}));
//    bikes->push_back(Bike(2,2000,"Monti","black","don't need",{nullptr}));
    admin=new Admin(bikes);
    repairman=new Repairman(bikes,comments);
    op=new Operator(bikes,reservations);
    owner= new Owner(bikes, reservations, comments);
}


void MainApp::runTest()
{
    /*********    ACHTUNG!    ****************
     *
     * Itt tudtok gyorsteszteket csinálni, még mielőtt betölt a menü.
     *
     * pl:
     */
  //  cout << getToday() << endl;
  //  cout << getNow();
  //  loadReservations();
  //  saveReservations();
    //repairman->repairBike();
 //   for(auto res:*reservations)
   //     res.print();
    pause();

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
            menu.push_back("Repair Bike"); if(cmd==++i){this->listBikes(); repairman->repairBike();}
            menu.push_back("Search Bike"); if(cmd==++i) (repairman->BikeSearch(bikes)).PrintBike();
            menu.push_back("List Bike"); if(cmd==++i) repairman->BikeList(bikes);
            menu.push_back("Save Reapired Bikes to file"); if(cmd==++i) repairman->WriteBadBikesToFile();
            menu.push_back("Save Comments to file"); if(cmd==++i) repairman->WriteCommentsToFile();
            menu.push_back("Load Comments from file"); if(cmd==++i) repairman->BikeList(bikes);
            menu.push_back("Save Bikes to file"); if(cmd==++i) repairman->WriteToFile("repairman_bikes.txt",bikes);
            if((int)menu.size() < cmd){valid_cmd = false;}
        }
        if(level == 3){
            menu_title = "Operator menu";
            menu.push_back("List Reservations");  if(cmd==++i) op->listReservations();
            menu.push_back("Search Reservation"); if(cmd==++i) op->searchReservation();
            menu.push_back("Add Reservation");    if(cmd==++i) op->addReservation();
            menu.push_back("Edit Reservation");   if(cmd==++i) op->editReservation();
            menu.push_back("Delete Reservation"); if(cmd==++i) op->deleteReservation();
            menu.push_back("Search Reservation"); if(cmd==++i) op->sendBikeToRepair();
            if((int)menu.size() < cmd){valid_cmd = false;}
        }
        if(level == 4){
            menu_title = "Owner menu";
            menu.push_back("Today Income");    if(cmd==++i) owner->todayIncome();
            menu.push_back("Monthly Income"); if(cmd==++i) owner->monthlyIncome();
            menu.push_back("Show Repair List"); if(cmd==++i) owner->showRepairList();
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
    loadReservations();
}

void MainApp::loadReservations()
{
    string filename = file_location + filename_reservations;
    string line;
    Reservation tmp_res;

   // Reservation(int res_id, string status, string name, string idnumber, string date_current, string date_from, string date_to, vector<int> bike_ids, string comment)

    ifstream input(filename);
    if (input.is_open()){
        while (input.good()){
            getline(input, line);
            std::string delimiter = "\";\"";   //A határoló string: ";" (mint egy csv fájlnál)

            //kommentezni lehet ezzel a karakterrel: #
            if(line.at(0) != '#' && line.length()>0){
                line.erase(0, 1);  // első "-t töröljük
                line.erase(line.length()-1, line.length()); //utolsó "-t töröljük

                //mezők szétválasztása:
                size_t pos = 0;
                int params = 9;
                int i=0;

                string token[9] = {"", "", "", "", "", "", "", "", ""};
                while ((pos = line.find(delimiter)) != string::npos && i<=params) {
                    token[i++] = line.substr(0, pos);
                    line.erase(0, pos + delimiter.length());
                }
                token[i] = line; // last field
                //bike_id-k szétválaszztása:
                vector<int> bike_ids = splitInt(token[7], ',');
                reservations->push_back(Reservation(
                            stoi(token[0]), //res_id
                            token[1],       //status
                            token[2],       //name
                            token[3],       //idnumber
                            token[4],       //date_current
                            token[5],       //date_from
                            token[6],       //date_to
                            bike_ids,       //bike_ids
                            token[8]        //comment
                            ));
              //  ltrim(rtrim(s))
            }
        }
        input.close();
    }
}

void MainApp::saveData()
{
    saveReservations();
}

void MainApp::saveReservations()
{
    string filename = file_location + filename_reservations;

    ofstream out(filename);
    if (out.is_open())
    {
        out << "#" <<"Reservation(int res_id, string status, string name, string idnumber, string date_current, string date_from, string date_to, vector<int> bike_ids, string comment)";

        for(auto res:*reservations){
            out << endl;
            out << "\"" << res.getRes_id() << "\";";
            out << "\"" << res.getStatus() << "\";";
            out << "\"" << res.getName() << "\";";
            out << "\"" << res.getIdnumber() << "\";";
            out << "\"" << res.getDate_current() << "\";";
            out << "\"" << res.getDate_from() << "\";";
            out << "\"" << res.getDate_to() << "\";";
            out << "\"";
            //Bike id-k kiirasa:
            for(auto bike_id : res.getBike_ids()){
                out << bike_id;
                if(bike_id != res.getBike_ids().back()){
                    out << ",";
                }
            }
            out << "\";";
            out << "\"" << res.getComment() << "\"";
        }
      out.close();
    }
    else cout << "Unable to open file";
}

void MainApp::listBikes()
{
    for(auto i :*bikes)
    {
        cout <<"ID: "<<i.getBikeId()<<" Price: "<< i.getPrice()<<" Status: "<<i.getStatus()<<endl;
    }
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
