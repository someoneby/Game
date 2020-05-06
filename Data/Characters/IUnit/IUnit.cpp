#include "IUnit.h"
#include "../../Utility/Constants/Constants.h"
#include "../../Utility/UtilityFunctions/CombatLog/CombatLog.h"


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
    Changing hp of a target, if hp < 0 it will die.
*/
void IUnit::takeDamage(int s_damage) {
    m_hp -= s_damage;
    if(m_hp < 0)
        m_hp = 0;
}


IUnit::~IUnit() {}