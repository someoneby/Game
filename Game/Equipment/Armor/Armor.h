#ifndef GAME_ARMOR_H
#define GAME_ARMOR_H

#include "../IEquipment/IEquipment.h"

class Armor : public IEquipment{
    protected:
        int m_armor;
        float m_avoidChance;
        int m_hp;
    public:
        Armor(int, float, int);
};


#endif //GAME_ARMOR_H
