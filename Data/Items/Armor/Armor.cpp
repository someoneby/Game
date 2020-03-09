#include "Armor.h"
#include "../../GameInterface/Bag/Bag.h"
#include <iostream>

Armor::Armor(int s_id, std::string s_name, std::string s_description, int s_armor, float s_avoidChance, int s_hp, int s_prise) : 
        Equipment(s_id, s_name, s_description, s_prise), m_armor{s_armor}, m_avoidChance{s_avoidChance}, m_hp{s_hp} {};

void Armor::showDescription() {
        system("clear");

        std::cout <<m_name << "\n\n" << m_description << "\n\n Броня: " << m_armor << "\n Шанс промаха: "
         << m_avoidChance << "\n Хп: " << m_hp << "\n\nСтоимость: " << m_prise << "\nМожно купить: " << Bag::getHowMuchGold()/m_prise << "\n";
}


int Armor::getArmor() {
        return m_armor;
}

float Armor::getAvoidChance() {
        return m_avoidChance;
}

int Armor::getHp() {
        return m_hp;
}