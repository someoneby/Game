#ifndef GAME_ARMOR_H
#define GAME_ARMOR_H

#include "../IItem/IItem.h"

class Armor : public IItem {
    private:
        int m_hp;
        int m_armor;
        float m_avoidChance;
    public:
        Armor(const int itemId, const std::string name, const int prise, const std::string description, const int hp,
            const int armor, const float avoidChance);
        void showDescription() const override;
        
        float getAvoidChance() const { return m_avoidChance; };
        int getHp() const { return m_hp; };
        int getArmor() const { return m_armor; };
};


#endif //GAME_ARMOR_H
