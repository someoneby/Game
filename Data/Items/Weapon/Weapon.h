#ifndef GAME_WEAPONS_H
#define GAME_WEAPON_H

#include "../Item/Item.h"

class Weapon : public Item {
    protected:
        int m_damage;
        float m_criticalChance;
    public:
        Weapon(int, std::string, int, float, int, std::string);
        void showDescription() override;
        int getDamage();
        float getCriticalChance();
};

#endif //GAME_WEAPONS_H
