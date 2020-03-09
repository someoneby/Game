#include "MainMenu.h"
#include <iostream>
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
            << "\n\nВаш выбор: ";

        cin >> choise;
        cin.clear();
        cin.ignore();

        switch (choise) {
            case 1 : {
                cout << " Новая игра \n";
                return;
            }
            case 2 : {
                cout << " Загрузить\n";
                return;
            }
            case 0 : {
                cout << " Выход\n";
                break;
            }
            default : {
                system("clear");
                cout << " Неправильный ввод\n";
                break;
            }
        }
    }
}  