#include "EquipedItems.h"
#include "../Bag/Bag.h"
#include "../../Items/Utility/AllItemsDB/AllItemsDB.h"
#include "../../Items/Weapon/Weapon.h"
#include "../../Items/Armor/Armor.h"
#include "../../Characters/Player/Player.h"
#include "../../Utility/UtilityFunctions/GetChoise/GetChoise.h"
#include "../../Utility/UtilityFunctions/CheckInputWithMessage/CheckInputWithMessage.h"
#include "../../Utility/UtilityFunctions/BadInputState/BadInputState.h"
#include "../Utility/InterfaceConst.h"
using std::cout;

EquipedItems* EquipedItems::m_instance = new EquipedItems();

EquipedItems::EquipedItems() : m_weaponId{0}, m_chestId{0}, m_helmId{0} {};

void EquipedItems::equip (const int s_id, const TypesOfEquip s_type) {
    switch (s_type) {
        case TypesOfEquip::weapon : {
            // If the item is on
            if (m_instance->m_weaponId != 0) {
                unEquip(s_type);
            }

            // Change count of items in the bag
            Bag::takeFromBag(s_id);

            // Change player's parameters
            Player::getInstance()->changeDamage(static_cast<Weapon *>(AllItemsDB::getItemByID(s_id))->getDamage());
            Player::getInstance()->changeCriticalChance(static_cast<Weapon *>(AllItemsDB::getItemByID(s_id))->getCriticalChance());

            // Change id of equipted Weapon
            m_instance->m_weaponId = s_id;

            break;
        }
        
        case TypesOfEquip::chest : {}
        case TypesOfEquip::helm : {
            //Select target_id by type
            int target_id;
            if(s_type == TypesOfEquip::chest)
                target_id = m_instance->m_chestId;
            else
                target_id = m_instance->m_helmId;

            // If the item is on
            if (target_id != 0) {
                unEquip(s_type);
            }
     
            // Change count of items in the bag
            Bag::takeFromBag(s_id);

            // Change player's parameters
            Player::getInstance()->changeHp(static_cast<Armor *>(AllItemsDB::getItemByID(s_id))->getHp());
            Player::getInstance()->changeArmor(static_cast<Armor *>(AllItemsDB::getItemByID(s_id))->getArmor());
            Player::getInstance()->changeAvoidChance(static_cast<Armor *>(AllItemsDB::getItemByID(s_id))->getAvoidChance());  

            // Change id of equipted Armor
            if(s_type == TypesOfEquip::chest)
                m_instance->m_chestId = s_id;
            else 
                m_instance->m_helmId = s_id;

            break;          
        }
    }
}

void EquipedItems::unEquip (const TypesOfEquip s_type) {

    switch (s_type) {
            case TypesOfEquip::weapon : {
                // Change count of items in the bag
                Bag::putToBag(m_instance->m_weaponId);

                // Taking Item* from the database, cast to Weapon* and Change player's parameters
                Player::getInstance()->changeDamage(- static_cast<Weapon *>(AllItemsDB::getItemByID(m_instance->m_weaponId))->getDamage());
                Player::getInstance()->changeCriticalChance(- static_cast<Weapon *>(AllItemsDB::getItemByID(m_instance->m_weaponId))->getCriticalChance());

                // Change id of equipted Weapon
                m_instance->m_weaponId = 0;

                break;
            }
            
            case TypesOfEquip::chest : {}
            case TypesOfEquip::helm : {
                //Select target_id by type
                int target_id;
                if(s_type == TypesOfEquip::chest)
                    target_id = m_instance->m_chestId;
                else
                    target_id = m_instance->m_helmId;
                
                // Change count of items in the bag
                Bag::putToBag(target_id);

                // Taking Item* from the database, cast to Armor* and Change player's parameters
                Player::getInstance()->changeHp(- static_cast<Armor *>(AllItemsDB::getItemByID(target_id))->getHp());
                Player::getInstance()->changeArmor(- static_cast<Armor *>(AllItemsDB::getItemByID(target_id))->getArmor());
                Player::getInstance()->changeAvoidChance(- static_cast<Armor *>(AllItemsDB::getItemByID(target_id))->getAvoidChance());  

                // Change id of equipted Armor
                if(s_type == TypesOfEquip::chest)
                    m_instance->m_chestId = 0;
                else 
                    m_instance->m_helmId = 0;

                break;          
            }
        }
}

void EquipedItems::showMenu() {
        int choise {1};

    while(choise != 0) {
        checkInputWithMessage();

        //Show all items
        cout << "Меню персонажа:"
            << "\n " << InterfaceConst::helm << ". Шлем: " << AllItemsDB::getItemByID(m_instance->m_helmId)->getName()
            << "\n " << InterfaceConst::chest << ". Тело: " << AllItemsDB::getItemByID(m_instance->m_chestId)->getName()
            << "\n " << InterfaceConst::weapon << ". Оружие: " << AllItemsDB::getItemByID(m_instance->m_weaponId)->getName()
            << "\n\n " << InterfaceConst::exit << "-выход"
            << "\n Ваш выбор: ";

        choise = getChoise();

        switch(choise) {
            case InterfaceConst::helm : {
                EquipedItems::showItemMenu(m_instance->m_helmId);
                break;
            }
            case InterfaceConst::chest : {
                EquipedItems::showItemMenu(m_instance->m_chestId);
                break;
            }
            case InterfaceConst::weapon : {
                EquipedItems::showItemMenu(m_instance->m_weaponId);
                break;
            }
            case 0: {
                return;
            }
            default:
                badInputState();
                break;
        }
    }
}

void EquipedItems::showItemMenu(const int s_id) {
    int choise {1};

    while(choise != 0) {
        checkInputWithMessage();
        if(s_id != 0)
            AllItemsDB::getItemByID(s_id)->showDescription();
        else 
            cout << "Пусто";
        
        cout << "\n\n0. Выход"
            << "\nВаш выбор: ";

        choise = getChoise();

        switch(choise) {
            case InterfaceConst::exit : {
                return;
            }
            default : {
                badInputState();
                break;
            }
        }
    }
}