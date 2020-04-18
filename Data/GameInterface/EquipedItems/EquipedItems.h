#ifndef GAME_EQUIPEDITEMS_H
#define GAME_EQUIPEDITEMS_H

class EquipedItems {
        int m_helmId;
        int m_chestId;
        int m_weaponId;
        static EquipedItems* m_instance;
        EquipedItems();
        static void showItemMenu(const int);
    public:
        static void showMenu ();
        static void equip (const int itemId);
        static void unEquip (const int itemId);
};

#endif