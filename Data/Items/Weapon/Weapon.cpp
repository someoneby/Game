#include "Weapon.h"

Weapon::Weapon(const int s_id, const std::string s_name, const int s_damage, const float s_criticalChance,
    const int s_prise, const std::string s_description) :
    m_damage{s_damage}, m_criticalChance{s_criticalChance}, IItem(s_id, s_name, s_prise, s_description) {
}

/*
    Show description of the item.
*/
void Weapon::showDescription() const {
        std::cout <<m_name << "\n\n" << m_description << "\n\n Урон: " << m_damage << "\n Шанс крита: "
         << m_criticalChance;
}