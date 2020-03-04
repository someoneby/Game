cmake_minimum_required(VERSION 3.15)
project(Game)

set(CMAKE_CXX_STANDARD 14)

FIND_PACKAGE( Boost 1.40 COMPONENTS program_options REQUIRED )
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )
TARGET_LINK_LIBRARIES( ${Boost_LIBRARIES} )


add_executable(Game main.cpp
        Game/Characters/IUnit/IUnit.cpp
        Game/Characters/Unit/Unit.cpp
        Game/Characters/Player/Player.cpp
        Game/Characters/Mob/Mob.cpp
        Game/GameInterface/Bag/Bag.cpp
        Game/GameInterface/EquipedItems/EquipedItems.cpp
        Game/Items/Armor/Armor.cpp
        Game/Items/Chest/Chest.cpp 
        Game/Items/Equipment/Equipment.cpp
        Game/Items/Helm/Helm.cpp
        Game/Items/IItem/IItem.cpp
        Game/Items/Item/Item.cpp
        Game/Items/ItemInTheBag/ItemInTheBag.cpp
        Game/Items/Reagent/Reagent.cpp
        Game/Items/Weapon/Weapon.cpp
        Game/Utility/AllItemsDB/AllItemsDB.cpp
        Game/Utility/RandDouble/RandDouble.cpp
        Game/Utility/CombatLog/CombatLog.cpp
        )