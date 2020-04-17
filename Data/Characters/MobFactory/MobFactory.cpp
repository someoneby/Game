#include "MobFactory.h"
#include "../../Utility/UtilityFunctions/RandDouble/RandDouble.h"
#include "../Utility/ParametersDB/ParametersDB.h"
#include "../Utility/Parameters/Parameters.h"


Mob* MobFactory::getMob(const int s_level) {
    //Getting random index from 0 to 2
    int randMob = (int)(randDouble() * 10) % 3;

    Parameters param {ParametersDB::getParam(randMob)};

    //Get multiplier based on a level
    double multiplier = 1 + s_level/10;

    return new Mob(param.m_hp * multiplier,
                   param.m_armor * multiplier, 
                   param.m_avoidChance,
                   param.m_damage * multiplier,
                   param.m_critChance,
                   param.m_name);
}
