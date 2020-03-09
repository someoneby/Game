#include "Item.h"

int Item::getId() {
    return m_id;
}

std::string Item::getName() {
    return m_name;
}

int Item::getPrise() {
    return m_prise;
}

Item::Item(int s_id, std::string s_name, std::string s_description, int s_prise) : m_id {s_id}, m_name{s_name}, m_prise{s_prise}, m_description{s_description} {};