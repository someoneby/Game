#ifndef GAME_WEAPONS_H
#define GAME_WEAPON_H

#include "../Equipment/Equipment.h"

class Weapon : public Equipment {
    protected:
        int m_damage;
        float m_criticalChance;
    public:
        int getDamage();
        float getCriticalChance();
};

#endif //GAME_WEAPONS_H
