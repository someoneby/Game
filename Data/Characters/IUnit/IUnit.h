#ifndef GAME_IUNIT_H
#define GAME_IUNIT_H

#include "../Utility/Parameters/Parameters.h"
#include "../../Utility/UtilityFunctions/RandDouble/RandDouble.h"
#include <iostream>
using std::string;

class IUnit {
    protected:
        int m_hp;
        float m_armor;
        float m_avoidChance;
        int m_damage;
        float m_criticalChance;
        string m_name;
    public:
        IUnit(const int hp, const float armor, const float avoidChance, const int damage,
            const float critChance, const string& name);
        IUnit(const Parameters& params);
        void hit(IUnit* const target) const;
        void takeDamage(const int damage);
        virtual ~IUnit() = 0;
        
        int damageCalculating(const IUnit* const target) const { return m_damage * (100 - target->getArmor())/100; };
        bool isMissing() const { return randDouble() <= m_avoidChance; };
        bool isCritical() const { return randDouble() <= m_criticalChance; };
        int getHP() const { return m_hp; };
        string getName() const { return m_name; };
        float getArmor() const { return m_armor; };
        int getDamage() const { return m_damage; };
        float getAvoidChance() const { return m_avoidChance; };
        float getCritChance() const { return m_criticalChance; };
};


#endif //GAME_IUNIT_H
