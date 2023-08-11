#include <boost/test/unit_test.hpp>

#include <Types.h>

using namespace Ternary;

BOOST_AUTO_TEST_SUITE(Types_Trit)

    BOOST_AUTO_TEST_CASE(constructor)
    {
        Trit t;
    }

    BOOST_AUTO_TEST_CASE(constructor_char)
    {
        Trit t1('0'), t2(0);
        BOOST_CHECK_EQUAL(t1, t2);
        t1 = Trit('1');
        t2 = Trit(1);
        BOOST_CHECK_EQUAL(t1, t2);
        t1 = Trit('T');
        t2 = Trit(-1);
        BOOST_CHECK_EQUAL(t1, t2);
        t1 = Trit('X');
        BOOST_CHECK(t1.isNaN());
    }

BOOST_AUTO_TEST_SUITE_END()
