#include "bike.h"

void Bike::Need_to_Repair()
{
    need_to_repair = 1;
}

void Bike::Repair()
{
    need_to_repair = 0;
}

//bool Bike::Reservable(int start, int end)
//{
//    return res_infos->Reservable(start,end);
//}

//void Bike::Reserving(int start, int end, const string name)
//{
//    res_infos.Reserving(start,end,name);
//}

//void Bike::ListCalendar() const
//{
//    res_infos.ListCalendar();
//}

//void Bike::AddComment(const string comment)
//{
//    res_infos.AddComment(comment);
//}

//void Bike::ListComments() const
//{
//    res_infos.ListComments();
//}



void Bike::setPrize(int value)
{
    prize = value;
}

string Bike::getType()
{
    return type;
}

Reservation *Bike::getReservation()
{
    return res_infos;
}

void Bike::SetReservation(Reservation* r)
{
    res_infos=r;
}

Bike::Bike(string _type, string _color, int _prize):
    type(_type),
    color(_color),
    prize(_prize)
{
    need_to_repair = 0;
    res_infos=nullptr;
}

void Bike::PrintBike() const
{
    cout << type << ", " << color << ", " << prize;
    if(need_to_repair==0)
    {
        cout << ", Don't need to be repaired!" << endl;
    }
    else
    {
        cout << ", Need to be repaired!" << endl;
    }
}


