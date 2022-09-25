#include <boost/test/unit_test.hpp>

#include "rogue.hpp"

BOOST_AUTO_TEST_SUITE(extern_hpp)


BOOST_AUTO_TEST_CASE( playltchars_fun )
{
    BOOST_REQUIRE_EQUAL(got_ltc, false);
    playltchars();
    got_ltc = false;
    BOOST_REQUIRE_EQUAL(got_ltc, false);
    playltchars();
    got_ltc = false;
}

BOOST_AUTO_TEST_SUITE_END()
