#include "MainMenu.h"
#include <iostream>
#include "../LocationsMenu/LocationsMenu.h"
#include "../Utility/InterfaceConst.h"
#include "../../Utility/UtilityFunctions/GetChoise/GetChoise.h"
#include "../../Utility/UtilityFunctions/CheckInputWithMessage/CheckInputWithMessage.h"
#include "../../Utility/UtilityFunctions/BadInputState/BadInputState.h"
using std::cout;
using std::cin;

/*
    Main menu of the game.
*/
void MainMenu::showMainMenu() noexcept {
    int choise{1};

    while(choise) {
        checkInputWithMessage();
        
        cout << "\nГлавное меню: \n"
            << " 1. Новая игра.\n"
            << " 2. Загрузить персонажа. (в разработке)\n"
            << " 3. Настройки. (в разработке)\n"
            << "\n0. Выход.\n"
            << "Ваш выбор: ";

        choise = getChoise();

        switch (choise) {
            case InterfaceConst::NEW_GAME : {
                LocationsMenu::showLocations();
                break;
            }
            case InterfaceConst::LOAD_GAME : {
                cout << " Загрузить\n";
                break;
            }
            case InterfaceConst::EXIT : {
                // cout << " Выход\n";
                return;
            }
            default : {
                badInputState();
                break;
            }
        }
    }
}  