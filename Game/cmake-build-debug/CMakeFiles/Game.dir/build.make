# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/yan/Clion/clion-2019.3.4/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/yan/Clion/clion-2019.3.4/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/yan/CLionProjects/Game

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/yan/CLionProjects/Game/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Game.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Game.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Game.dir/flags.make

CMakeFiles/Game.dir/main.cpp.o: CMakeFiles/Game.dir/flags.make
CMakeFiles/Game.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yan/CLionProjects/Game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Game.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Game.dir/main.cpp.o -c /home/yan/CLionProjects/Game/main.cpp

CMakeFiles/Game.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Game.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yan/CLionProjects/Game/main.cpp > CMakeFiles/Game.dir/main.cpp.i

CMakeFiles/Game.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Game.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yan/CLionProjects/Game/main.cpp -o CMakeFiles/Game.dir/main.cpp.s

CMakeFiles/Game.dir/Characters/IUnit/IUnit.cpp.o: CMakeFiles/Game.dir/flags.make
CMakeFiles/Game.dir/Characters/IUnit/IUnit.cpp.o: ../Characters/IUnit/IUnit.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yan/CLionProjects/Game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Game.dir/Characters/IUnit/IUnit.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Game.dir/Characters/IUnit/IUnit.cpp.o -c /home/yan/CLionProjects/Game/Characters/IUnit/IUnit.cpp

CMakeFiles/Game.dir/Characters/IUnit/IUnit.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Game.dir/Characters/IUnit/IUnit.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yan/CLionProjects/Game/Characters/IUnit/IUnit.cpp > CMakeFiles/Game.dir/Characters/IUnit/IUnit.cpp.i

CMakeFiles/Game.dir/Characters/IUnit/IUnit.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Game.dir/Characters/IUnit/IUnit.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yan/CLionProjects/Game/Characters/IUnit/IUnit.cpp -o CMakeFiles/Game.dir/Characters/IUnit/IUnit.cpp.s

CMakeFiles/Game.dir/Characters/Unit/Unit.cpp.o: CMakeFiles/Game.dir/flags.make
CMakeFiles/Game.dir/Characters/Unit/Unit.cpp.o: ../Characters/Unit/Unit.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yan/CLionProjects/Game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Game.dir/Characters/Unit/Unit.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Game.dir/Characters/Unit/Unit.cpp.o -c /home/yan/CLionProjects/Game/Characters/Unit/Unit.cpp

CMakeFiles/Game.dir/Characters/Unit/Unit.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Game.dir/Characters/Unit/Unit.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yan/CLionProjects/Game/Characters/Unit/Unit.cpp > CMakeFiles/Game.dir/Characters/Unit/Unit.cpp.i

CMakeFiles/Game.dir/Characters/Unit/Unit.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Game.dir/Characters/Unit/Unit.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yan/CLionProjects/Game/Characters/Unit/Unit.cpp -o CMakeFiles/Game.dir/Characters/Unit/Unit.cpp.s

CMakeFiles/Game.dir/Characters/Player/Player.cpp.o: CMakeFiles/Game.dir/flags.make
CMakeFiles/Game.dir/Characters/Player/Player.cpp.o: ../Characters/Player/Player.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yan/CLionProjects/Game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Game.dir/Characters/Player/Player.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Game.dir/Characters/Player/Player.cpp.o -c /home/yan/CLionProjects/Game/Characters/Player/Player.cpp

CMakeFiles/Game.dir/Characters/Player/Player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Game.dir/Characters/Player/Player.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yan/CLionProjects/Game/Characters/Player/Player.cpp > CMakeFiles/Game.dir/Characters/Player/Player.cpp.i

CMakeFiles/Game.dir/Characters/Player/Player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Game.dir/Characters/Player/Player.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yan/CLionProjects/Game/Characters/Player/Player.cpp -o CMakeFiles/Game.dir/Characters/Player/Player.cpp.s

CMakeFiles/Game.dir/Utility/RandDouble/RandDouble.cpp.o: CMakeFiles/Game.dir/flags.make
CMakeFiles/Game.dir/Utility/RandDouble/RandDouble.cpp.o: ../Utility/RandDouble/RandDouble.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yan/CLionProjects/Game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Game.dir/Utility/RandDouble/RandDouble.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Game.dir/Utility/RandDouble/RandDouble.cpp.o -c /home/yan/CLionProjects/Game/Utility/RandDouble/RandDouble.cpp

CMakeFiles/Game.dir/Utility/RandDouble/RandDouble.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Game.dir/Utility/RandDouble/RandDouble.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yan/CLionProjects/Game/Utility/RandDouble/RandDouble.cpp > CMakeFiles/Game.dir/Utility/RandDouble/RandDouble.cpp.i

CMakeFiles/Game.dir/Utility/RandDouble/RandDouble.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Game.dir/Utility/RandDouble/RandDouble.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yan/CLionProjects/Game/Utility/RandDouble/RandDouble.cpp -o CMakeFiles/Game.dir/Utility/RandDouble/RandDouble.cpp.s

CMakeFiles/Game.dir/Utility/FightLog.cpp.o: CMakeFiles/Game.dir/flags.make
CMakeFiles/Game.dir/Utility/FightLog.cpp.o: ../Utility/FightLog.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yan/CLionProjects/Game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Game.dir/Utility/FightLog.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Game.dir/Utility/FightLog.cpp.o -c /home/yan/CLionProjects/Game/Utility/FightLog.cpp

CMakeFiles/Game.dir/Utility/FightLog.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Game.dir/Utility/FightLog.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yan/CLionProjects/Game/Utility/FightLog.cpp > CMakeFiles/Game.dir/Utility/FightLog.cpp.i

CMakeFiles/Game.dir/Utility/FightLog.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Game.dir/Utility/FightLog.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yan/CLionProjects/Game/Utility/FightLog.cpp -o CMakeFiles/Game.dir/Utility/FightLog.cpp.s

# Object files for target Game
Game_OBJECTS = \
"CMakeFiles/Game.dir/main.cpp.o" \
"CMakeFiles/Game.dir/Characters/IUnit/IUnit.cpp.o" \
"CMakeFiles/Game.dir/Characters/Unit/Unit.cpp.o" \
"CMakeFiles/Game.dir/Characters/Player/Player.cpp.o" \
"CMakeFiles/Game.dir/Utility/RandDouble/RandDouble.cpp.o" \
"CMakeFiles/Game.dir/Utility/FightLog.cpp.o"

# External object files for target Game
Game_EXTERNAL_OBJECTS =

Game: CMakeFiles/Game.dir/main.cpp.o
Game: CMakeFiles/Game.dir/Characters/IUnit/IUnit.cpp.o
Game: CMakeFiles/Game.dir/Characters/Unit/Unit.cpp.o
Game: CMakeFiles/Game.dir/Characters/Player/Player.cpp.o
Game: CMakeFiles/Game.dir/Utility/RandDouble/RandDouble.cpp.o
Game: CMakeFiles/Game.dir/Utility/FightLog.cpp.o
Game: CMakeFiles/Game.dir/build.make
Game: CMakeFiles/Game.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/yan/CLionProjects/Game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable Game"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Game.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Game.dir/build: Game

.PHONY : CMakeFiles/Game.dir/build

CMakeFiles/Game.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Game.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Game.dir/clean

CMakeFiles/Game.dir/depend:
	cd /home/yan/CLionProjects/Game/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/yan/CLionProjects/Game /home/yan/CLionProjects/Game /home/yan/CLionProjects/Game/cmake-build-debug /home/yan/CLionProjects/Game/cmake-build-debug /home/yan/CLionProjects/Game/cmake-build-debug/CMakeFiles/Game.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Game.dir/depend

