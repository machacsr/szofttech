#include <iostream>
#include "mainapp.h"
using namespace std;

int main()
{
    MainApp app;
    app.loadData();
    app.loadMenu();
    app.saveData();
    return 0;
}
