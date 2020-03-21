#ifndef GAME_EQUIPEDITEMS_H
#define GAME_EQUIPEDITEMS_H

#include "../../Utility/Constants/TypesOfEquip.h"

class EquipedItems {
        int m_helmId;
        int m_chestId;
        int m_weaponId;
        static EquipedItems* m_instance;
        EquipedItems();
    public:
        static void equip (int, TypesOfEquip);
        static void unEquip (TypesOfEquip);
};

#endif