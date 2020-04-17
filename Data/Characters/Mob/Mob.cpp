#include "Mob.h"
#include "../Utility/ParametersDB/ParametersDB.h"
#include "../Utility/Parameters/Parameters.h"

Mob::Mob(const int s_hp, const double s_armor, const double s_avoidChance, const int s_damage,
         const double s_critChance, const string s_name) {
        m_hp = s_hp;
        m_armor = s_armor;
        m_avoidChance = s_avoidChance;
        m_damage = s_damage;
        m_criticalChance = s_critChance;
        m_name = s_name;
}