#ifndef GAME_ITEM_H
#define GAME_ITEM_H

#include "../IItem/IItem.h"
#include <iostream>

class Item : public IItem {
    private:
        std::string m_name;
        int m_id;
    public:
        Item(int, std::string);
        int getId() override;
        std::string getName() override;
};

#endif 