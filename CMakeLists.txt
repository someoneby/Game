cmake_minimum_required(VERSION 3.15)
project(Game)

set(CMAKE_CXX_STANDARD 14)

FIND_PACKAGE( Boost 1.40 COMPONENTS program_options REQUIRED )
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )
TARGET_LINK_LIBRARIES( ${Boost_LIBRARIES} )


add_executable(Game main.cpp
        Data/Characters/IUnit/IUnit.cpp
        Data/Characters/Unit/Unit.cpp
        Data/Characters/Player/Player.cpp
        Data/Characters/Mob/Mob.cpp
        Data/GameInterface/Bag/Bag.cpp
        Data/GameInterface/EquipedItems/EquipedItems.cpp
        Data/Items/Armor/Armor.cpp
        Data/Items/Chest/Chest.cpp 
        Data/Items/Equipment/Equipment.cpp
        Data/Items/Helm/Helm.cpp
        Data/Items/IItem/IItem.cpp
        Data/Items/Item/Item.cpp
        Data/Items/ItemInTheBag/ItemInTheBag.cpp
        Data/Items/Reagent/Reagent.cpp
        Data/Items/Weapon/Weapon.cpp
        Data/Utility/AllItemsDB/AllItemsDB.cpp
        Data/Utility/RandDouble/RandDouble.cpp
        Data/Utility/CombatLog/CombatLog.cpp
        )