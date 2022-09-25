
find_package(Boost COMPONENTS system filesystem unit_test_framework REQUIRED)
include_directories (${Boost_INCLUDE_DIRS})

add_executable(tests_rogue
test_main.cpp
extern/come_down.cpp
extern/doctor.cpp
extern/getltchars.cpp
extern/land.cpp
extern/nohaste.cpp
extern/playltchars.cpp
extern/resetltchars.cpp
extern/rollwand.cpp
)

target_link_libraries(tests_rogue
    ${Boost_LIBRARIES}
    rogue_lib
)
