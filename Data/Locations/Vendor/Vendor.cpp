#include "Vendor.h"
#include <iostream>
#include "../../Items/Utility/AllItemsDB/AllItemsDB.h"
#include "../../Utility/UtilityFunctions/GetChoise/GetChoise.h"
#include "../../GameInterface/Bag/Bag.h"
#include "../../Utility/UtilityFunctions/CheckInputWithMessage/CheckInputWithMessage.h"
#include "../../Utility/UtilityFunctions/BadInputState/BadInputState.h"
#include "../Utility/LocationConstants.h"
using std::cout;
using std::cin;


Vendor* Vendor::m_instance {new Vendor()};

Vendor::Vendor() : m_itemsIdToBuy{
        1,  //Кастрюля дырявая
        2,  //Кастрюля картавая
        4,  //Каска деда-электрика
        6,  //Памперс мумии
        8,  //Красный кляп

        31, //Рваный мешок от картошки
        32, //Цельный мешок от картошки
        34, //Бушлат
        37, //Бронелифчик

        61  //Test
    } {};

/*
    This is main menu of all location
*/
void Vendor::showMenu() {
    int choise {1};

    while(choise != LocationConstants::EXIT) {
        checkInputWithMessage();

        cout << "\nМеню торговца: \n\n"
            << LocationConstants::MENU_TO_BUY << ". Купить.\n"
            << LocationConstants::MENU_TO_SELL << ". Продать.\n"
            << "\n" << LocationConstants::EXIT << ". Назад.\n"
            << "Ваш выбор: ";

        choise = getChoise();

        switch (choise) {
            case LocationConstants::MENU_TO_BUY : {
                showMenuToBuy();
                break;
            }
            case LocationConstants::MENU_TO_SELL : {
                showMenuToSell();
                break;
            }
            case LocationConstants::EXIT : {
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

    while(choise != LocationConstants::EXIT) {
        checkInputWithMessage();

        cout << "Товары для покупки: \n\n";
        
        // Show all items to buy
        for(int i{0}; i<m_instance->m_itemsIdToBuy.size(); ++i){
            //Printing type of item for better navigation
            if(m_instance->m_itemsIdToBuy.at(i) == LocationConstants::FIRST_HELM_ID_TO_BUY)
                cout << "Шлемы:\n";
            else if(m_instance->m_itemsIdToBuy.at(i) == LocationConstants::FIRST_CHEST_ID_TO_BUY)
                cout << "\nБроня на тело:\n";
            else if(m_instance->m_itemsIdToBuy.at(i) == LocationConstants::FIRST_WEAPON_ID_TO_BUY)
                cout << "\nОружия:\n";

            int id {m_instance->m_itemsIdToBuy.at(i)};

            //Printing position, name and cost tu buy
            cout << i+1 << ". " << AllItemsDB::getItemByID(id)->getName() << " - "
                //Prise of item to buy = prise of item to sale * 10
                << AllItemsDB::getItemByID(id)->getPrise() * LocationConstants::modifierCostToBuy << "з.\n";
        }
        cout << "\n" << LocationConstants::EXIT << ". Назад." << "\nВаш выбор: ";

        choise = getChoise();

        // Position within the pull
        if(choise > 0 && choise <= m_instance->m_itemsIdToBuy.size()) {
            // -1 because real position "choise-1"
            showDescriptionToBuy(m_instance->m_itemsIdToBuy.at(choise-1));
        }
        else if (choise == LocationConstants::EXIT) {
            return;
        }
        // Bad input
        else  {
            badInputState();
        }
    }
}

/*
    Show description of the choosen item
*/
void Vendor::showDescriptionToBuy(const int s_idToBuy) {
    const int priseToBuy { AllItemsDB::getItemByID(s_idToBuy)->getPrise() * LocationConstants::modifierCostToBuy };
    const int howMuchCanBuy { Bag::getGold() / priseToBuy };
    int numberToBuy {1};

    while(numberToBuy != LocationConstants::EXIT) {
        checkInputWithMessage();

        // Show information about item
        AllItemsDB::getItemByID(s_idToBuy)->showDescription();
        cout << "\n\nСтоимость: " << priseToBuy << "\n"; 
        cout << "Можно купить: " << howMuchCanBuy;
        cout << "\n\nСколько купить (" << LocationConstants::EXIT <<"-выход): ";

        numberToBuy = getChoise();

        // number within range
        if(numberToBuy > 0 && numberToBuy <= howMuchCanBuy) {
            Bag::spendGold(numberToBuy * priseToBuy);
            Bag::putToBag(s_idToBuy, numberToBuy);
            return;
        } 
        else if(numberToBuy == LocationConstants::EXIT) {
            return;
        }
        // Bad input
        else 
            badInputState();
    } 
}

void Vendor::showMenuToSell() {
    int choise {1};

    while(choise != LocationConstants::EXIT) {
        checkInputWithMessage();

        // Show all your's items
        cout << "Ваша сумка: \n\n";
        Bag::show();
        cout << "\n\n" << LocationConstants::EXIT << ". Назад." << "\nНа продажу: ";
        
        choise = getChoise();

        // Position within the borders of the bag
        if(choise > 0 && choise <= Bag::getBagSize()) {
            // -1 because real position "shoise-1"
            showDescriptionToSell(choise-1);
        }
        else if (choise == LocationConstants::EXIT) {
            return;
        }
        // Bad input
        else
            badInputState();
    }
}

/*
    Show description of the choosen item
*/
void Vendor::showDescriptionToSell(const int s_positionToSell) {
    const int id {Bag::getItemFromBag(s_positionToSell)->getId()};
    const int count {Bag::getItemFromBag(s_positionToSell)->getCount()};
    const int prise {AllItemsDB::getItemByID(id)->getPrise()};
    int numberToSell {1};

    while(numberToSell != LocationConstants::EXIT) {
        checkInputWithMessage();

        // Show info
        AllItemsDB::getItemByID(id)->showDescription();
        cout << "\n\nСтоимость: " << prise;
        cout << "\nКоличество: " << count;
        cout << "\n\nСколько продать (" << LocationConstants::EXIT << "-выход): ";

        numberToSell = getChoise();

        // number within range
        if(numberToSell > 0 && numberToSell <= count) {
            Bag::takeGold(numberToSell * prise);
            Bag::takeFromBag(id, numberToSell);
            return;
        } 
        else if(numberToSell == LocationConstants::EXIT) {
            return;
        }
        // Bad input
        else {
            badInputState();
        }
    } 
}
