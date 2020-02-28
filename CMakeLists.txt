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
        Game/Utility/RandDouble/RandDouble.cpp
        Game/Utility/CombatLog/CombatLog.cpp
        Game/Characters/Mob/Mob.cpp
        Game/Equipment/Equipment/Equipment.cpp
        Game/Equipment/Armor/Armor.cpp
        Game/Equipment/Weapon/Weapon.cpp
        Game/Equipment/Helm/Helm.cpp
        Game/Equipment/Chest/Chest.cpp 
        Game/Equipment/IItem/IItem.cpp
        Game/Equipment/Item/Item.cpp
        Game/GameInterface/Bag/Bag.cpp
        Game/GameInterface/EquipedItems/EquipedItems.cpp
        )