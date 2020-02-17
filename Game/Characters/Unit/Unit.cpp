#include "Unit.h"
#include "../../Utility/Constans/Constans.h"

void Unit::hit(IUnit * mob) {
    if(mob->isMissing()){

    }

    int damage = damageCalculating(mob->getArmor());
    if(isCritical()){
        damage *= Constans::criticalMultiple;
    } else {

    }
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
