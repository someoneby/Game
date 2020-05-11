#include "Armor.h"
#include "../../GameInterface/Bag/Bag.h"
#include "../../Utility/Constants/Constants.h"
#include <iostream>

Armor::Armor(const int s_id, const std::string s_name, const int s_prise, const std::string s_description, const int s_hp,
    const int s_armor, const float s_avoidChance) noexcept : 
    m_avoidChance{s_avoidChance}, m_hp{s_hp}, m_armor{s_armor}, IItem(s_id, s_name, s_prise, s_description) {
};

/*
    Show description of the item.
*/
void Armor::showDescription() const noexcept {
    std::cout << m_name << "\n\n" << m_description << "\n\n Броня: " << m_armor << "\n Шанс промаха: "
    << m_avoidChance << "\n Хп: " << m_hp;
}