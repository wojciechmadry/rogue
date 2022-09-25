#include <boost/test/unit_test.hpp>

#include "rogue.hpp"

BOOST_AUTO_TEST_SUITE(extern_hpp)


BOOST_AUTO_TEST_CASE( resetltchars_fun )
{
    BOOST_REQUIRE_EQUAL(got_ltc, false);
    BOOST_REQUIRE_EQUAL(orig_dsusp, 0);
    resetltchars();
    BOOST_REQUIRE_EQUAL(got_ltc, false);
    BOOST_REQUIRE_EQUAL(orig_dsusp, 0);
    resetltchars();
    BOOST_REQUIRE_EQUAL(got_ltc, false);
    BOOST_REQUIRE_EQUAL(orig_dsusp, 0);
    got_ltc = false;
}

BOOST_AUTO_TEST_SUITE_END()
