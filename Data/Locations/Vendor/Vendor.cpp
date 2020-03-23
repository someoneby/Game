#include "Vendor.h"
#include <iostream>
#include "../../Utility/AllItemsDB/AllItemsDB.h"
#include "../../Utility/UtilityFunctions/GetChoise/GetChoise.h"
#include "../../Utility/Constants/Constants.h"
#include "../../GameInterface/Bag/Bag.h"
#include "../../Utility/UtilityFunctions/CheckInputWithMessage/CheckInputWithMessage.h"
#include "../../Utility/UtilityFunctions/BadInputState/BadInputState.h"
#include "../Utility/LocationConstants.h"
#include "../Utility/MenuChoise.h"
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

void Vendor::showMenuOfVendor() {
    int choise {1};

    while(choise != MenuChoise::exit) {
        checkInputWithMessage();

        cout << "\nМеню торговца: \n\n"
            << MenuChoise::menuToBuy << ". Купить.\n"
            << MenuChoise::menuToSell << ". Продать.\n"
            << "\n" << MenuChoise::exit << ". Назад.\n"
            << "Ваш выбор: ";

        choise = getChoise();

        switch (choise) {
            case MenuChoise::menuToBuy : {
                showMenuToBuy();
                break;
            }
            case MenuChoise::menuToSell : {
                showMenuToSell();
                break;
            }
            case MenuChoise::exit : {
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

    while(choise != MenuChoise::exit) {
        checkInputWithMessage();

        cout << "Товары для покупки: \n\n";
        
        // Show all items to buy
        for(int i{0}; i<m_instance->m_itemsIdToBuy.size(); ++i){
            if(m_instance->m_itemsIdToBuy.at(i) == LocationConstants::firstHelmIdToBuy)
                cout << "Шлемы:\n";
            else if(m_instance->m_itemsIdToBuy.at(i) == LocationConstants::firstChestIdToBuy)
                cout << "\nБроня на тело:\n";
            else if(m_instance->m_itemsIdToBuy.at(i) == LocationConstants::firstWeaponIdToBuy)
                cout << "\nОружия:\n";

            int id {m_instance->m_itemsIdToBuy.at(i)};

            cout << i+1 << ". " << AllItemsDB::getItemByID(id)->getName() << " - "
                << AllItemsDB::getItemByID(id)->getPrise() * Constants::modifierCostToBuy << "з.\n";
        }
        cout << "\n" << MenuChoise::exit << ". Назад." << "\nВаш выбор: ";

        choise = getChoise();

        // Position within the borders of the pull
        if(choise > 0 && choise <= m_instance->m_itemsIdToBuy.size())
            // -1 because real position n-1
            showDescriptionToBuy(m_instance->m_itemsIdToBuy.at(choise-1));
        // Exit
        else if (choise == MenuChoise::exit)
            return;
        // Bad input
        else 
            badInputState();
    }
}

void Vendor::showDescriptionToBuy(const int s_idToBuy) {
    const int priseToBuy { AllItemsDB::getItemByID(s_idToBuy)->getPrise() * Constants::modifierCostToBuy };
    const int howMuchCanBuy { Bag::getHowManyGold() / priseToBuy };
    int numberToBuy {1};

    while(numberToBuy != MenuChoise::exit) {
        checkInputWithMessage();

        // Show information about item
        AllItemsDB::getItemByID(s_idToBuy)->showDescription();
        cout << "\n\nСтоимость: " << priseToBuy << "\n"; 
        cout << "Можно купить: " << howMuchCanBuy;
        cout << "\n\nСколько купить (" << MenuChoise::exit <<"-выход): ";

        numberToBuy = getChoise();

        // number within range
        if(numberToBuy > 0 && numberToBuy <= howMuchCanBuy) {
            Bag::spendGold(numberToBuy * priseToBuy);
            Bag::putToBag(s_idToBuy, numberToBuy);
            return;
        } 
        //Exit
        else if(numberToBuy == MenuChoise::exit)
            return;
        // Bad input
        else 
            badInputState();
    } 
}

void Vendor::showMenuToSell() {
    int choise {1};

    while(choise != MenuChoise::exit) {
        checkInputWithMessage();

        // Show all your's items
        cout << "Ваша сумка: \n\n";
        Bag::show();
        cout << "\n" << MenuChoise::exit << ". Назад." << "\nНа продажу: ";
        
        choise = getChoise();

        // Position within the borders of the bag
        if(choise > 0 && choise <= Bag::getBagSize()) 
            // -1 because real position n-1
            showDescriptionToSell(choise-1);
        // Exit
        else if (choise == MenuChoise::exit)
            return;
        // Bad input
        else
            badInputState();
    }
}

void Vendor::showDescriptionToSell(const int s_positionToSell) {
    const int id {Bag::getItemFromBag(s_positionToSell)->getId()};
    const int count {Bag::getItemFromBag(s_positionToSell)->getCount()};
    const int prise {AllItemsDB::getItemByID(id)->getPrise()};
    int numberToSell {1};

    while(numberToSell != MenuChoise::exit) {
        checkInputWithMessage();

        // Show info
        AllItemsDB::getItemByID(id)->showDescription();
        cout << "\n\nСтоимость: " << prise;
        cout << "\nКоличество: " << count;
        cout << "\n\nСколько продать (" << MenuChoise::exit << "-выход): ";

        numberToSell = getChoise();

        // number within range
        if(numberToSell > 0 && numberToSell <= count) {
            Bag::takeGold(numberToSell * prise);
            Bag::takeFromBag(id, numberToSell);
            return;
        } 
        //Exit
        else if(numberToSell == MenuChoise::exit) {
            return;
        }
        else {
            badInputState();
        }
    } 
}



















