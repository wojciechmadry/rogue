#include <boost/test/unit_test.hpp>

#include "rogue.hpp"

BOOST_AUTO_TEST_SUITE(extern_hpp)


BOOST_AUTO_TEST_CASE( land_fun )
{
    init_player();
    BOOST_REQUIRE_EQUAL(player.t_flags, 0);

    for(int i = 0 ; i < 100 ; ++i)
    {
        move(0, 0);
        clrtoeol();
        mpos = 0;
        player.t_flags = i;
        land();
        BOOST_REQUIRE_EQUAL(player.t_flags, i & (~ISLEVIT));
    }
    

    player.t_flags = 0;
}

BOOST_AUTO_TEST_SUITE_END()
