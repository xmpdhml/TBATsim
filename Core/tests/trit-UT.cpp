#include <boost/test/unit_test.hpp>
#include <sstream>

#include <trit.h>

using namespace Ternary;

BOOST_AUTO_TEST_SUITE(Types_Trit)

    BOOST_AUTO_TEST_CASE(constructor)
    {
        Trit t;
    }

    BOOST_AUTO_TEST_CASE(trit_neg)
    {
        Trit t1('0'), t2('1'), t3('T');
        BOOST_CHECK_EQUAL(-t1, t1);
        BOOST_CHECK_EQUAL(-t2, t3);
        BOOST_CHECK_EQUAL(-t3, t2);
    }

    BOOST_AUTO_TEST_CASE(trit_comparison)
    {
        Trit t1('0'), t2('1'), t3('T');
        BOOST_CHECK(t1 == t1);
        BOOST_CHECK(t2 == t2);
        BOOST_CHECK(t3 == t3);
        BOOST_CHECK(t1 != t2);
        BOOST_CHECK(t1 != t3);
        BOOST_CHECK(t2 != t3);
        BOOST_CHECK(t1 < t2);
        BOOST_CHECK(t1 > t3);
        BOOST_CHECK(t2 > t3);
    }

    BOOST_AUTO_TEST_CASE(tritwise_and)
    {
        Trit t1('T'), t2('0'), t3('1');
        BOOST_CHECK_EQUAL(t1 & t1, t1);
        BOOST_CHECK_EQUAL(t1 & t2, t1);
        BOOST_CHECK_EQUAL(t1 & t3, t1);
        BOOST_CHECK_EQUAL(t2 & t1, t1);
        BOOST_CHECK_EQUAL(t2 & t2, t2);
        BOOST_CHECK_EQUAL(t2 & t3, t2);
        BOOST_CHECK_EQUAL(t3 & t1, t1);
        BOOST_CHECK_EQUAL(t3 & t2, t2);
        BOOST_CHECK_EQUAL(t3 & t3, t3);
    }

    BOOST_AUTO_TEST_CASE(tritwise_or)
    {
        Trit t1('T'), t2('0'), t3('1');
        BOOST_CHECK_EQUAL(t1 | t1, t1);
        BOOST_CHECK_EQUAL(t1 | t2, t2);
        BOOST_CHECK_EQUAL(t1 | t3, t3);
        BOOST_CHECK_EQUAL(t2 | t1, t2);
        BOOST_CHECK_EQUAL(t2 | t2, t2);
        BOOST_CHECK_EQUAL(t2 | t3, t3);
        BOOST_CHECK_EQUAL(t3 | t1, t3);
        BOOST_CHECK_EQUAL(t3 | t2, t3);
        BOOST_CHECK_EQUAL(t3 | t3, t3);
    }

    BOOST_AUTO_TEST_CASE(trit_add)
    {
        Trit t('T');
        BOOST_CHECK_EQUAL(t.Add('T'), Trit('T'));
        BOOST_CHECK_EQUAL(t, Trit('1'));
        BOOST_CHECK_EQUAL(t.Add('T'), Trit('0'));
        BOOST_CHECK_EQUAL(t, Trit('0'));
        BOOST_CHECK_EQUAL(t.Add('T'), Trit('0'));
        BOOST_CHECK_EQUAL(t, Trit('T'));
        BOOST_CHECK_EQUAL(t.Add('0'), Trit('0'));
        BOOST_CHECK_EQUAL(t, Trit('T'));
        BOOST_CHECK_EQUAL(t.Add('1'), Trit('0'));
        BOOST_CHECK_EQUAL(t, Trit('0'));
        BOOST_CHECK_EQUAL(t.Add('1'), Trit('0'));
        BOOST_CHECK_EQUAL(t, Trit('1'));
        BOOST_CHECK_EQUAL(t.Add('1'), Trit('1'));
        BOOST_CHECK_EQUAL(t, Trit('T'));
    }

    BOOST_AUTO_TEST_CASE(trit_sub)
    {
        Trit t('T');
        BOOST_CHECK_EQUAL(t.Sub('T'), Trit('0'));
        BOOST_CHECK_EQUAL(t, Trit('0'));
        BOOST_CHECK_EQUAL(t.Sub('T'), Trit('0'));
        BOOST_CHECK_EQUAL(t, Trit('1'));
        BOOST_CHECK_EQUAL(t.Sub('T'), Trit('1'));
        BOOST_CHECK_EQUAL(t, Trit('T'));
        BOOST_CHECK_EQUAL(t.Sub('0'), Trit('0'));
        BOOST_CHECK_EQUAL(t, Trit('T'));
        BOOST_CHECK_EQUAL(t.Sub('1'), Trit('T'));
        BOOST_CHECK_EQUAL(t, Trit('1'));
        BOOST_CHECK_EQUAL(t.Sub('1'), Trit('0'));
        BOOST_CHECK_EQUAL(t, Trit('0'));
        BOOST_CHECK_EQUAL(t.Sub('1'), Trit('0'));
        BOOST_CHECK_EQUAL(t, Trit('T'));
    }

BOOST_AUTO_TEST_SUITE_END()
