#include <boost/test/unit_test.hpp>

#include "rogue.hpp"

BOOST_AUTO_TEST_SUITE(extern_hpp)

BOOST_AUTO_TEST_CASE( come_down_cpp )
{
    for(std::int16_t i = 0 ; i <= 1000 ; ++i)
    {
        player._t._t_flags = i;
        const auto old_flag = player._t._t_flags;
        come_down();

        if (!on(player, ISHALU))
        {
            BOOST_REQUIRE_EQUAL(player._t._t_flags, old_flag);
            continue;
        }
        if (on(player, ISBLIND))
        {
            BOOST_REQUIRE_EQUAL(player._t._t_flags, old_flag &(~ISHALU));
            continue;
        }
        BOOST_REQUIRE_EQUAL(player._t._t_flags, old_flag &(~ISHALU));
    }
    player._t._t_flags = 0;
}

BOOST_AUTO_TEST_SUITE_END()
