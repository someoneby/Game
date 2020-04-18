#include "ItemInTheBag.h"

ItemInTheBag::ItemInTheBag(int s_id, int s_count) : m_id{s_id}, m_count{s_count} {};

/*
    Return number of the item.
*/
int ItemInTheBag::getCount() {
    return m_count;
}

/*
    Return id of the item.
*/
int ItemInTheBag::getId() {
    return m_id;
}

/*
    Change number of the item in the bag.
*/
void ItemInTheBag::changeCount(int s_number) {
    m_count += s_number;
}