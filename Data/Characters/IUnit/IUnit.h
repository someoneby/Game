#ifndef GAME_IUNIT_H
#define GAME_IUNIT_H

#include "../Utility/Parameters/Parameters.h"
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
        virtual void hit(IUnit* const target) const;
        virtual inline bool isMissing() const;
        virtual inline bool isCritical() const;
        virtual void takeDamage(const int damage);
        virtual inline int damageCalculating(const IUnit* const target) const;
        virtual inline int getHP() const;
        virtual inline string getName() const;
        virtual inline float getArmor() const;
        virtual inline int getDamage() const;
        virtual inline float getAvoidChance() const;
        virtual inline float getCritChance() const { return m_criticalChance; };
        virtual ~IUnit() = 0;
};


#endif //GAME_IUNIT_H
