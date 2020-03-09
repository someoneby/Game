#include "LocationsMenu.h"
#include "../../Locations/Vendor/Vendor.h"
#include <iostream>
using std::cout;
using std::cin;


void LocationsMenu::showLocations() {
    system("clear");
    int choise;

    while(choise != 3) {
        cout << "\nМеню локаций: \n"
            << "1. Мастерская.\n"
            << "2. Лавка торговца.\n"
            << "3. Приключения.\n"
            << "\n\n0. Выход в главное меню.\n"
            << "Ваш выбор: ";

        cin >> choise;
        cin.clear();
        cin.ignore();

        switch (choise) {
            case 1 : {
                cout << " Мастерская. \n";
                return;
            }
            case 2 : {
                Vendor::showMenuOfVendor();
                return;
            }
            case 3 : {
                cout << " Приключения.\n";
                break;
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