#ifndef GAME_EQUIPMENT_H
#define GAME_EQUIPMENT_H

#include "../Item/Item.h"

class Equipment : public Item {
    private:
        float m_ilvl;
    public:
        Equipment(int, std::string);
        float getIlvl();
};


#endif //GAME_EQUIPMENT_H
