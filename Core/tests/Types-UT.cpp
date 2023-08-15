#include <boost/test/unit_test.hpp>
#include <sstream>

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

    BOOST_AUTO_TEST_CASE(trit_neg)
    {
        Trit t1('0'), t2('1'), t3('T');
        BOOST_CHECK_EQUAL(-t1, t1);
        BOOST_CHECK_EQUAL(-t2, t3);
        BOOST_CHECK_EQUAL(-t3, t2);
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
        BOOST_CHECK_EQUAL(t4.toString(), "T");

        Tryte t5(27);
        BOOST_CHECK_EQUAL(t5.toString(), "1000");

        t = 5;
        BOOST_CHECK_EQUAL(t.toString(), "1TT");

        t = -5;
        BOOST_CHECK_EQUAL(t.toString(), "T11");
        
    }

    BOOST_AUTO_TEST_CASE(tryte_nan)
    {
        Tryte t1(365);
        BOOST_CHECK(t1.isNaN());
        Tryte t2(-365);
        BOOST_CHECK(t2.isNaN());

        Tryte t3(364);
        BOOST_CHECK(!t3.isNaN());
        Tryte t4(-364);
        BOOST_CHECK(!t4.isNaN());

        Tryte t5;
        t5.data = 0b001100100100;
        BOOST_CHECK(t5.isNaN());
        t5.data = 0b010100100100;
        BOOST_CHECK(!t5.isNaN());
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
        os << t3;
        BOOST_CHECK_EQUAL(os.str(), "X01T01");
    }

    BOOST_AUTO_TEST_CASE(tryte_neg)
    {
        Tryte t1(1), t2(-1), t3(2), t4(-2);
        BOOST_CHECK_EQUAL(-t1, t2);
        BOOST_CHECK_EQUAL(-t2, t1);
        BOOST_CHECK_EQUAL(-t3, t4);
        BOOST_CHECK_EQUAL(-t4, t3);
    }

BOOST_AUTO_TEST_SUITE_END()
