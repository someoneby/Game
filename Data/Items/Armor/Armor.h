#ifndef GAME_ARMOR_H
#define GAME_ARMOR_H

#include "../IItem/IItem.h"

class Armor : public IItem {
    private:
        int m_armor;
        float m_avoidChance;
        int m_hp;
    public:
        Armor(int itemId, std::string name, std::string description, int armor, float avoidChance, int hp, int prise);
        int getArmor() const;
        float getAvoidChance() const;
        int getHp() const;
        void showDescription() const override;
};


#endif //GAME_ARMOR_H
