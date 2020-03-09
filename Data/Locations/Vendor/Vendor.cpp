#include "Vendor.h"
#include <iostream>
#include "../../Utility/AllItemsDB/AllItemsDB.h"
#include "../../Utility/GetChoise/GetChoise.h"
using std::cout;
using std::cin;
std::vector<int> Vendor::itemsIdToBuy {1,3,4};


void Vendor::showMenuOfVendor() {
    system("clear");
    int choise;

    while(choise != 0) {
        cout << "\nМеню торговца: \n"
            << "1. Купить.\n"
            << "2. Продать.\n"
            << "\n\n0. Назад.\n"
            << "Ваш выбор: ";

        choise = getChoise();

        switch (choise) {
            case 1 : {
                showMenuToBuy();
                return;
            }
            case 2 : {
                showMenuToSell();
                return;
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

void Vendor::showMenuToBuy() {
    system("clear");
    int choise;
    cout << "Товары для покупки: \n\n";

    for(int i{0}; i<itemsIdToBuy.size(); ++i){
        cout << i+1 << ". " << AllItemsDB::getItemByID(itemsIdToBuy.at(i))->getName() << " - "
                        << AllItemsDB::getItemByID(itemsIdToBuy.at(i))->getPrise() << "з.\n";
    }
    cout << "0. Назад." 
        << "\n\nВаш выбор: ";

    choise = getChoise();

    if(choise > 0 && choise < itemsIdToBuy.size()+1) {
        AllItemsDB::getItemByID(itemsIdToBuy.at(choise-1))->showDescription();

        cout << "\n\n1. Купить." << "\n0. Назад.\n\nВаш выбор: ";


    }
    else if (choise == 0) {
        return;
    }
    else {
        
    }

}

void Vendor::showMenuToSell() {

}





















