#include "Armor.h"
#include <iostream>

Armor::Armor(int s_id, std::string s_name,int armor, float avoidChance, int hp) : 
        Equipment(s_id, s_name), m_armor{armor}, m_avoidChance{avoidChance}, m_hp{hp} {};

void Armor::show() {
        std::cout << "\t" << getName() << "\n\t ilvl: " << getIlvl() << "\n\n\t armor: " << m_armor
        << "\n\n\t avoid chanse: " << m_avoidChance << "\n\n\t hp: " << m_hp << "\n\n";
}
