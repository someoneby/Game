#ifndef GAME_EQUIPEDITEMS_H
#define GAME_EQUIPEDITEMS_H

#include "Helm.h"
#include "Chest.h"
#include "Weapon.h"

class EquipedItems {
    private:
        static EquipedItems * m_instance;
        EquipedItems();
        EquipedItems(const EquipedItems &);
        EquipedItems & operator = (EquipedItems &);

        static Helm * m_helm;
        static Chest * m_chest;
        static Weapon * m_weapon;
    public:
        static EquipedItems * getInstance();
        static Helm * getHelm();
        static Helm * equipHelm(Helm *);
        static Chest * getChest();
        static Weapon * getWeapon();
};

#endif