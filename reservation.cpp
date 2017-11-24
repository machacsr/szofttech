#include "reservation.h"


Reservation::Reservation()
{
    for(auto &i: calendar)
    {
        i="*";
    }
}

Reservation::Reservation(int s, int e, string name):
    start(s),
    end(e),
    name(name)
{
    for(auto &i: calendar)
    {
        i="*";
    }
}

bool Reservation::Reservable() //kitöröltem innen a start, end inteket mert tárolja az osztály(Dani)
{
    int i=(start-1);
    while(i<end)
    {
        if(calendar[i]=="*")
        {
            i++;
        }
        else
        {
            return 0;
        }
    }
    return 1;
}

void Reservation::Reserving()//kitöröltem innen a start, end inteket mert tárolja az osztaly, name? a foglalo nevét is tárolni kellene(Dani)
{
    for(int i=(start-1);i<end;i++)
    {
        if(calendar[i]=="*")
        {
            calendar[i]=name;
        }
        else
        {
            cout<<"This bike is reserved!"<<endl;
        }
    }
}

void Reservation::ListCalendar() const
{

    int j=0;
    for(int k=0;k<6;k++)
    {
        for(int i=j;i<(j+5);i++)
        {
            if(calendar[i]!="*")
            {
                cout <<"[-]";
            }
            else
            {
                cout <<"[+]";
            }

        }
        cout << endl;
        j+=5;
    }
    cout << endl;
}

void Reservation::AddComment(const string comment)
{
    comments.push_back(comment);
}

void Reservation::ListComments() const
{
    for(auto i: comments)
    {
        cout << i<<endl;;
    }
}

int Reservation::getCost() const {
    return cost;
}


