#include "Bag.h"
#include "../../Utility/AllItems/AllItems.h"

Bag::Bag() {
    m_bag = getAllItems();
    m_gold = 0;
}

void Bag::show() {
    for(int i = 0; i < m_bag.size(); ++i){
        //Skip if count = 0
        if(m_bag.at(i)->getCount == 0)
            continue;

        m_bag.at(i)->showFromBag();
    }
}

void Bag::putToBag(int  s_id, int s_number) {
    m_bag.at(s_id)->increaseCount(s_number);
}

void Bag::takeFromBag(int s_id, int s_number) {
    m_bag.at(s_id)->reduceCount(s_number);
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