#include "Armor.h"
#include "../../GameInterface/Bag/Bag.h"
#include "../../Utility/Constants/Constants.h"
#include <iostream>

Armor::Armor(int s_id, std::string s_name, std::string s_description, int s_armor, float s_avoidChance,
             int s_hp, int s_prise) : m_avoidChance{s_avoidChance}, m_hp{s_hp}, m_armor{s_armor} {
             m_id = s_id;
             m_name = s_name;
             m_description = s_description;
             m_prise = s_prise;
};

/*
    Show description of the item.
*/
void Armor::showDescription() const {
        std::cout <<m_name << "\n\n" << m_description << "\n\n Броня: " << m_armor << "\n Шанс промаха: "
         << m_avoidChance << "\n Хп: " << m_hp;
}

/*
    Return armor gained from the item.
*/
int Armor::getArmor() const {
        return m_armor;
}

/*
    Return avoid chance gained from the item.
*/
float Armor::getAvoidChance() const {
        return m_avoidChance;
}

/*
    Return hp gained from the item.
*/
int Armor::getHp() const {
        return m_hp;
}