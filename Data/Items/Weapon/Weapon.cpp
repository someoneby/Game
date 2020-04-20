#include "Weapon.h"

Weapon::Weapon(int s_id, std::string s_name, int s_damage, float s_criticalChance, int s_prise,
               std::string s_description) : m_damage{s_damage}, m_criticalChance{s_criticalChance} {
               m_id = s_id;
               m_name = s_name;
               m_description = s_description;
               m_prise = s_prise;
}

/*
    Show description of the item.
*/
void Weapon::showDescription() const {
        std::cout <<m_name << "\n\n" << m_description << "\n\n Урон: " << m_damage << "\n Шанс крита: "
         << m_criticalChance;
}

/*
    Return damage gained from the weapon.
*/
int Weapon::getDamage() const {
    return m_damage;
}

/*
    Return critical chance gained from the weapon.
*/
float Weapon::getCriticalChance() const {
    return m_criticalChance;
}