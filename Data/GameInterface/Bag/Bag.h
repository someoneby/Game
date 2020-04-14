#ifndef GAME_BAH_H
#define GAME_BAH_H

#include "../../Items/Item/Item.h"
#include "../Utility/ItemInTheBag/ItemInTheBag.h"
#include "../../Locations/Vendor/Vendor.h"
#include <vector>

class Bag {
        Bag();
        int m_gold;
        std::vector<ItemInTheBag *> m_bag;
        static Bag* m_instance;
    public:
        static void showMenu();
        static void itemMenu(const int);
        static void show();
        static void putToBag(const int, const int = 1);
        static void takeFromBag(const int, const int = 1);
        static void takeGold(const int);
        static void spendGold(const int);
        // нужны ли ?
        static int getHowManyGold();
        static int getCounterById(const int);
        static int getBagSize();
        static ItemInTheBag* getItemFromBag(const int);
        //
};

#endif