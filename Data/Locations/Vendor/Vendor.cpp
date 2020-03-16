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


std::vector<int> Vendor::m_itemsIdToBuy {1,3,4};

void Vendor::showMenuOfVendor() {
    int choise {1};

    while(choise != 0) {
        checkInputWithMessage();

        cout << "\nМеню торговца: \n\n"
            << "1. Купить.\n"
            << "2. Продать.\n"
            << "\n0. Назад.\n"
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
        for(int i{0}; i<m_itemsIdToBuy.size(); ++i){
            // Getting id
            int id {m_itemsIdToBuy.at(i)};

            cout << i+1 << ". " << AllItemsDB::getItemByID(id)->getName() << " - "
                << AllItemsDB::getItemByID(id)->getPrise() * Constants::modifierCostToBuy << "з.\n";
        }

        cout << "\n0. Назад." << "\nВаш выбор: ";

        choise = getChoise();

        // Position within the borders of the pull
        if(choise > 0 && choise <= m_itemsIdToBuy.size())
            // -1 т.к. у нас отсчёт с нуля
            showDescriptionToBuy(m_itemsIdToBuy.at(choise-1));
        // Exit
        else if (choise == 0)
            return;
        // Bad input
        else 
            badInputState();
    }
}

void Vendor::showDescriptionToBuy(int s_idToBuy) {
    int priseToBuy { AllItemsDB::getItemByID(s_idToBuy)->getPrise() * Constants::modifierCostToBuy };
    int howMuchCanBuy { Bag::getHowMuchGold() / priseToBuy };
    int number {1};

    while(number != 0) {
        checkInputWithMessage();

        // Show information about item
        AllItemsDB::getItemByID(s_idToBuy)->showDescription();
        cout << "\n\nСтоимость: " << priseToBuy << "\n"; 
        cout << "Можно купить: " << howMuchCanBuy;
        cout << "\n\nСколько купить (0 - выход): ";

        number = getChoise();

        // number within range
        if(number > 0 && number <= howMuchCanBuy) {
            Bag::spendGold(number * priseToBuy);
            Bag::putToBag(s_idToBuy, number);
            return;
        } 
        //Exit
        else if(number == 0)
            return;
        // Bad input
        else 
            badInputState();
    } 
}

void Vendor::showMenuToSell() {
    int choise {1};

    while(choise != 0) {
        checkInputWithMessage();

        // Показать все продаваемые предметы
        cout << "Ваша сумка: \n\n";
        Bag::show();
        cout << "\n0. Назад." << "\nНа продажу: ";
        
        choise = getChoise();

        // Position within the borders of the bag
        if(choise > 0 && choise <= Bag::m_bag.size()) 
            // -1 т.к. у нас отсчёт с нуля
            showDescriptionToSell(choise-1);
        // Exit
        else if (choise == 0)
            return;
        // Bad input
        else
            badInputState();
    }
}

void Vendor::showDescriptionToSell(int s_positionToSell) {
    int id {Bag::m_bag.at(s_positionToSell)->m_id};
    int number {1};
    int count {Bag::m_bag.at(s_positionToSell)->m_count};
    int prise {AllItemsDB::getItemByID(id)->getPrise()};

    while(number != 0) {
        checkInputWithMessage();

        // Show info
        AllItemsDB::getItemByID(id)->showDescription();
        cout << "\n\nСтоимость: " << prise;
        cout << "\nКоличество: " << count;
        cout << "\n\nСколько продать (0 - выход): ";

        number = getChoise();

        if(number > 0 && number <= count) {
            Bag::takeGold(number * prise);
            Bag::takeFromBag(id, number);
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



















