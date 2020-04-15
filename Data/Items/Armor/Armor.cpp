#include "Armor.h"
#include "../../GameInterface/Bag/Bag.h"
#include "../../Utility/Constants/Constants.h"
#include <iostream>

Armor::Armor(int s_id, std::string s_name, std::string s_description, int s_armor, float s_avoidChance, int s_hp, int s_prise) : 
        m_avoidChance{s_avoidChance}, m_hp{s_hp}, m_armor{s_armor}, Item(s_id, s_name, s_description, s_prise) {};

void Armor::showDescription() const {
        std::cout <<m_name << "\n\n" << m_description << "\n\n Броня: " << m_armor << "\n Шанс промаха: "
         << m_avoidChance << "\n Хп: " << m_hp;
}

int Armor::getArmor() const {
        return m_armor;
}

float Armor::getAvoidChance() const {
        return m_avoidChance;
}

int Armor::getHp() const {
        return m_hp;
}