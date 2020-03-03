#ifndef GAME_ITEM_H
#define GAME_ITEM_H

#include "../IItem/IItem.h"
#include <iostream>

class Item : public IItem {
    private:
        std::string m_name;
        int m_count = 0;
        int m_id;
    public:
        Item(int, std::string);
        void showFromBag() override;
        int getId() override;
        std::string getName() override;
        void increaseCount(int number = 1);
        void reduceCount(int number = 1);
        int getCount();
};

#endif 