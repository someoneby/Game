#include "GetChoise.h"
#include "iostream"
using std::cin;

    //Баг: исправить возможный ввод с пробелами
int getChoise() {
    int choise;
    cin >> choise;

    if(cin.fail()) 
        choise = -1;

    cin.clear();
    cin.ignore();
    
    return choise;
}