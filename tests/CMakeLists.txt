
find_package(Boost COMPONENTS system filesystem unit_test_framework REQUIRED)
include_directories (${Boost_INCLUDE_DIRS})

add_executable(tests_rogue
test_main.cpp
)

target_link_libraries(tests_rogue
    ${Boost_LIBRARIES}
    rogue_lib
)
