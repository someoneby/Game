#include "Vendor.h"
#include <iostream>
#include "../../Utility/AllItemsDB/AllItemsDB.h"
#include "../../Utility/UtilityFunctions/GetChoise/GetChoise.h"
#include "../../Utility/Constants/Constants.h"
#include "../../GameInterface/Bag/Bag.h"
#include "../../Utility/UtilityFunctions/CheckInputWithMessage/CheckInputWithMessage.h"
#include "../../Utility/UtilityFunctions/BadInputState/BadInputState.h"
using std::cout;
using std::cin;


std::vector<int> Vendor::itemsIdToBuy {1,3,4};

void Vendor::showMenuOfVendor() {
    int choise {1};

    while(choise != 0) {
        checkInputWithMessage();

        cout << "\nМеню торговца: \n"
            << "1. Купить.\n"
            << "2. Продать.\n"
            << "\n\n0. Назад.\n"
            << "Ваш выбор: ";

        choise = getChoise();

        switch (choise) {
            case 1 : {
                showMenuToBuy();
                break;
            }
            case 2 : {
                showMenuToSell();
                break;
            }
            case 0 : {
                return;
            }
            default : {
                badInputState();
                break;
            }
        }
    }
}

void Vendor::showMenuToBuy() {
    int choise {1};

    while(choise != 0) {
        checkInputWithMessage();

        cout << "Товары для покупки: \n\n";

        // Показать все продаваемые предметы
        for(int i{0}; i<itemsIdToBuy.size(); ++i){
            cout << i+1 << ". " << AllItemsDB::getItemByID(itemsIdToBuy.at(i))->getName() << " - "
                << AllItemsDB::getItemByID(itemsIdToBuy.at(i))->getPrise() * Constants::modifierCostToBuy << "з.\n";
        }

        cout << "\n\n0. Назад." 
            << "\n\nВаш выбор: ";

        choise = getChoise();

        // Good input
        if(choise > 0 && choise < itemsIdToBuy.size()+1) {
            // -1 т.к. у нас отсчёт с нуля
            showDescriptionToBuy(choise-1);
        }
        // Exit
        else if (choise == 0) {
            return;
        }
        // Bad input
        else {
            badInputState();
        }
    }
}

void Vendor::showDescriptionToBuy(int s_idToBuy) {
    int priseToBuy { AllItemsDB::getItemByID(itemsIdToBuy.at(s_idToBuy))->getPrise() * Constants::modifierCostToBuy };
    int howMuchCanBuy { Bag::getHowMuchGold() / priseToBuy };
    int number {1};

    while(number != 0) {
        checkInputWithMessage();

        AllItemsDB::getItemByID(itemsIdToBuy.at(s_idToBuy))->showDescription();
        cout << "\n\nСколько купить (0 - выход): ";

        number = getChoise();

        if(number > 0 && number <= howMuchCanBuy) {
            Bag::spendGold(number * priseToBuy);
            Bag::putToBag(s_idToBuy, number);
            return;
        } 
        //Exit
        else if(number == 0) {
            return;
        }
        else {
            badInputState();
        }
    } 
}

void Vendor::showMenuToSell() {

}





















