#ifndef GAME_ARMOR_H
#define GAME_ARMOR_H

#include "../IEquipment/IEquipment.h"

class Armor : public IEquipment{
protected:
    float armor;
    float avoidChance;
    float hp;
};


#endif //GAME_ARMOR_H
