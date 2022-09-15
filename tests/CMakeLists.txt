
find_package(Boost COMPONENTS system filesystem unit_test_framework REQUIRED)
include_directories (${Boost_INCLUDE_DIRS})

add_compile_options(-DBOOST_TEST_DYN_LINK)
add_compile_definitions(BOOST_TEST_DYN_LINK)

add_subdirectory(extern)

add_executable(tests_rogue
test_main.cpp
)

target_link_libraries(tests_rogue
    ${Boost_LIBRARIES}
    extern_tests
)
