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


/*
    Show all your gold and items in the bag.
*/
void Bag::show() noexcept {
    //Show gold
    cout << "Ваша сумка:\n\n"
        << " Золото: " << m_instance->m_gold;

    //Show all items
    for(int i {0}; i < m_instance->m_bag.size(); ++i) {
        cout << "\n " << i+1 << ". " << AllItemsDB::getItemByID(m_instance->m_bag.at(i)->getId())->getName();
        // if instances more then 1 show it's number
        if( m_instance->m_bag.at(i)->getCount() > 1 )
            cout << ": " << m_instance->m_bag.at(i)->getCount();
    }
}


/*
    Show menu of the bag.
*/
void Bag::showMenu() noexcept {
    int choise {1};

    while(choise) {
        checkInputWithMessage();

        Bag::show();
        cout << "\n\n0 - выход"
            << "\nВаш выбор: ";
        
        choise = getChoise();

        //Check that choise in the pool
        if(choise > 0 && choise <= m_instance->m_bag.size()){
            // -1 because real position has "choise-1"
            itemMenu(choise-1);
        }
        else if(choise == InterfaceConst::EXIT)
            return;
        else
            badInputState();
    }
}


/*
    Shows description of the item and if it's equipment apply you to put on it.
*/
void Bag::itemMenu(const int s_itemPosition) noexcept {
    int choise {1};

    while(choise) {
        checkInputWithMessage();

        int id = m_instance->m_bag.at(s_itemPosition)->getId();

        AllItemsDB::getItemByID(id)->showDescription();

        // Check that choosen item isn't reagent
        if(id < InterfaceConst::FIRST_REAGENT_ID) {
            cout << "\n\n1. Надеть."
                << "\n0. Назад.";
        } 
        else
            cout << "\n\n0 - Назад.";

        cout << "\nВаш выбор: ";

        choise = getChoise();

        //Can`t put on reagent
        if(id >= InterfaceConst::FIRST_REAGENT_ID && choise == 1) {
            badInputState();
            continue;
        }
        
        switch (choise) {
            // Put on item and exit
            case InterfaceConst::PUT_ON :{
                EquipedItems::equip(id);
            }
            case InterfaceConst::EXIT : {
                return;
            }
            default: {
                badInputState();
                break;
            }
        }
    }
}


/*
    Put item in the bag.
*/
void Bag::putToBag(const int  s_itemId, const int s_number) noexcept {
    for(auto itemPtr{m_instance->m_bag.begin()}; itemPtr != m_instance->m_bag.end(); ++itemPtr) {
        //If item exists
        if( (*itemPtr)->getId() == s_itemId) {
            (*itemPtr)->changeCount(s_number);
            return;
        }
        // If item doesn't exists
        if((*itemPtr)->getId() > s_itemId) {
            m_instance->m_bag.insert(itemPtr, new ItemInTheBag(s_itemId, s_number));
            return;
        }
    }
    // If position is last element
    m_instance->m_bag.push_back(new ItemInTheBag(s_itemId, s_number));
}


/*
    Take item from the bag.
*/
void Bag::takeFromBag(const int s_itemId, const int s_number) noexcept {
    // Search item
    for(auto itemPtr{m_instance->m_bag.begin()}; itemPtr != m_instance->m_bag.end(); ++itemPtr) {
        if( (*itemPtr)->getId() == s_itemId) {
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


/*
    Return number of the item.
*/
int Bag::getCounterById(const int s_itemId) noexcept {
    // Search for item
    for(auto itemPtr{m_instance->m_bag.begin()}; itemPtr != m_instance->m_bag.end(); ++itemPtr) {
        if((*itemPtr)->getId() == s_itemId) {
            return (*itemPtr)->getCount();
        }
    }
    // If item doesn`t exist
    return 0;
}
