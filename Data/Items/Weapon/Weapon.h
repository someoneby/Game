#ifndef GAME_WEAPONS_H
#define GAME_WEAPON_H

#include "../IItem/IItem.h"

class Weapon : public IItem {
    private:
        int m_damage;
        float m_criticalChance;
    public:
        Weapon(int, std::string, int, float, int, std::string);
        void showDescription() const override;
        int getDamage() const;
        float getCriticalChance() const;
};

#endif //GAME_WEAPONS_H
