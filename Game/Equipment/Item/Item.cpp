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