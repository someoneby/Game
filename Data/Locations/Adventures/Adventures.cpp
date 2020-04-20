#include "Adventures.h"
#include "../Depths/Depths.h"
#include "../Utility/LocationConstants.h"
#include "../../Utility/UtilityFunctions/GetChoise/GetChoise.h"
#include "../../Utility/UtilityFunctions/CheckInputWithMessage/CheckInputWithMessage.h"
#include "../../Utility/UtilityFunctions/BadInputState/BadInputState.h"
using std::cout;

/*
    Show list of all adventures.
*/
void Adventures::showMenu() {
    int choise {1};

    while(choise) {
        checkInputWithMessage();

        //Show menu
        cout << "Куда пойдём?\n"
            << " " << LocationConstants::FARM << ". Ферма\n"
            << " " << LocationConstants::PATROL << ". Дозор\n"
            << " " << LocationConstants::DEPTHS << ". Шахта\n"
            << "\n 0. Выход\n"
            << "Ваш выбор: ";

        choise = getChoise();

        switch(choise) {
            case LocationConstants::FARM : {

                break;
            }
            case LocationConstants::PATROL : {

                break;
            }
            case LocationConstants::DEPTHS : {
                Depths::mainMenu();
                break;
            }
            case LocationConstants::EXIT : {
                return;
            }
            default: {
                badInputState();
            }
        }
    }
}