#ifndef GAME_BAH_H
#define GAME_BAH_H

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
        static void itemMenu(const int itemPosition);
        static void show();
        static void putToBag(const int itemId, const int number = 1);
        static void takeFromBag(const int itemId, const int number = 1);
        static void takeGold(const int gold);
        static void spendGold(const int gold);
        static int getGold();
        static int getCounterById(const int itemId);
        static int getBagSize();
        static ItemInTheBag* getItemFromBag(const int itemPosition);
};

#endif