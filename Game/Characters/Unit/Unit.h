#ifndef GAME_UNIT_H
#define GAME_UNIT_H


#include "../IUnit/IUnit.h"

class Unit : public IUnit {
protected:
    float m_armor;
    int m_hp;
    int m_damage;
    float m_avoidChance;
    float m_criticalChance;
    string m_name = "";
public:
    Unit(float, int, int, float, float);

    float getArmor() override;
    bool isMissing() override;
    bool isCritical() override;
    int getHP() override;
    int damageCalculating(float) override;
    void takeDamage(int) override;
    string getName() override;
    void hit(IUnit *) override;
};


#endif //GAME_UNIT_H
