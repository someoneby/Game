#include "Bag.h"
#include "../../Utility/AllItemsDB/AllItemsDB.h"

int Bag::m_gold {0};
std::vector<ItemInTheBag *> Bag::m_bag;

void Bag::show() {
    std::cout << " Gold: " << m_gold << "\n";

    for(int i {0}; i < m_bag.size(); ++i) {
        std::cout << " " << i+1 << ". " << AllItemsDB::getItemByID(m_bag.at(i)->m_id)->getName();
        if( m_bag.at(i)->m_count > 1 )
            std::cout << ": " << m_bag.at(i)->m_count;
        std::cout << "\n";
    }
}

void Bag::putToBag(int  s_id, int s_number) {
    for(int i = 0; i < m_bag.size(); ++i) {
        //IF ITEM EXISTS
        if(m_bag.at(i)->m_id == s_id) {
            m_bag.at(i)->m_count += s_number;
            return;
        }
    }
    // IF ITEM DOESN`T EXISTS
    m_bag.push_back(new ItemInTheBag(s_id, s_number));
}

void Bag::takeFromBag(int s_id, int s_number) {
    //Search item
    for(int i{0}; i < m_bag.size(); ++i) {
        if(m_bag.at(i)->m_id == s_id) {
            //Change count of items
            m_bag.at(i)->m_count -= s_number;
            //If items is over
            if(m_bag.at(i)->m_count == 0) {
                delete m_bag.at(i);
                m_bag.erase(m_bag.begin() + i, m_bag.begin() + i + 1);
            }
        }
    }
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