#include "Item.h"

int Item::getId() {
    return m_id;
}

std::string Item::getName() {
    return m_name;
}

Item::Item(int s_id, std::string s_name) : m_id {s_id}, m_name{s_name} {};