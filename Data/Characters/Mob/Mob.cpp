#include "Mob.h"
#include "../Utility/ParametersDB/ParametersDB.h"
#include "../Utility/Parameters/Parameters.h"

Mob::Mob(const int s_hp, const float s_armor, const float s_avoidChance, const int s_damage,
         const float s_critChance, const string& s_name) : 
         IUnit(s_hp, s_armor, s_avoidChance, s_damage, s_critChance, s_name) 
{}