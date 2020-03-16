#ifndef GAME_ARMOR_H
#define GAME_ARMOR_H

#include "../Item/Item.h"

class Armor : public Item{
    protected:
        int m_armor;
        float m_avoidChance;
        int m_hp;
    public:
        Armor(int, std::string, std::string, int, float, int, int);

        int getArmor();
        float getAvoidChance();
        int getHp();
        void showDescription() override;
};


#endif //GAME_ARMOR_H
