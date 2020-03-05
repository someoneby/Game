#include "EquipedItems.h"
#include "../Bag/Bag.h"
#include "../../Utility/AllItemsDB/AllItemsDB.h"
#include "../../Items/Weapon/Weapon.h"
#include "../../Characters/Player/Player.h"

int EquipedItems::m_helmId = 0;
int EquipedItems::m_chestId = 0;
int EquipedItems::m_weaponId = 0;

void EquipedItems::equip (int s_id, TypesOfEquip s_type) {
    switch (s_type) {
        case TypesOfEquip::weapon : {
            int damage_change {0};
            int criticalChance_change {0};

            if (m_weaponId != 0) {
                // Taking Item* from the database, cast to Weapon* and calculating changes
                // Substract parameters of unequiped Weapon
                damage_change -= static_cast<Weapon *>(AllItemsDB::getItemByID(m_weaponId))->getDamage();
                criticalChance_change -= static_cast<Weapon *>(AllItemsDB::getItemByID(m_weaponId))->getCriticalChance();
            }

            // Add parameters of equiped Weapon
            damage_change += static_cast<Weapon *>(AllItemsDB::getItemByID(s_id))->getDamage();
            criticalChance_change += static_cast<Weapon *>(AllItemsDB::getItemByID(s_id))->getCriticalChance();

            // Change count of items in the bag
            if (m_weaponId != 0)
                Bag::putToBag(m_weaponId);

            Bag::takeFromBag(s_id);

            // Change player's parameters
            Player::getInstance()->changeDamage(damage_change);
            Player::getInstance()->changeCriticalChance(criticalChance_change);

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
            
            int hp_change {0};
            int armor_change {0};
            int avoidChance_change {0};

            if (target_id != 0) {
                // Taking Item* from the database, cast to Armor* and calculating changes
                // Substract parameters of unequiped Armor
                hp_change -= static_cast<Armor *>(AllItemsDB::getItemByID(target_id))->getHp();
                armor_change -= static_cast<Armor *>(AllItemsDB::getItemByID(target_id))->getArmor();
                avoidChance_change -= static_cast<Armor *>(AllItemsDB::getItemByID(target_id))->getAvoidChance();
            }

            // Add parameters of equiped Armor
            hp_change += static_cast<Armor *>(AllItemsDB::getItemByID(s_id))->getHp();
            armor_change += static_cast<Armor *>(AllItemsDB::getItemByID(s_id))->getArmor();
            avoidChance_change += static_cast<Armor *>(AllItemsDB::getItemByID(s_id))->getAvoidChance();
            
            // Change count of items in the bag
            if(target_id != 0)
                Bag::putToBag(target_id);

            Bag::takeFromBag(s_id);

            // Change player's parameters
            Player::getInstance()->changeHp(hp_change);
            Player::getInstance()->changeArmor(armor_change);
            Player::getInstance()->changeAvoidChance(avoidChance_change);  

            // Change id of equipted Armor
            if(s_type == TypesOfEquip::chest)
                m_chestId = s_id;
            else 
                m_helmId = s_id;

            break;          
        }
        
    }
}

