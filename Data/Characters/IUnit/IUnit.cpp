#include "IUnit.h"
#include "../../Utility/Constants/Constants.h"
#include "../../Utility/UtilityFunctions/CombatLog/CombatLog.h"
#include "../../Utility/UtilityFunctions/RandDouble/RandDouble.h"


void IUnit::hit(IUnit * target) {
    if(target->isMissing()){
        combatLog(CombatLogStages::MISS, this, target);
        return;
    }

    int damage = damageCalculating(target->getArmor());
    
    if(isCritical()){
        damage *= Constants::CRITICAL_MULTIPLE;
        combatLog(CombatLogStages::CRITICAL, this, target, damage);
    } else {
        combatLog(CombatLogStages::HIT, this, target, damage);
    }

    target->takeDamage(damage);
}

int IUnit::getHP() {
    return m_hp;
}

bool IUnit::isMissing() {
    return randDouble() <= m_avoidChance;
}

bool IUnit::isCritical() {
    return randDouble() <= m_criticalChance;
}

string IUnit::getName() {
    return m_name;
}

double IUnit::getArmor() {
    return m_armor;
}

int IUnit::damageCalculating(float targetArmor){
    return m_damage * (100 - targetArmor)/100;
}

void IUnit::takeDamage(int damage) {
    m_hp -= damage;
    if(m_hp < 0)
        m_hp = 0;
}

double IUnit::getCritChance() {
    return m_criticalChance;
}

int IUnit::getDamage() {
    return m_damage;
}

double IUnit::getAvoidChance() {
    return m_avoidChance;
}

// IUnit::~IUnit() {}