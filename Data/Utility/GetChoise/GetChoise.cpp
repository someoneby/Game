#include "GetChoise.h"
#include "iostream"
using std::cin;

int getChoise() {
    int choise;
    cin >> choise;
    cin.clear();
    cin.ignore();
    return choise;
}