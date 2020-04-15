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

void EquipedItems::equip (const int s_id) {
    // If id belongs to helms or chests
    if(s_id < ItemsConsts::FIRST_WEAPON_ID) {
        //Select target_id by type
        int target_id;
        if(s_id < ItemsConsts::FIRST_CHEST_ID)
            target_id = m_instance->m_helmId;
        else
            target_id = m_instance->m_chestId;

        // If the item is on
        if (target_id != 0) {
            unEquip(s_id);
        }
     
        // Change count of items in the bag
        Bag::takeFromBag(s_id);

        // Change player's parameters
        Player::getInstance()->changeHp(static_cast<Armor *>(AllItemsDB::getItemByID(s_id))->getHp());
        Player::getInstance()->changeArmor(static_cast<Armor *>(AllItemsDB::getItemByID(s_id))->getArmor());
        Player::getInstance()->changeAvoidChance(static_cast<Armor *>(AllItemsDB::getItemByID(s_id))->getAvoidChance());  

        // Change id of equipted Armor
        if(s_id < ItemsConsts::FIRST_CHEST_ID)
            m_instance->m_helmId = s_id;
        else 
            m_instance->m_chestId = s_id;
    }
    else {
        // If the item is on
        if (m_instance->m_weaponId != 0) {
            unEquip(s_id);
        }

        // Change count of items in the bag
        Bag::takeFromBag(s_id);

        // Change player's parameters
        Player::getInstance()->changeDamage(static_cast<Weapon *>(AllItemsDB::getItemByID(s_id))->getDamage());
        Player::getInstance()->changeCriticalChance(static_cast<Weapon *>(AllItemsDB::getItemByID(s_id))->getCriticalChance());

        // Change id of equipted Weapon
        m_instance->m_weaponId = s_id;
    }
}

void EquipedItems::unEquip (const int s_id) {
    if(s_id < ItemsConsts::FIRST_WEAPON_ID) {
        //Select target_id by type
        int target_id;
        if(s_id < ItemsConsts::FIRST_CHEST_ID)
            target_id = m_instance->m_helmId;
        else
            target_id = m_instance->m_chestId;
                
        // Change count of items in the bag
        Bag::putToBag(target_id);

        // Taking Item* from the database, cast to Armor* and Change player's parameters
        Player::getInstance()->changeHp(- static_cast<Armor *>(AllItemsDB::getItemByID(target_id))->getHp());
        Player::getInstance()->changeArmor(- static_cast<Armor *>(AllItemsDB::getItemByID(target_id))->getArmor());
        Player::getInstance()->changeAvoidChance(- static_cast<Armor *>(AllItemsDB::getItemByID(target_id))->getAvoidChance());  

        // Change id of equipted Armor
        if(s_id < ItemsConsts::FIRST_CHEST_ID)
            m_instance->m_helmId = 0;         
        else 
            m_instance->m_chestId = 0;
    }
    else { 
        // Change count of items in the bag
        Bag::putToBag(m_instance->m_weaponId);

        // Taking Item* from the database, cast to Weapon* and Change player's parameters
        Player::getInstance()->changeDamage(- static_cast<Weapon *>(AllItemsDB::getItemByID(m_instance->m_weaponId))->getDamage());
        Player::getInstance()->changeCriticalChance(- static_cast<Weapon *>(AllItemsDB::getItemByID(m_instance->m_weaponId))->getCriticalChance());

        // Change id of equipted Weapon
        m_instance->m_weaponId = 0;       
    }
}

void EquipedItems::showMenu() {
    int choise {1};

    while(choise != 0) {
        checkInputWithMessage();

        //Show all equiped items
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

void EquipedItems::showItemMenu(const int s_id) {
    int choise {1};

    while(choise != 0) {
        checkInputWithMessage();

        // If you have item in choosen slot
        if(s_id != 0)
            AllItemsDB::getItemByID(s_id)->showDescription();
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