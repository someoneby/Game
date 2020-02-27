cmake_minimum_required(VERSION 3.15)
project(Game)

set(CMAKE_CXX_STANDARD 14)

FIND_PACKAGE( Boost 1.40 COMPONENTS program_options REQUIRED )
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )
TARGET_LINK_LIBRARIES( ${Boost_LIBRARIES} )


add_executable(Game main.cpp
        Characters/IUnit/IUnit.cpp
        Characters/Unit/Unit.cpp
        Characters/Player/Player.cpp
        Utility/RandDouble/RandDouble.cpp
        Utility/CombatLog/CombatLog.cpp
        Characters/Mob/Mob.cpp
        Equipment/IEquipment/IEquipment.cpp
        Equipment/Armor/Armor.cpp
        Equipment/Weapon/Weapon.cpp
        Equipment/EquipedItems/EquipedItems.cpp
        Equipment/Helm/Helm.cpp
        Equipment/Chest/Chest.cpp 
        )