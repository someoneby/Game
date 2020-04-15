#ifndef GAME_ITEM_H
#define GAME_ITEM_H

#include "../IItem/IItem.h"
#include <iostream>

class Item : public IItem {
    protected:
        std::string m_name;
        int m_id;
        int m_prise;
        std::string m_description;
    public:
        Item(int, std::string, std::string, int);
        int getId() const override;
        std::string getName() const override;
        int getPrise() const override;
};

#endif 