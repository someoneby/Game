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
        static void showMenu() noexcept;
        static void itemMenu(const int itemPosition) noexcept;
        static void show() noexcept;
        static void putToBag(const int itemId, const int number = 1) noexcept;
        static void takeFromBag(const int itemId, const int number = 1) noexcept;
        static int getCounterById(const int itemId) noexcept;
        
        static void takeGold(const int gold) noexcept { m_instance->m_gold += gold; };
        static void spendGold(const int gold) noexcept { m_instance->m_gold -= gold; };
        static int getGold() noexcept { return m_instance->m_gold; };
        static int getBagSize() noexcept { return m_instance->m_bag.size(); };
        static ItemInTheBag* getItemFromBag(const int itemPosition) noexcept { return m_instance->m_bag.at(itemPosition); };
};

#endif