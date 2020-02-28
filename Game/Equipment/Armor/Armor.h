#ifndef GAME_ARMOR_H
#define GAME_ARMOR_H

#include "../Equipment/Equipment.h"

class Armor : public Equipment{
    protected:
        int m_armor;
        float m_avoidChance;
        int m_hp;
    public:
        Armor(int, float, int);
};


#endif //GAME_ARMOR_H
