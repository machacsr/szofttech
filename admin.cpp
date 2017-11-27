#include "admin.h"

Admin::Admin(vector<Bike> *bikes):
    bikes(bikes)
{

}

void Admin::setBikePrice()
{
    int new_price;
    for(auto &i :*bikes)
    {
        cout <<"New Price:"<<endl;
        new_price = getInt();
        i.setPrice(new_price);
    }

}
