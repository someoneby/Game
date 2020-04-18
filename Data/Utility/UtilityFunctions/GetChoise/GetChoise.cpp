#include "GetChoise.h"
#include "iostream"
#include "../BadInputState/BadInputState.h"
using std::cin;

//Баг: исправить возможный ввод с пробелами

/*
    Take menu point from player and mark if input was incorrect.
*/
int getChoise() {
    int choise;
    cin >> choise;

    // If we have bad input we should return error code
    if(cin.fail()) 
        choise = -1;

    // Clear buffer
    cin.clear();
    cin.ignore();
    
    return choise;
}