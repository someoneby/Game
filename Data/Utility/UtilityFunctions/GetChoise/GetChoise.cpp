#include "GetChoise.h"
#include "iostream"
using std::cin;

//Баг: исправить возможный ввод с пробелами

/*
    Take menu point from player and mark if input was incorrect
*/

int getChoise() {
    int choise;
    cin >> choise;

    if(cin.fail()) 
        choise = -1;

    cin.clear();
    cin.ignore();
    
    return choise;
}