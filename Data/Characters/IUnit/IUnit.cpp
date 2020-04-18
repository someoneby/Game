#include "IUnit.h"
#include "../../Utility/Constants/Constants.h"
#include "../../Utility/UtilityFunctions/CombatLog/CombatLog.h"
#include "../../Utility/UtilityFunctions/RandDouble/RandDouble.h"

/*
    This is a phase of a battle when one unit hit another with
    all needed calculations.
*/
void IUnit::hit(IUnit * s_target) {
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
int IUnit::getHP() {
    return m_hp;
}


/*
    Return whether there was a hit(false) or miss(true).
*/
bool IUnit::isMissing() const{
    return randDouble() <= m_avoidChance;
}

/*
    Return whether there was a crit(true) or not(false).
*/
bool IUnit::isCritical() const{
    return randDouble() <= m_criticalChance;
}

/*
    Return name of the unit.
*/
string IUnit::getName() {
    return m_name;
}

/*
    Return armor of the unit.
*/
double IUnit::getArmor() {
    return m_armor;
}

/*
    Calculate the damage that the target will take.
*/
int IUnit::damageCalculating(IUnit* s_target){
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
double IUnit::getCritChance() {
    return m_criticalChance;
}

/*
    Return damage of the unit.
*/
int IUnit::getDamage() {
    return m_damage;
}

/*
    Return avoid chance of the unit.
*/
double IUnit::getAvoidChance() {
    return m_avoidChance;
}

IUnit::~IUnit() {}