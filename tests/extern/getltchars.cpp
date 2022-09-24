#include <boost/test/unit_test.hpp>

#include "rogue.hpp"

BOOST_AUTO_TEST_SUITE(extern_hpp)


BOOST_AUTO_TEST_CASE( getltchars_fun )
{
    BOOST_REQUIRE_EQUAL(got_ltc, false);
    BOOST_REQUIRE_EQUAL(orig_dsusp, 0);
    getltchars();
    BOOST_REQUIRE_EQUAL(got_ltc, true);
    BOOST_REQUIRE_EQUAL(orig_dsusp, 0);
    getltchars();
    BOOST_REQUIRE_EQUAL(got_ltc, true);
    BOOST_REQUIRE_EQUAL(orig_dsusp, 0);
}

BOOST_AUTO_TEST_SUITE_END()
