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
#include "../../Items/Utility/ItemsConsts.h"
#include "../../Characters/Player/Player.h"
#include "../../Utility/Constants/Constants.h"
using std::cout;

EquipedItems* EquipedItems::m_instance = new EquipedItems();

EquipedItems::EquipedItems() : m_weaponId{0}, m_chestId{0}, m_helmId{0} {};

/*
    Equip item.
*/
void EquipedItems::equip (const int s_itemId) {
    // If id belongs to helms or chests
    if(s_itemId < ItemsConsts::FIRST_WEAPON_ID) {
        //Select type by id
        int target_id;
        if(s_itemId < ItemsConsts::FIRST_CHEST_ID)
            target_id = m_instance->m_helmId;
        else
            target_id = m_instance->m_chestId;

        // If the item is on
        if (target_id != 0) {
            unEquip(s_itemId);
        }
     
        // Take item from the bag
        Bag::takeFromBag(s_itemId);

        // Change player's parameters
        Armor* item {static_cast<Armor *>(AllItemsDB::getItemByID(s_itemId))};
        Player::getInstance()->changeHp(item->getHp());
        Player::getInstance()->changeArmor(item->getArmor());
        Player::getInstance()->changeAvoidChance(item->getAvoidChance());  

        // Change id of equipted Armor
        if(s_itemId < ItemsConsts::FIRST_CHEST_ID)
            m_instance->m_helmId = s_itemId;
        else 
            m_instance->m_chestId = s_itemId;
    }
    else {
        // If the weapon is on
        if (m_instance->m_weaponId != 0) {
            unEquip(s_itemId);
        }

        // Take item from the bag
        Bag::takeFromBag(s_itemId);

        // Change player's parameters
        Weapon* weapon {static_cast<Weapon *>(AllItemsDB::getItemByID(s_itemId))};
        Player::getInstance()->changeDamage(weapon->getDamage());
        Player::getInstance()->changeCriticalChance(weapon->getCriticalChance());

        // Change id of equipted Weapon
        m_instance->m_weaponId = s_itemId;
    }
}

/*
    Unequip item.
*/
void EquipedItems::unEquip (const int s_itemId) {
    if(s_itemId < ItemsConsts::FIRST_WEAPON_ID) {
        // Select type by id
        int target_id;
        if(s_itemId < ItemsConsts::FIRST_CHEST_ID)
            target_id = m_instance->m_helmId;
        else
            target_id = m_instance->m_chestId;
                
        // Put item in the bag
        Bag::putToBag(target_id);

        // Change player's parameters
        Armor* armor {static_cast<Armor *>(AllItemsDB::getItemByID(target_id))};
        Player::getInstance()->changeHp(- armor->getHp());
        Player::getInstance()->changeArmor(- armor->getArmor());
        Player::getInstance()->changeAvoidChance(- armor->getAvoidChance());  

        // Change id of equipted Armor
        if(s_itemId < ItemsConsts::FIRST_CHEST_ID)
            m_instance->m_helmId = 0;         
        else 
            m_instance->m_chestId = 0;
    }
    else { 
        // Put weapon in the bag
        Bag::putToBag(m_instance->m_weaponId);

        // Change player's parameters
        Weapon* weapon {static_cast<Weapon *>(AllItemsDB::getItemByID(m_instance->m_weaponId))};
        Player::getInstance()->changeDamage(- weapon->getDamage());
        Player::getInstance()->changeCriticalChance(- weapon->getCriticalChance());

        // Change id of equipted Weapon
        m_instance->m_weaponId = 0;       
    }
}

/*
    Show equipment of the player
*/
void EquipedItems::showMenu() {
    int choise {1};

    while(choise != 0) {
        checkInputWithMessage();

        //Show all equiped items and player's parameters
        cout << "Меню персонажа:" << "\n\nОснащение:"
            << "\n " << InterfaceConst::HELM << ". Шлем: " << AllItemsDB::getItemByID(m_instance->m_helmId)->getName()
            << "\n " << InterfaceConst::CHEST << ". Тело: " << AllItemsDB::getItemByID(m_instance->m_chestId)->getName()
            << "\n " << InterfaceConst::WEAPON << ". Оружие: " << AllItemsDB::getItemByID(m_instance->m_weaponId)->getName()
            << "\n\n" << "Характеристики:"
            << "\n " << "Хп: " << Player::getInstance()->getHP()
            << "\n " << "Броня: " << Player::getInstance()->getArmor()
            << "\n " << "Шанс уворота: " << Player::getInstance()->getAvoidChance() * Constants::FROM_PERCENT << "%"
            << "\n " << "Урон: " << Player::getInstance()->getDamage()
            << "\n " << "Шанс крита: " << Player::getInstance()->getCritChance() * Constants::FROM_PERCENT << "%"
            << "\n\n" << InterfaceConst::EXIT << "-выход"
            << "\nВаш выбор: ";

        choise = getChoise();

        switch(choise) {
            case InterfaceConst::HELM : {
                EquipedItems::showItemMenu(m_instance->m_helmId);
                break;
            }
            case InterfaceConst::CHEST : {
                EquipedItems::showItemMenu(m_instance->m_chestId);
                break;
            }
            case InterfaceConst::WEAPON : {
                EquipedItems::showItemMenu(m_instance->m_weaponId);
                break;
            }
            case InterfaceConst::EXIT : {
                return;
            }
            default:
                badInputState();
                break;
        }
    }
}

/*
    Show description of the item if it is.
*/
void EquipedItems::showItemMenu(const int s_itemId) {
    int choise {1};

    while(choise != 0) {
        checkInputWithMessage();

        // If you have item in choosen slot
        if(s_itemId != 0)
            AllItemsDB::getItemByID(s_itemId)->showDescription();
        // If you haven't
        else 
            cout << "Пусто";
        
        cout << "\n\n0. Выход"
            << "\nВаш выбор: ";

        choise = getChoise();

        switch(choise) {
            case InterfaceConst::EXIT : {
                return;
            }
            default : {
                badInputState();
                break;
            }
        }
    }
}