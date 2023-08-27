#include <boost/test/unit_test.hpp>
#include <sstream>

#include <Types.h>

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

BOOST_AUTO_TEST_SUITE(Types_Tryte)

    BOOST_AUTO_TEST_CASE(constructor)
    {
        Tryte t;
        BOOST_CHECK(t.data == 0);

        Tryte t2(1);
        BOOST_CHECK(t2.data == 0b000000000001);
        
        Tryte t3(2);
        BOOST_CHECK_EQUAL(t3.toString(), "1T");

        Tryte t4(-1);
        BOOST_CHECK_EQUAL(t4.data, 0b000000000010);
        BOOST_CHECK_EQUAL(t4.toString(), "T");

        Tryte t5(27);
        BOOST_CHECK_EQUAL(t5.toString(), "1000");

        t = 5;
        BOOST_CHECK_EQUAL(t.toString(), "1TT");

        t = -5;
        BOOST_CHECK_EQUAL(t.toString(), "T11");
        
    }

    BOOST_AUTO_TEST_CASE(tryte_to_string)
    {
        std::ostringstream os;
        Tryte t1(1);
        os << t1;
        BOOST_CHECK_EQUAL(os.str(), "1");
        os.str(std::string());
        Tryte t2(-1);
        os << t2;
        BOOST_CHECK_EQUAL(os.str(), "T");
        os.str(std::string());
        Tryte t3;
        t3.data = 0b110001100001;
        BOOST_CHECK_THROW(os << t3, TException);
    }

    BOOST_AUTO_TEST_CASE(tryte_neg)
    {
        Tryte t1(1), t2(-1), t3(2), t4(-2);

        try {
        BOOST_CHECK_EQUAL(-t1, t2);
        BOOST_CHECK_EQUAL(-t2, t1);
        BOOST_CHECK_EQUAL(-t3, t4);
        BOOST_CHECK_EQUAL(-t4, t3);
        }
        catch (TException& e) {
            std::cout << e.what() << std::endl;
        }
    }

    BOOST_AUTO_TEST_CASE(tryte_comparison)
    {
        Tryte t1(1), t2(-1), t3(2), t4(-2), t5(3), t6(-3);

        BOOST_CHECK(t1 == t1);
        BOOST_CHECK(t2 == t2);
        BOOST_CHECK(t3 == t3);
        BOOST_CHECK(t4 == t4);
        BOOST_CHECK(t5 == t5);
        BOOST_CHECK(t6 == t6);

        BOOST_CHECK(t1 != t2);
        BOOST_CHECK(t1 != t3);
        BOOST_CHECK(t1 != t4);
        BOOST_CHECK(t1 != t5);
        BOOST_CHECK(t1 != t6);

        BOOST_CHECK(t2 != t3);
        BOOST_CHECK(t2 != t4);
        BOOST_CHECK(t2 != t5);
        BOOST_CHECK(t2 != t6);

        BOOST_CHECK(t3 != t4);
        BOOST_CHECK(t3 != t5);
        BOOST_CHECK(t3 != t6);

        BOOST_CHECK(t4 != t5);
        BOOST_CHECK(t4 != t6);

        BOOST_CHECK(t5 != t6);

        BOOST_CHECK(t1 > t2);
        BOOST_CHECK(t1 < t3);
        BOOST_CHECK(t1 > t4);
        BOOST_CHECK(t1 < t5);
        BOOST_CHECK(t1 > t6);

        BOOST_CHECK(t2 < t3);
        BOOST_CHECK(t2 > t4);
        BOOST_CHECK(t2 < t5);
        BOOST_CHECK(t2 > t6);

        BOOST_CHECK(t3 > t4);
        BOOST_CHECK(t3 < t5);
        BOOST_CHECK(t3 > t6);

        BOOST_CHECK(t4 < t5);
        BOOST_CHECK(t4 > t6);

        BOOST_CHECK(t5 > t6);
    }

BOOST_AUTO_TEST_SUITE_END()
