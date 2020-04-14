#include "Bag.h"
#include "../../Items/Utility/AllItemsDB/AllItemsDB.h"
#include "../../Utility/UtilityFunctions/GetChoise/GetChoise.h"
#include "../../Utility/UtilityFunctions/CheckInputWithMessage/CheckInputWithMessage.h"
#include "../../Utility/UtilityFunctions/BadInputState/BadInputState.h"
#include "../EquipedItems/EquipedItems.h"
#include "../Utility/InterfaceConst.h"
using std::cout;

Bag* Bag::m_instance = new Bag();

Bag::Bag() : m_gold{200} {}

void Bag::show() {
    system("clear");
    //Show gold
    cout << "Ваша сумка:\n\n"
        << " Золото: " << m_instance->m_gold;

    //Show all items
    for(int i {0}; i < m_instance->m_bag.size(); ++i) {
        cout << "\n " << i+1 << ". " << AllItemsDB::getItemByID(m_instance->m_bag.at(i)->getId())->getName();
        // if instances more then 1 show it number
        if( m_instance->m_bag.at(i)->getCount() > 1 )
            cout << ": " << m_instance->m_bag.at(i)->getCount();
    }
}

void Bag::showMenu() {
    int choise {1};

    while(choise != 0) {
        checkInputWithMessage();

        Bag::show();
        cout << "\n\n 0 - выход"
            << "\nВаш выбор: ";
        
        choise = getChoise();

        //Check that choise in the pool
        if(choise > 0 && choise <= m_instance->m_bag.size()){
            // -1 because real position has "choise-1"
            itemMenu(choise-1);
        }
        else if(choise == InterfaceConst::exit) {
            return;
        }
        else
            badInputState();
    }
}

void Bag::itemMenu(const int s_position) {
    int choise {1};

    while(choise != 0) {
        checkInputWithMessage();

        //Show description of choosen item
        AllItemsDB::getItemByID(m_instance->m_bag.at(s_position)->getId())->showDescription();

        int id = m_instance->m_bag.at(s_position)->getId();

        // Check that choosen item isn't reagent
        if(id < InterfaceConst::firstReagentId) {
            cout << "\n\n1. Надеть."
                << "\n0. Назад.";
        } else
            cout << "\n\n0 - Назад.";
        cout << "\nВаш выбор: ";

        choise = getChoise();

        if(id >= InterfaceConst::firstReagentId && choise == 1)
            badInputState();
        
        // Coming soon
        switch (choise) {
        case InterfaceConst::putOn :{
            // EquipedItems::equip(id, );
            break;
        }
        
        default:
            break;
        }

    }
}

void Bag::putToBag(const int  s_id, const int s_number) {
    //If item exists
    for(auto itemPtr{m_instance->m_bag.begin()}; itemPtr != m_instance->m_bag.end(); ++itemPtr) {
        
        if( (*itemPtr)->getId() == s_id) {
            (*itemPtr)->changeCount(s_number);
            return;
        }
    }

    // If item doesn't exists
    for(auto it{m_instance->m_bag.begin()}; it != m_instance->m_bag.end(); it++) {
        // Search position in sorted vector for item
        if((*it)->getId() > s_id) {
            m_instance->m_bag.insert(it, new ItemInTheBag(s_id, s_number));
            return;
        }
    }
    // If position is last element
    m_instance->m_bag.push_back(new ItemInTheBag(s_id, s_number));
}

void Bag::takeFromBag(const int s_id, const int s_number) {
    // Search item
    for(auto itemPtr{m_instance->m_bag.begin()}; itemPtr != m_instance->m_bag.end(); ++itemPtr) {
        if( (*itemPtr)->getId() == s_id) {
            // Change count of items
            (*itemPtr)->changeCount(-s_number);

            // If items is over
            if( (*itemPtr)->getCount() == 0) {
                delete *itemPtr;
                m_instance->m_bag.erase( itemPtr, itemPtr+1);
            }
        }
    }
}

void Bag::takeGold(const int s_gold) {
    m_instance->m_gold += s_gold;
}

void Bag::spendGold(const int s_gold) {
    m_instance->m_gold -= s_gold;
}

int Bag::getHowManyGold() {
    return m_instance->m_gold;
}

int Bag::getCounterById(const int s_id) {
    // Search for item
    for(auto itemPtr{m_instance->m_bag.begin()}; itemPtr != m_instance->m_bag.end(); ++itemPtr) {
        if((*itemPtr)->getId() == s_id) {
            return (*itemPtr)->getCount();
        }
    }
    // If item doesn`t exist
    return 0;
}

int Bag::getBagSize() {
    return m_instance->m_bag.size();
}

ItemInTheBag* Bag::getItemFromBag(const int s_position) {
    return m_instance->m_bag.at(s_position);
}