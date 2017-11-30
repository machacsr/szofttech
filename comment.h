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
    time_t getDate() const;

public:
    Comment(int comment_id,int bike_id,string comment,time_t date);
    Comment(int bike_id,string comment,string date);
    Comment();
    Comment(int bike_id);
    void printComment();
    string getInfo();
};

#endif // COMMENT_H
