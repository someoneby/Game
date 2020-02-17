#include "Unit.h"
#include "../../Utility/Constans/Constans.h"
#include "../../Utility/CombatLog/CombatLog.h"

void Unit::hit(IUnit * target) {
    if(target->isMissing()){
        combatLog(CombatLogStages::missing, this, target);
        return;
    }

    int damage = damageCalculating(target->getArmor());
    if(isCritical()){
        damage *= Constans::criticalMultiple;
        combatLog(CombatLogStages::critical, this, target, damage);
    } else {
        combatLog(CombatLogStages::hit, this, target, damage);
    }

    target->takeDamage(damage);
}

Unit::Unit(float s_armor, int s_hp, int s_damage, float s_avoidChance) : m_armor{s_armor}, m_hp{s_hp},
    m_damage{s_damage}, m_avoidChance{s_avoidChance} {}

int Unit::getHP() {
    return m_hp;
}

bool Unit::isMissing() {
    return false;
}

bool Unit::isCritical() {
    return false;
}

string Unit::getName() {
    return m_name;
}

void Unit::takeDamage(int damage) {
    m_hp -= damage;
    if(m_hp < 0)
        m_hp = 0;
}