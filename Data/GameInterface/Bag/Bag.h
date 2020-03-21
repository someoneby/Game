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
        static void show();
        static void putToBag(int, int = 1);
        static void takeFromBag(int, int = 1);
        static void takeGold(int);
        static void spendGold(int);
        // нужны ли ?
        static int getHowManyGold();
        static int getCounterById(int);
        static int getBagSize();
        static ItemInTheBag* getItemFromBag(int);
        //
};

#endif