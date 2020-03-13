#include "Mob.h"
#include "../../Utility/Constants/Parameters.h"

Mob::Mob() : Unit(Parameters::mobArmor, Parameters::mobHP, Parameters::mobDamage,
                        Parameters::mobAvoidChance, Parameters::mobCriticalChance){
    m_name = "Анальный уничтожитель";
    // потом сделаю норм
}
