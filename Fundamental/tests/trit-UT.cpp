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
        Trit t('T'); // -1 + -1 + -1 = -3 T0
        BOOST_CHECK_EQUAL(t.Add('T', 'T'), Trit('T'));
        BOOST_CHECK_EQUAL(t, Trit('0'));
        t = 'T'; // -1 + -1 + 0 = -2 T1
        BOOST_CHECK_EQUAL(t.Add('T', '0'), Trit('T'));
        BOOST_CHECK_EQUAL(t, Trit('1'));
        t = 'T'; // -1 + -1 + 1 = -1 0T
        BOOST_CHECK_EQUAL(t.Add('T', '1'), Trit('0'));
        BOOST_CHECK_EQUAL(t, Trit('T'));
        t = 'T'; // -1 + 0 + -1 = -2 T1
        BOOST_CHECK_EQUAL(t.Add('0', 'T'), Trit('T'));
        BOOST_CHECK_EQUAL(t, Trit('1'));
        t = 'T'; // -1 + 0 + 0 = -1 0T
        BOOST_CHECK_EQUAL(t.Add('0', '0'), Trit('0'));
        BOOST_CHECK_EQUAL(t, Trit('T'));
        t = 'T'; // -1 + 0 + 1 = 0 00
        BOOST_CHECK_EQUAL(t.Add('0', '1'), Trit('0'));
        BOOST_CHECK_EQUAL(t, Trit('0'));
        t = 'T'; // -1 + 1 + -1 = -1 0T
        BOOST_CHECK_EQUAL(t.Add('1', 'T'), Trit('0'));
        BOOST_CHECK_EQUAL(t, Trit('T'));
        t = 'T'; // -1 + 1 + 0 = 0 00
        BOOST_CHECK_EQUAL(t.Add('1', '0'), Trit('0'));
        BOOST_CHECK_EQUAL(t, Trit('0'));
        t = 'T'; // -1 + 1 + 1 = 1 01
        BOOST_CHECK_EQUAL(t.Add('1', '1'), Trit('0'));
        BOOST_CHECK_EQUAL(t, Trit('1'));

        t = '0'; // 0 + -1 + -1 = -2 T1
        BOOST_CHECK_EQUAL(t.Add('T', 'T'), Trit('T'));
        BOOST_CHECK_EQUAL(t, Trit('1'));
        t = '0'; // 0 + -1 + 0 = -1 0T
        BOOST_CHECK_EQUAL(t.Add('T', '0'), Trit('0'));
        BOOST_CHECK_EQUAL(t, Trit('T'));
        t = '0'; // 0 + -1 + 1 = 0 00
        BOOST_CHECK_EQUAL(t.Add('T', '1'), Trit('0'));
        BOOST_CHECK_EQUAL(t, Trit('0'));
        t = '0'; // 0 + 0 + -1 = -1 0T
        BOOST_CHECK_EQUAL(t.Add('0', 'T'), Trit('0'));
        BOOST_CHECK_EQUAL(t, Trit('T'));
        t = '0'; // 0 + 0 + 0 = 0 00
        BOOST_CHECK_EQUAL(t.Add('0', '0'), Trit('0'));
        BOOST_CHECK_EQUAL(t, Trit('0'));
        t = '0'; // 0 + 0 + 1 = 1 01
        BOOST_CHECK_EQUAL(t.Add('0', '1'), Trit('0'));
        BOOST_CHECK_EQUAL(t, Trit('1'));
        t = '0'; // 0 + 1 + -1 = 0 00
        BOOST_CHECK_EQUAL(t.Add('1', 'T'), Trit('0'));
        BOOST_CHECK_EQUAL(t, Trit('0'));
        t = '0'; // 0 + 1 + 0 = 1 01
        BOOST_CHECK_EQUAL(t.Add('1', '0'), Trit('0'));
        BOOST_CHECK_EQUAL(t, Trit('1'));
        t = '0'; // 0 + 1 + 1 = 2 1T
        BOOST_CHECK_EQUAL(t.Add('1', '1'), Trit('1'));
        BOOST_CHECK_EQUAL(t, Trit('T'));

        t = '1'; // 1 + -1 + -1 = -1 0T
        BOOST_CHECK_EQUAL(t.Add('T', 'T'), Trit('0'));
        BOOST_CHECK_EQUAL(t, Trit('T'));
        t = '1'; // 1 + -1 + 0 = 0 00
        BOOST_CHECK_EQUAL(t.Add('T', '0'), Trit('0'));
        BOOST_CHECK_EQUAL(t, Trit('0'));
        t = '1'; // 1 + -1 + 1 = 1 01
        BOOST_CHECK_EQUAL(t.Add('T', '1'), Trit('0'));
        BOOST_CHECK_EQUAL(t, Trit('1'));
        t = '1'; // 1 + 0 + -1 = 0 00
        BOOST_CHECK_EQUAL(t.Add('0', 'T'), Trit('0'));
        BOOST_CHECK_EQUAL(t, Trit('0'));
        t = '1'; // 1 + 0 + 0 = 1 01
        BOOST_CHECK_EQUAL(t.Add('0', '0'), Trit('0'));
        BOOST_CHECK_EQUAL(t, Trit('1'));
        t = '1'; // 1 + 0 + 1 = 2 1T
        BOOST_CHECK_EQUAL(t.Add('0', '1'), Trit('1'));
        BOOST_CHECK_EQUAL(t, Trit('T'));
        t = '1'; // 1 + 1 + -1 = 1 01
        BOOST_CHECK_EQUAL(t.Add('1', 'T'), Trit('0'));
        BOOST_CHECK_EQUAL(t, Trit('1'));
        t = '1'; // 1 + 1 + 0 = 2 1T
        BOOST_CHECK_EQUAL(t.Add('1', '0'), Trit('1'));
        BOOST_CHECK_EQUAL(t, Trit('T'));
        t = '1'; // 1 + 1 + 1 = 3 TT
        BOOST_CHECK_EQUAL(t.Add('1', '1'), Trit('1'));
        BOOST_CHECK_EQUAL(t, Trit('0'));
    }

    BOOST_AUTO_TEST_CASE(trit_sub)
    {
        Trit t('T'); // -1 - -1 + -1 = -1 0T
        BOOST_CHECK_EQUAL(t.Sub('T', 'T'), Trit('0'));
        BOOST_CHECK_EQUAL(t, Trit('T'));
        t = 'T'; // -1 - -1 + 0 = 0 00
        BOOST_CHECK_EQUAL(t.Sub('T', '0'), Trit('0'));
        BOOST_CHECK_EQUAL(t, Trit('0'));
        t = 'T'; // -1 - -1 + 1 = 1 01
        BOOST_CHECK_EQUAL(t.Sub('T', '1'), Trit('0'));
        BOOST_CHECK_EQUAL(t, Trit('1'));
        t = 'T'; // -1 - 0 + -1 = -2 T1
        BOOST_CHECK_EQUAL(t.Sub('0', 'T'), Trit('T'));
        BOOST_CHECK_EQUAL(t, Trit('1'));
        t = 'T'; // -1 - 0 + 0 = -1 0T
        BOOST_CHECK_EQUAL(t.Sub('0', '0'), Trit('0'));
        BOOST_CHECK_EQUAL(t, Trit('T'));
        t = 'T'; // -1 - 0 + 1 = 0 00
        BOOST_CHECK_EQUAL(t.Sub('0', '1'), Trit('0'));
        BOOST_CHECK_EQUAL(t, Trit('0'));
        t = 'T'; // -1 - 1 + -1 = -3 T0
        BOOST_CHECK_EQUAL(t.Sub('1', 'T'), Trit('T'));
        BOOST_CHECK_EQUAL(t, Trit('0'));
        t = 'T'; // -1 - 1 + 0 = -2 T1
        BOOST_CHECK_EQUAL(t.Sub('1', '0'), Trit('T'));
        BOOST_CHECK_EQUAL(t, Trit('1'));
        t = 'T'; // -1 - 1 + 1 = -1 0T
        BOOST_CHECK_EQUAL(t.Sub('1', '1'), Trit('0'));
        BOOST_CHECK_EQUAL(t, Trit('T'));

        t = '0'; // 0 - -1 + -1 = 0 00
        BOOST_CHECK_EQUAL(t.Sub('T', 'T'), Trit('0'));
        BOOST_CHECK_EQUAL(t, Trit('0'));
        t = '0'; // 0 - -1 + 0 = 1 01
        BOOST_CHECK_EQUAL(t.Sub('T', '0'), Trit('0'));
        BOOST_CHECK_EQUAL(t, Trit('1'));
        t = '0'; // 0 - -1 + 1 = 2 1T
        BOOST_CHECK_EQUAL(t.Sub('T', '1'), Trit('1'));
        BOOST_CHECK_EQUAL(t, Trit('T'));
        t = '0'; // 0 - 0 + -1 = -1 0T
        BOOST_CHECK_EQUAL(t.Sub('0', 'T'), Trit('0'));
        BOOST_CHECK_EQUAL(t, Trit('T'));
        t = '0'; // 0 - 0 + 0 = 0 00
        BOOST_CHECK_EQUAL(t.Sub('0', '0'), Trit('0'));
        BOOST_CHECK_EQUAL(t, Trit('0'));
        t = '0'; // 0 - 0 + 1 = 1 01
        BOOST_CHECK_EQUAL(t.Sub('0', '1'), Trit('0'));
        BOOST_CHECK_EQUAL(t, Trit('1'));
        t = '0'; // 0 - 1 + -1 = -2 T1
        BOOST_CHECK_EQUAL(t.Sub('1', 'T'), Trit('T'));
        BOOST_CHECK_EQUAL(t, Trit('1'));
        t = '0'; // 0 - 1 + 0 = -1 0T
        BOOST_CHECK_EQUAL(t.Sub('1', '0'), Trit('0'));
        BOOST_CHECK_EQUAL(t, Trit('T'));
        t = '0'; // 0 - 1 + 1 = 0 00
        BOOST_CHECK_EQUAL(t.Sub('1', '1'), Trit('0'));
        BOOST_CHECK_EQUAL(t, Trit('0'));
        
        t = '1'; // 1 - -1 + -1 = 1 01
        BOOST_CHECK_EQUAL(t.Sub('T', 'T'), Trit('0'));
        BOOST_CHECK_EQUAL(t, Trit('1'));
        t = '1'; // 1 - -1 + 0 = 2 1T
        BOOST_CHECK_EQUAL(t.Sub('T', '0'), Trit('1'));
        BOOST_CHECK_EQUAL(t, Trit('T'));
        t = '1'; // 1 - -1 + 1 = 3 10
        BOOST_CHECK_EQUAL(t.Sub('T', '1'), Trit('1'));
        BOOST_CHECK_EQUAL(t, Trit('0'));
        t = '1'; // 1 - 0 + -1 = 0 00
        BOOST_CHECK_EQUAL(t.Sub('0', 'T'), Trit('0'));
        BOOST_CHECK_EQUAL(t, Trit('0'));
        t = '1'; // 1 - 0 + 0 = 1 01
        BOOST_CHECK_EQUAL(t.Sub('0', '0'), Trit('0'));
        BOOST_CHECK_EQUAL(t, Trit('1'));
        t = '1'; // 1 - 0 + 1 = 2 1T
        BOOST_CHECK_EQUAL(t.Sub('0', '1'), Trit('1'));
        BOOST_CHECK_EQUAL(t, Trit('T'));
        t = '1'; // 1 - 1 + -1 = -1 0T
        BOOST_CHECK_EQUAL(t.Sub('1', 'T'), Trit('0'));
        BOOST_CHECK_EQUAL(t, Trit('T'));
        t = '1'; // 1 - 1 + 0 = 0 00
        BOOST_CHECK_EQUAL(t.Sub('1', '0'), Trit('0'));
        BOOST_CHECK_EQUAL(t, Trit('0'));
        t = '1'; // 1 - 1 + 1 = 1 01
        BOOST_CHECK_EQUAL(t.Sub('1', '1'), Trit('0'));
        BOOST_CHECK_EQUAL(t, Trit('1'));
    }

    BOOST_AUTO_TEST_CASE(trit_mul)
    {
        Trit t('T');
        t.Mul('T');
        BOOST_CHECK_EQUAL(t, Trit('1'));
        t = 'T';
        t.Mul('0');
        BOOST_CHECK_EQUAL(t, Trit('0'));
        t = 'T';
        t.Mul('1');
        BOOST_CHECK_EQUAL(t, Trit('T'));
        t = '0';
        t.Mul('T');
        BOOST_CHECK_EQUAL(t, Trit('0'));
        t = '0';
        t.Mul('0');
        BOOST_CHECK_EQUAL(t, Trit('0'));
        t = '0';
        t.Mul('1');
        BOOST_CHECK_EQUAL(t, Trit('0'));
        t = '1';
        t.Mul('T');
        BOOST_CHECK_EQUAL(t, Trit('T'));
        t = '1';
        t.Mul('0');
        BOOST_CHECK_EQUAL(t, Trit('0'));
        t = '1';
        t.Mul('1');
        BOOST_CHECK_EQUAL(t, Trit('1'));
    }

BOOST_AUTO_TEST_SUITE_END()
