#ifndef GAME_EQUIPMENT_H
#define GAME_EQUIPMENT_H

#include "../Item/Item.h"

class Equipment : public Item {
    public:
        Equipment (int, std::string, std::string, int);
        // virtual void equip(int);
        // virtual void unequip() = 0;
};

#endif