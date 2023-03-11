cmake_minimum_required(VERSION 3.15)
project(Game)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_LIB Data/Characters/IUnit/IUnit.cpp
        Data/Characters/Player/Player.cpp
        Data/Characters/Mob/Mob.cpp
        Data/Characters/MobFactory/MobFactory.cpp
        Data/Characters/Utility/Parameters/Parameters.cpp
        Data/Characters/Utility/ParametersDB/ParametersDB.cpp
        Data/GameInterface/Bag/Bag.cpp
        Data/GameInterface/EquipedItems/EquipedItems.cpp
        Data/GameInterface/MainMenu/MainMenu.cpp
        Data/GameInterface/LocationsMenu/LocationsMenu.cpp
        Data/GameInterface/Utility/ItemInTheBag/ItemInTheBag.cpp
        Data/Items/Armor/Armor.cpp
        Data/Items/Chest/Chest.cpp 
        Data/Items/Helm/Helm.cpp
        Data/Items/IItem/IItem.cpp
        Data/Items/Reagent/Reagent.cpp
        Data/Items/Weapon/Weapon.cpp
        Data/Items/Utility/AllItemsDB/AllItemsDB.cpp
        Data/Utility/UtilityFunctions/RandDouble/RandDouble.cpp
        Data/Utility/UtilityFunctions/CombatLog/CombatLog.cpp
        Data/Utility/UtilityFunctions/GetChoise/GetChoise.cpp
        Data/Utility/UtilityFunctions/CheckInputWithMessage/CheckInputWithMessage.cpp
        Data/Utility/UtilityFunctions/BadInputState/BadInputState.cpp
        Data/Locations/Vendor/Vendor.cpp
        Data/Locations/Workshop/Workshop.cpp
        Data/Locations/Adventures/Adventures.cpp
        Data/Locations/Depths/Depths.cpp
        Data/Locations/Utility/ReagentElement/ReagentElement.cpp
        Data/Locations/Utility/ItemToCraft/ItemToCraft.cpp
)	


FIND_PACKAGE( Boost 1.40 COMPONENTS program_options REQUIRED )
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )
TARGET_LINK_LIBRARIES( ${Boost_LIBRARIES} )


add_library(game_lib STATIC ${SOURCE_LIB})

add_executable(Game main.cpp)

target_link_libraries(Game game_lib)