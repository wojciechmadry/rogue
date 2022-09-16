#include <boost/test/unit_test.hpp>

#include "rogue.hpp"

BOOST_AUTO_TEST_SUITE(extern_hpp)

BOOST_AUTO_TEST_CASE( doctor_fun )
{
    init_player();
    BOOST_REQUIRE_EQUAL(quiet, 0);
    BOOST_REQUIRE_EQUAL(pstats.s_hpt, 12);
    BOOST_REQUIRE_EQUAL(pstats.s_lvl, 1);
    BOOST_REQUIRE_EQUAL(max_hp, 12);
    max_hp = 25;
    BOOST_REQUIRE_EQUAL(max_hp, 25);
    int cur_hp = 12;
    int quiet_counter = 0;

    for(int i = 0 ; i <= 255 ; ++i)
    {
        BOOST_REQUIRE_EQUAL(pstats.s_lvl, 1);
        BOOST_REQUIRE_EQUAL(pstats.s_hpt, cur_hp);
        BOOST_REQUIRE_EQUAL(quiet, quiet_counter);

        const auto before = pstats.s_hpt;
        doctor();
        const auto after = pstats.s_hpt;

        ++quiet_counter;
        const auto qu = quiet_counter;
        if (before != after || quiet_counter == 19)
        {
            quiet_counter = 0;
        }

		if (pstats.s_lvl < 8 && (qu + (pstats.s_lvl << 1) > 20))
		{
            ++cur_hp;
        }
        else if (qu >= 3)
		{
            cur_hp = pstats.s_hpt;
        }

        if(cur_hp > max_hp)
        {
            cur_hp = max_hp;
        }
    }
    
    BOOST_REQUIRE_EQUAL(pstats.s_lvl, 1);
    BOOST_REQUIRE_EQUAL(pstats.s_hpt, max_hp);
    BOOST_REQUIRE_EQUAL(quiet, 9);
    pstats.s_hpt = 10;
    BOOST_REQUIRE_EQUAL(pstats.s_hpt, 10);

    ring_on();
    cur_ring[LEFT] = new THING;
    cur_ring[RIGHT] = new THING;
    BOOST_REQUIRE_NE(cur_ring[LEFT], nullptr);
    BOOST_REQUIRE_NE(cur_ring[RIGHT], nullptr);
    cur_ring[LEFT]->_o._o_which = R_REGEN;
    cur_ring[RIGHT]->_o._o_which = R_REGEN;

    doctor();
    BOOST_REQUIRE_EQUAL(pstats.s_hpt, 12);

    delete cur_ring[LEFT];
    delete cur_ring[RIGHT] ;
}

BOOST_AUTO_TEST_SUITE_END()
