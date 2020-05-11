#include "MobFactory.h"
#include "../../Utility/UtilityFunctions/RandDouble/RandDouble.h"
#include "../Utility/ParametersDB/ParametersDB.h"
#include "../Utility/Parameters/Parameters.h"

/*
    Creating a mob with parameters based on a taken level of the depth.
*/
Mob* MobFactory::getMob(const int s_depthLevel) noexcept {
    //Getting random index of mob
    int randMob = (int)(randDouble() * 10) % ParametersDB::getMobsNumber();

    Parameters param {ParametersDB::getParam(randMob)};

    //Get multiplier based on a level of depth
    double multiplier = 1 + s_depthLevel/10;

    return new Mob(param.m_hp * multiplier,
                   param.m_armor * multiplier, 
                   param.m_avoidChance,
                   param.m_damage * multiplier,
                   param.m_critChance,
                   param.m_name);
}
