#ifndef GAME_UNIT_H
#define GAME_UNIT_H

#include "../IUnit/IUnit.h"

class Unit : public IUnit {
    protected:
        double m_armor;
        int m_hp;
        int m_damage;
        double m_avoidChance;
        double m_criticalChance;
        string m_name = "";
    public:
        Unit(float, int, int, float, float);
        void hit(IUnit *) override;
        bool isMissing() override;
        bool isCritical() override;
        int damageCalculating(float) override;
        void takeDamage(int) override;
        int getHP() override;
        string getName() override;
        double getArmor() override;
        int getDamage() override;
        double getAvoidChance() override;
        double getCritChance() override;
};


#endif //GAME_UNIT_H
