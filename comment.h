#ifndef COMMENT_H
#define COMMENT_H
#include <iostream>
#include "custom.h"
using namespace std;


class Comment
{
    static int comment_id;
    int bike_id=0;
    string comment="";
    string date="";
public:
<<<<<<< HEAD
    time_t getDate() const;

public:
    Comment(int comment_id,int bike_id,string comment,time_t date);
=======
    Comment(int bike_id,string comment,string date);
    Comment();
    Comment(int bike_id);
>>>>>>> 43c2fdb10a0fb6f21136d6a2444694480add2087
    void printComment();
    string getInfo();
};

#endif // COMMENT_H
