#include "ItemInTheBag.h"

ItemInTheBag::ItemInTheBag(int s_id, int s_count) : m_id{s_id}, m_count{s_count} {};

int ItemInTheBag::getCount() {
    return m_count;
}

int ItemInTheBag::getId() {
    return m_id;
}

void ItemInTheBag::changeCount(int s_number) {
    m_count += s_number;
}