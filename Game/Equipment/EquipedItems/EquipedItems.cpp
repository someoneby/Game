#include "EquipedItems.h"

EquipedItems * EquipedItems::m_instance = nullptr;
Helm * EquipedItems::m_helm = nullptr;
Chest * EquipedItems::m_chest = nullptr;
Weapon * EquipedItems::m_weapon = nullptr;

EquipedItems::EquipedItems() {}

EquipedItems * EquipedItems::getInstance() {
    if(m_instance == nullptr)
        m_instance = new EquipedItems();
        
    return m_instance;
}

Helm * EquipedItems::getHelm() {
    return m_helm;
}