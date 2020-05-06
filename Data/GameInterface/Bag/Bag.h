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
        static int getCounterById(const int itemId);
        
        static void takeGold(const int gold) { m_instance->m_gold += gold; };
        static void spendGold(const int gold) { m_instance->m_gold -= gold; };
        static int getGold() { return m_instance->m_gold; };
        static int getBagSize() { return m_instance->m_bag.size(); };
        static ItemInTheBag* getItemFromBag(const int itemPosition) { return m_instance->m_bag.at(itemPosition); };
};

#endif