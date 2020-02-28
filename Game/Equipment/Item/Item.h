#ifndef GAME_ITEM_H
#define GAME_ITEM_H

#include "../IItem/IItem.h"

class Item : public IItem {
    private:
        int count;
    public:
        void increaseCount();
        void reduce();
};

#endif 