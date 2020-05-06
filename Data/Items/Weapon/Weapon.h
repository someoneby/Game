#ifndef GAME_WEAPONS_H
#define GAME_WEAPON_H

#include "../IItem/IItem.h"

class Weapon : public IItem {
    private:
        int m_damage;
        float m_criticalChance;
    public:
        Weapon(const int id, const std::string name, const int damage, const float criticalChance,
            const int prise, const std::string description);
        void showDescription() const override;
        int getDamage() const { return m_damage; };
        float getCriticalChance() const { return m_criticalChance; };
};

#endif //GAME_WEAPONS_H
