#include "comment.h"
int Comment::comment_id=0;

Comment::Comment()
{

}

Comment::Comment(int bike_id, string comment, string date):
    bike_id(bike_id),
    comment(comment),
    date(date)
{

}

Comment::Comment(int bike_id)
{
    cout<<"What is the comment for this bike?"<<endl;
    comment=getString();
    date=getNow();
    this->bike_id=bike_id;
    comment_id++;
}

string Comment::getInfo()
{
    string str("");
    str+="Comment ID: "+to_string(comment_id)+"\n";
    str+="Bike ID: "+to_string(bike_id)+"\n";
    str+="Date: "+date+"\n";
    str+="Comment:";
    str+="\n";
    str+=comment+"\n";
    return str;
}
