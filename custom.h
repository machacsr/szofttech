#ifndef CUSTOM_H
#define CUSTOM_H
#include <iostream>
#include <sstream>
#include <ctime>
#include <vector>
#include"accessory.h"
#include "bike.h"

using namespace std;

int getInt();
string getString();
void pause();
string getToday();
string getNow();
vector<string> splitString(const string &s, char delim);
vector<int> splitInt(const string &s, char delim);
void printTitle(string title);
string SplitEgymasAgyazasSeged(vector<string> SplitStr);

vector<Accessory*> GenerateAccessory();

#endif // CUSTOM_H
