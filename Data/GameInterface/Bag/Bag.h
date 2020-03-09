#ifndef GAME_BAH_H
#define GAME_BAH_H

#include "../../Items/Item/Item.h"
#include "../../Items/ItemInTheBag/ItemInTheBag.h"
#include <vector>

class Bag {
    private:
        static int m_gold;
        static std::vector<ItemInTheBag *> m_bag;
    public:
        static void show();
        static void putToBag(int, int = 1);
        static void takeFromBag(int, int = 1);
        static void takeGold(int);
        static void spendGold(int);
        static int getHowMuchGold();
};

#endif