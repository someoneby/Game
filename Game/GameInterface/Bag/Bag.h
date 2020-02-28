#ifndef GAME_BAH_H
#define GAME_BAH_H

#include "../../Equipment/IItem/IItem.h"
#include <vector>

class Bag {
    private:
        std::vector<IItem> bag;


    public:
        void show();
        void putToBag(IItem *);
        void takeFromBag(IItem *);
};





#endif