#include "Unit.h"
#include "../../Utility/Constants/Constants.h"
#include "../../Utility/UtilityFunctions/CombatLog/CombatLog.h"
#include "../../Utility/UtilityFunctions/RandDouble/RandDouble.h"


Unit::Unit(float s_armor, int s_hp, int s_damage, float s_avoidChance, float s_criticalChance) : m_armor{s_armor}, m_hp{s_hp},
           m_damage{s_damage}, m_avoidChance{s_avoidChance}, m_criticalChance{s_criticalChance} {}

void Unit::hit(IUnit * target) {
    if(target->isMissing()){
        combatLog(CombatLogStages::MISS, this, target);
        return;
    }

    int damage = damageCalculating(target->getArmor());
    
    if(isCritical()){
        damage *= Constants::criticalMultiple;
        combatLog(CombatLogStages::CRITICAL, this, target, damage);
    } else {
        combatLog(CombatLogStages::HIT, this, target, damage);
    }

    target->takeDamage(damage);
}

int Unit::getHP() {
    return m_hp;
}

bool Unit::isMissing() {
    return randDouble() <= m_avoidChance;
}

bool Unit::isCritical() {
    return randDouble() <= m_criticalChance;
}

string Unit::getName() {
    return m_name;
}

float Unit::getArmor() {
    return m_armor;
}

int Unit::damageCalculating(float targetArmor){
    return m_damage * (100 - targetArmor)/100;
}

void Unit::takeDamage(int damage) {
    m_hp -= damage;
    if(m_hp < 0)
        m_hp = 0;
}