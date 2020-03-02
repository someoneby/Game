#include "Bag.h"

void Bag::show() {

}

void Bag::putToBag(IItem * s_item, int s_number) {

}

void Bag::takeFromBag(IItem * s_item, int s_number) {
    for(int i = 0; )
}

void Bag::takeGold(int s_gold) {
    m_gold += s_gold;
}

void Bag::spendGold(int s_gold) {
    m_gold -= s_gold;
}

int Bag::getHowMuchGold() {
    return m_gold;
}