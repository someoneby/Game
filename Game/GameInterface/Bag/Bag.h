#ifndef GAME_BAH_H
#define GAME_BAH_H

#include "../../Equipment/IItem/IItem.h"
#include <vector>

class Bag {
    private:
        int m_gold;
        std::vector<IItem> m_bag;
    public:
        void show();
        void putToBag(IItem *, int);
        void takeFromBag(IItem *, int);
        void takeGold(int);
        void spendGold(int);
};





#endif