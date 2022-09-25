#include <boost/test/unit_test.hpp>

#include "rogue.hpp"

BOOST_AUTO_TEST_SUITE(extern_hpp)


BOOST_AUTO_TEST_CASE( rollwand_fun )
{
    BOOST_REQUIRE_EQUAL(between, 0);
    for(int i = 0 ; i < 20 ; ++i)
    {
        msg("\0");
        rollwand();
        BOOST_REQUIRE_EQUAL(between, (i + 1) % 4);
    }
}

BOOST_AUTO_TEST_SUITE_END()
