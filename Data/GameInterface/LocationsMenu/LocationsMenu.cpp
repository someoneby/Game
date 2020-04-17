#include "LocationsMenu.h"
#include "../../Locations/Vendor/Vendor.h"
#include "../../Locations/Workshop/Workshop.h"
#include "../../Utility/UtilityFunctions/GetChoise/GetChoise.h"
#include "../../Utility/UtilityFunctions/CheckInputWithMessage/CheckInputWithMessage.h"
#include "../../Utility/UtilityFunctions/BadInputState/BadInputState.h"
#include "../Utility/InterfaceConst.h"
#include "../Bag/Bag.h"
#include "../EquipedItems/EquipedItems.h"
#include "../../Locations/Adventures/Adventures.h"
using std::cout;
using std::cin;


void LocationsMenu::showLocations() {
    int choise {1};

    while(choise != 0) {
        checkInputWithMessage();

        //Show all locations
        cout << "\nМеню локаций: \n\n"
            << InterfaceConst::WORKSHOP << ". Мастерская.\n"
            << InterfaceConst::SHOP <<". Лавка торговца.\n"
            << InterfaceConst::ADVENTURES << ". Приключения.\n"
            << InterfaceConst::BAG << ". Сумка\n"
            << InterfaceConst::PERSON_INFO << ". Меню персонажа\n"
            << "\n" << InterfaceConst::EXIT << ". Выход в главное меню.\n"
            << "Ваш выбор: ";

        choise = getChoise();
        
        switch (choise) {
            case InterfaceConst::WORKSHOP : {
                Workshop::showItemsToCraft();
                break;
            }
            case InterfaceConst::SHOP : {
                Vendor::showMenu();
                break;
            }
            // coming soon
            case InterfaceConst::ADVENTURES : {
                Adventures::showMenu();
                break;
            }
            case InterfaceConst::BAG : {
                Bag::showMenu();
                break;
            }
            case InterfaceConst::PERSON_INFO : {
                EquipedItems::showMenu();
                break;
            }
            case InterfaceConst::EXIT : {
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