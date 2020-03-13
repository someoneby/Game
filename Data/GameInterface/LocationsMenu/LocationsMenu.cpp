#include "LocationsMenu.h"
#include "../../Locations/Vendor/Vendor.h"
#include "../../Utility/UtilityFunctions/GetChoise/GetChoise.h"
#include "../../Utility/UtilityFunctions/CheckInputWithMessage/CheckInputWithMessage.h"
#include "../../Utility/UtilityFunctions/BadInputState/BadInputState.h"
// #include <iostream>

using std::cout;
using std::cin;


void LocationsMenu::showLocations() {
    int choise {1};

    while(choise != 0) {
        checkInputWithMessage();

        cout << "\nМеню локаций: \n"
            << "1. Мастерская.\n"
            << "2. Лавка торговца.\n"
            << "3. Приключения.\n"
            << "\n\n0. Выход в главное меню.\n"
            << "Ваш выбор: ";

        choise = getChoise();
        
        switch (choise) {
            case 1 : {
                cout << " Мастерская. \n";
                return;
            }
            case 2 : {
                Vendor::showMenuOfVendor();
                break;
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
                badInputState();
                break;
            }
        }
    }
}