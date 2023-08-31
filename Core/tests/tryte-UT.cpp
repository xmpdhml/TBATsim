#include <boost/test/unit_test.hpp>
#include <sstream>

#include <tryte.h>

using namespace Ternary;

BOOST_AUTO_TEST_SUITE(Types_Tryte)

    BOOST_AUTO_TEST_CASE(constructor)
    {
        Tryte t;

        Tryte t2(1);
        BOOST_CHECK(t2.trits[0].data == 0b01);
        
        Tryte t3(2);
        BOOST_CHECK_EQUAL(t3.toString(), "1T");

        Tryte t4(-1);
        BOOST_CHECK_EQUAL(t4.trits[0].data, 0b10);
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
        Tryte t3(200);
        t3.trits[2].data = 0b11;
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
