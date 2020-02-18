#ifndef GAME_WEAPONS_H
#define GAME_WEAPON_H


#include "../IEquipment/IEquipment.h"

class Weapon : public IEquipment {
protected:
    int damage;
    float criticalChance;
};


#endif //GAME_WEAPONS_H
