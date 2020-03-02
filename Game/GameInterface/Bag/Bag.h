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
        void putToBag(IItem *, int = 1);
        void takeFromBag(IItem *, int = 1);
        void takeGold(int);
        void spendGold(int);
        int getHowMuchGold();
};





#endif