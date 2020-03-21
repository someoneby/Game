#include "Bag.h"
#include "../../Utility/AllItemsDB/AllItemsDB.h"


Bag* Bag::m_instance = new Bag();

Bag::Bag() : m_gold{0} {}

void Bag::show() {
    std::cout << " Gold: " << m_instance->m_gold << "\n";

    for(int i {0}; i < m_instance->m_bag.size(); ++i) {
        std::cout << " " << i+1 << ". " << AllItemsDB::getItemByID(m_instance->m_bag.at(i)->getId())->getName();
        // if instances more then 1
        if( m_instance->m_bag.at(i)->getCount() > 1 )
            std::cout << ": " << m_instance->m_bag.at(i)->getCount();
        std::cout << "\n";
    }
}

void Bag::putToBag(int  s_id, int s_number) {
    for(int i = 0; i < m_instance->m_bag.size(); ++i) {
        //IF ITEM EXISTS
        if(m_instance->m_bag.at(i)->getId() == s_id) {
            m_instance->m_bag.at(i)->changeCount(s_number);
            return;
        }
    }
    // IF ITEM DOESN`T EXISTS
    m_instance->m_bag.push_back(new ItemInTheBag(s_id, s_number));
}

void Bag::takeFromBag(int s_id, int s_number) {
    //Search item
    for(int i{0}; i < m_instance->m_bag.size(); ++i) {
        if(m_instance->m_bag.at(i)->getId() == s_id) {
            //Change count of items
            m_instance->m_bag.at(i)->changeCount(-s_number);
            //If items is over
            if(m_instance->m_bag.at(i)->getCount() == 0) {
                delete m_instance->m_bag.at(i);
                m_instance->m_bag.erase(m_instance->m_bag.begin() + i, m_instance->m_bag.begin() + i + 1);
            }
        }
    }
}

void Bag::takeGold(int s_gold) {
    m_instance->m_gold += s_gold;
}

void Bag::spendGold(int s_gold) {
    m_instance->m_gold -= s_gold;
}

int Bag::getHowManyGold() {
    return m_instance->m_gold;
}

int Bag::getCounterById(int s_id) {
    for(int i{0}; i < m_instance->m_bag.size(); ++i){
        if(m_instance->m_bag.at(i)->getId() == s_id)
            return m_instance->m_bag.at(i)->getCount();
    }
    return 0;
}

int Bag::getBagSize() {
    return m_instance->m_bag.size();
}

ItemInTheBag* Bag::getItemFromBag(int s_position) {
    return m_instance->m_bag.at(s_position);
}