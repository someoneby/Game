#ifndef GAME_EQUIPEDITEMS_H
#define GAME_EQUIPEDITEMS_H

class EquipedItems {
        int m_helmId;
        int m_chestId;
        int m_weaponId;
        static EquipedItems* m_instance;
        EquipedItems() noexcept;
        static void showItemMenu(const int) noexcept;
    public:
        static void showMenu() noexcept;
        static void equip(const int itemId) noexcept;
        static void unEquip(const int itemId) noexcept;
};

#endif