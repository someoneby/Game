#include "EquipedItems.h"
#include "../Bag/Bag.h"
#include "../../Utility/AllItemsDB/AllItemsDB.h"
#include "../../Items/Weapon/Weapon.h"
#include "../../Items/Armor/Armor.h"
#include "../../Characters/Player/Player.h"

int EquipedItems::m_helmId = 0;
int EquipedItems::m_chestId = 0;
int EquipedItems::m_weaponId = 0;

void EquipedItems::equip (int s_id, TypesOfEquip s_type) {
    switch (s_type) {
        case TypesOfEquip::weapon : {
            if (m_weaponId != 0) {
                unEquip(s_type);
            }

            // Change count of items in the bag
            Bag::takeFromBag(s_id);

            // Change player's parameters
            Player::getInstance()->changeDamage(static_cast<Weapon *>(AllItemsDB::getItemByID(s_id))->getDamage());
            Player::getInstance()->changeCriticalChance(static_cast<Weapon *>(AllItemsDB::getItemByID(s_id))->getCriticalChance());

            // Change id of equipted Weapon
            m_weaponId = s_id;

            break;
        }
        
        case TypesOfEquip::chest : {}
        case TypesOfEquip::helm : {
            //Select target_id by type
            int target_id {m_helmId};
            if(s_type == TypesOfEquip::chest)
                target_id = m_chestId;

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
                m_chestId = s_id;
            else 
                m_helmId = s_id;

            break;          
        }
        
    }
}

void EquipedItems::unEquip (TypesOfEquip s_type) {

    switch (s_type) {
            case TypesOfEquip::weapon : {
                // Change count of items in the bag
                Bag::putToBag(m_weaponId);

                // Taking Item* from the database, cast to Weapon* and Change player's parameters
                Player::getInstance()->changeDamage(- static_cast<Weapon *>(AllItemsDB::getItemByID(m_weaponId))->getDamage());
                Player::getInstance()->changeCriticalChance(- static_cast<Weapon *>(AllItemsDB::getItemByID(m_weaponId))->getCriticalChance());

                // Change id of equipted Weapon
                m_weaponId = 0;

                break;
            }
            
            case TypesOfEquip::chest : {}
            case TypesOfEquip::helm : {
                //Select target_id by type
                int target_id {m_helmId};
                if(s_type == TypesOfEquip::chest)
                    target_id = m_chestId;
                
                // Change count of items in the bag
                Bag::putToBag(target_id);

                // Taking Item* from the database, cast to Armor* and Change player's parameters
                Player::getInstance()->changeHp(- static_cast<Armor *>(AllItemsDB::getItemByID(target_id))->getHp());
                Player::getInstance()->changeArmor(- static_cast<Armor *>(AllItemsDB::getItemByID(target_id))->getArmor());
                Player::getInstance()->changeAvoidChance(- static_cast<Armor *>(AllItemsDB::getItemByID(target_id))->getAvoidChance());  

                // Change id of equipted Armor
                if(s_type == TypesOfEquip::chest)
                    m_chestId = 0;
                else 
                    m_helmId = 0;

                break;          
            }
            
        }


}

