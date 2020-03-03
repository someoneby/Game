#ifndef GAME_BAH_H
#define GAME_BAH_H

#include "../../Equipment/Item/Item.h"
#include <vector>

class Bag {
    private:
        int m_gold;
        std::vector<Item *> m_bag;
    public:
        Bag();
        void show();
        void putToBag(int, int = 1);
        void takeFromBag(int, int = 1);
        void takeGold(int);
        void spendGold(int);
        int getHowMuchGold();
};





#endif