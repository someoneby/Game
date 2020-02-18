#ifndef GAME_EQUIPMENT_H
#define GAME_EQUIPMENT_H

#include "../IEquipment/IEquipment.h"
#include "../../Utility/Constans/TypesOfEquip.h"

class Equipment : public IEquipment{
protected:
    TypeOfEquip type;
    float armor {0};
    float avoidChance {0};
    float hp {0};
    int damage {0};
    float criticalChance {0};
};


#endif //GAME_EQUIPMENT_H
