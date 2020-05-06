#include "IUnit.h"
#include "../../Utility/Constants/Constants.h"
#include "../../Utility/UtilityFunctions/CombatLog/CombatLog.h"
#include "../../Utility/UtilityFunctions/RandDouble/RandDouble.h"


IUnit::IUnit(const int s_hp, const float s_armor, const float s_avoidChance, const int s_damage,
         const float s_critChance, const string& s_name) :
        m_hp {s_hp},
        m_armor {s_armor},
        m_avoidChance {s_avoidChance},
        m_damage {s_damage},
        m_criticalChance {s_critChance},
        m_name {s_name}
{}


IUnit::IUnit(const Parameters& s_params) : m_hp{s_params.m_hp}, m_armor{s_params.m_armor},
 m_avoidChance{s_params.m_avoidChance}, m_damage{s_params.m_damage}, m_criticalChance{s_params.m_critChance},
 m_name{s_params.m_name} 
{}


/*
    This is a phase of a battle when one unit hit another with
    all needed calculations.
*/
void IUnit::hit(IUnit* const s_target) const {
    if(s_target->isMissing()){
        combatLog(CombatLogStages::MISS, this, s_target);
        return;
    }

    int damage = damageCalculating(s_target);
    
    if(isCritical()){
        damage *= Constants::CRITICAL_MULTIPLE;
        combatLog(CombatLogStages::CRITICAL, this, s_target, damage);
    } else {
        combatLog(CombatLogStages::HIT, this, s_target, damage);
    }

    s_target->takeDamage(damage);
}

/*
    Return hp of the unit.
*/
inline int IUnit::getHP() const {
    return m_hp;
}


/*
    Return whether there was a hit(false) or miss(true).
*/
inline bool IUnit::isMissing() const {
    return randDouble() <= m_avoidChance;
}

/*
    Return whether there was a crit(true) or not(false).
*/
inline bool IUnit::isCritical() const {
    return randDouble() <= m_criticalChance;
}

/*
    Return name of the unit.
*/
inline string IUnit::getName() const {
    return m_name;
}

/*
    Return armor of the unit.
*/
inline float IUnit::getArmor() const {
    return m_armor;
}

/*
    Calculate the damage that the target will take.
*/
inline int IUnit::damageCalculating(const IUnit* const s_target) const {
    return m_damage * (100 - s_target->getArmor())/100;
}

/*
    Changing hp of a target, if hp < 0 it will die.
*/
void IUnit::takeDamage(int s_damage) {
    m_hp -= s_damage;
    if(m_hp < 0)
        m_hp = 0;
}

/*
    Return critical chance of the unit.
*/
// float IUnit::getCritChance() const {
//     return m_criticalChance;
// }

/*
    Return damage of the unit.
*/
inline int IUnit::getDamage() const {
    return m_damage;
}

/*
    Return avoid chance of the unit.
*/
inline float IUnit::getAvoidChance() const {
    return m_avoidChance;
}

IUnit::~IUnit() {}