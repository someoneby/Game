#ifndef GAME_IUNIT_H
#define GAME_IUNIT_H

#include <iostream>
using std::string;

class IUnit {
    protected:
        double m_armor;
        int m_hp;
        int m_damage;
        double m_avoidChance;
        double m_criticalChance;
        string m_name;
    public:
        virtual void hit(IUnit* target);
        virtual bool isMissing() const;
        virtual bool isCritical() const;
        virtual void takeDamage(const int damage);
        virtual int damageCalculating(IUnit* target);
        virtual int getHP();
        virtual string getName();
        virtual double getArmor();
        virtual int getDamage();
        virtual double getAvoidChance();
        virtual double getCritChance();
        virtual ~IUnit() = 0;
};


#endif //GAME_IUNIT_H
