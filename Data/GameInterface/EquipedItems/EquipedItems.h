#ifndef GAME_EQUIPEDITEMS_H
#define GAME_EQUIPEDITEMS_H

#include "../../Utility/Constans/TypesOfEquip.h"
#include "../../Items/Helm/Helm.h"
// #include "Chest.h"
// #include "Weapon.h"

class EquipedItems {
    private:
        static int m_helmId;
        static int m_chestId;
        static int m_weaponId;
    public:
        static void equip (int, TypesOfEquip);
};

#endif