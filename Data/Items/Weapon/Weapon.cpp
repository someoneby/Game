#include "Weapon.h"

Weapon::Weapon(int s_id, std::string s_name, int s_damage, float s_criticalChance, int s_prise, std::string s_description) : 
    m_damage{s_damage}, m_criticalChance{s_criticalChance}, Item(s_id, s_name, s_description, s_prise) {}

void Weapon::showDescription() {
        std::cout <<m_name << "\n\n" << m_description << "\n\n Урон: " << m_damage << "\n Шанс крита: "
         << m_criticalChance;
}

int Weapon::getDamage() {
    return m_damage;
}

float Weapon::getCriticalChance() {
    return m_criticalChance;
}