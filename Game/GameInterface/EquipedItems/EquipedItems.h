#ifndef GAME_EQUIPEDITEMS_H
#define GAME_EQUIPEDITEMS_H

#include "../../Equipment/Helm/Helm.h"
// #include "Chest.h"
// #include "Weapon.h"

class EquipedItems {
    private:
        static EquipedItems * m_instance;
        EquipedItems();
        EquipedItems(const EquipedItems &);
        EquipedItems & operator = (EquipedItems &);

        static Helm * m_helm;

        // static Chest * m_chest;
        // static Weapon * m_weapon;
    public:
        static EquipedItems * getInstance();

        static void equipHelm(Helm *);
        static void printHelm();
        // static void unequipHelm();
        // static Chest * getChest();
        // static Weapon * getWeapon();
};

#endif