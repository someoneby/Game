cmake_minimum_required(VERSION 3.15)
project(Game)

set(CMAKE_CXX_STANDARD 14)

add_executable(Game main.cpp
        Characters/IUnit/IUnit.cpp
        Characters/Unit/Unit.cpp
        Characters/Player/Player.cpp
        Utility/RandDouble/RandDouble.cpp

        Utility/CombatLog/CombatLog.cpp Utility/CombatLog/CombatLog.h Utility/Constans/CombatLogStages.h)