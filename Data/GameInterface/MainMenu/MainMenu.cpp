#include "MainMenu.h"
#include <iostream>
#include "../LocationsMenu/LocationsMenu.h"
using std::cout;
using std::cin;

void MainMenu::showMainMenu() {
    system("clear");
    int choise;

    while(choise != 3) {
        cout << "\nГлавное меню: \n"
            << "1. Новая игра.\n"
            << "2. Загрузить персонажа.\n"
            << "\n0. Выход.\n"
            << "Ваш выбор: ";

        cin >> choise;
        cin.clear();
        cin.ignore();

        switch (choise) {
            case 1 : {
                LocationsMenu::showLocations();
                return;
            }
            case 2 : {
                cout << " Загрузить\n";
                return;
            }
            case 0 : {
                // cout << " Выход\n";
                return;
            }
            default : {
                system("clear");
                cout << " Неправильный ввод\n";
                break;
            }
        }
    }
}  