#ifndef GAME_ITEM_H
#define GAME_ITEM_H

#include "../IItem/IItem.h"

class Item : public IItem {
    private:
        int m_count = 0;
    public:
        void increaseCount(int number = 1);
        void reduceCount(int number = 1);
        int getCount();
};

#endif 