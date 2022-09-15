cmake_minimum_required(VERSION 3.17)
project(RogueLinuxCpp)
set(CMAKE_CXX_STANDARD 20)

# Define either of KEYS_QWERTY or KEYS_DVORAK below
add_definitions(-DKEYS_QWERTY)

include_directories(include)

set(COMPILER_FLAGS "-O3")

add_library(rogue_lib STATIC
        src/xcrypt.cpp
        src/wizard.cpp
        src/weapons.cpp
        src/vers.cpp
        src/things.cpp
        src/sticks.cpp
        src/state.cpp
        src/scrolls.cpp
        src/save.cpp
        src/rooms.cpp
        src/rip.cpp
        src/rings.cpp
        src/potions.cpp
        src/passages.cpp
        src/pack.cpp
        src/options.cpp
        src/new_level.cpp
        src/move.cpp
        src/monsters.cpp
        src/misc.cpp
        src/mdport.cpp
        src/mach_dep.cpp
        src/list.cpp
        src/io.cpp
        src/init.cpp
        src/fight.cpp
        src/extern.cpp
        src/daemons.cpp
        src/daemon.cpp
        src/command.cpp
        src/chase.cpp
        src/armor.cpp
)

set_target_properties(rogue_lib PROPERTIES LINKER_LANGUAGE CXX)
target_compile_options(rogue_lib PRIVATE ${COMPILER_FLAGS})

add_executable(rogue 
        src/main.cpp
)

#   ncourses library
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})
target_link_libraries(rogue rogue_lib ${CURSES_LIBRARIES})
# -------------------

set_target_properties(rogue PROPERTIES LINKER_LANGUAGE CXX)
target_compile_options(rogue PRIVATE ${COMPILER_FLAGS})
