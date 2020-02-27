#include "EquipedItems.h"

EquipedItems * EquipedItems::m_instance = nullptr;
Helm * EquipedItems::m_helm = nullptr;

// Chest * EquipedItems::m_chest = nullptr;
// Weapon * EquipedItems::m_weapon = nullptr;

EquipedItems::EquipedItems() {}

EquipedItems * EquipedItems::getInstance() {
    if(m_instance == nullptr)
        m_instance = new EquipedItems();
        
    return m_instance;
}

void EquipedItems::equipHelm(Helm * s_helm) {
    if(m_helm != nullptr)
        m_helm->putToBag();
    
    s_helm->takeFromBag();
    m_helm = s_helm;
}

#include <iostream>
void EquipedItems::printHelm() {
    std::cout << "hp = " << m_helm->getHP() << "\n";
}