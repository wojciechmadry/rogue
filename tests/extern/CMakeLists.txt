add_library(extern_tests SHARED
    come_down.cpp
)
target_link_libraries(extern_tests ${Boost_LIBRARIES} rogue_lib)
