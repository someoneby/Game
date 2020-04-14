#include "LocationsMenu.h"
#include "../../Locations/Vendor/Vendor.h"
#include "../../Locations/Workshop/Workshop.h"
#include "../../Utility/UtilityFunctions/GetChoise/GetChoise.h"
#include "../../Utility/UtilityFunctions/CheckInputWithMessage/CheckInputWithMessage.h"
#include "../../Utility/UtilityFunctions/BadInputState/BadInputState.h"
#include "../Utility/InterfaceConst.h"
#include "../Bag/Bag.h"
#include "../EquipedItems/EquipedItems.h"

using std::cout;
using std::cin;


void LocationsMenu::showLocations() {
    int choise {1};

    while(choise != 0) {
        checkInputWithMessage();

        cout << "\nМеню локаций: \n\n"
            << InterfaceConst::workshop << ". Мастерская.\n"
            << InterfaceConst::shop <<". Лавка торговца.\n"
            << InterfaceConst::adventures << ". Приключения.\n"
            << InterfaceConst::bag << ". Сумка\n"
            << InterfaceConst::personInfo << ". Меню персонажа\n"
            << "\n" << InterfaceConst::exit << ". Выход в главное меню.\n"
            << "Ваш выбор: ";

        choise = getChoise();
        
        switch (choise) {
            case InterfaceConst::workshop : {
                Workshop::showItemsToCraft();
                break;
            }
            case InterfaceConst::shop : {
                Vendor::showMenuOfVendor();
                break;
            }
            // coming soon
            case InterfaceConst::adventures : {
                cout << " Приключения.\n";
                break;
            }
            case InterfaceConst::bag : {
                Bag::showMenu();
                break;
            }
            case InterfaceConst::personInfo : {
                EquipedItems::showMenu();
                break;
            }
            case InterfaceConst::exit : {
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