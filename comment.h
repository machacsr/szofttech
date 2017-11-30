#ifndef COMMENT_H
#define COMMENT_H
#include <iostream>
#include "custom.h"
using namespace std;


class Comment
{
    int comment_id;
    int bike_id;
    string comment;
    time_t date;
public:
    time_t getDate() const;

public:
    Comment(int comment_id,int bike_id,string comment,time_t date);
    void printComment();
};

#endif // COMMENT_H
