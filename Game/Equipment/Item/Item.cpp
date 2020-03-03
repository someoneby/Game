#include "Item.h"

void Item::reduceCount(int s_number) {
    m_count -= s_number;
}

void Item::increaseCount(int s_number) {
    m_count += s_number;
}

int Item::getCount() {
    return m_count;
}

int Item::getId() {
    return m_id;
}

std::string Item::getName() {
    return m_name;
}

void Item::showFromBag() {
    std::cout << 
}

Item::Item(int s_id, std::string s_name) : m_id {s_id}, m_name{s_name} {};