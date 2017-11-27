#include <iostream>
#include "mainapp.h"
using namespace std;

int main()
{
    MainApp app;
    app.loadData();
    app.runTest(); //ebben a függvényben lehet tesztelni, még mielőtt betölt a menü
    app.loadMenu();
    app.saveData();
    return 0;
}
