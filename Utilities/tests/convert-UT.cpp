#include <boost/test/unit_test.hpp>

#include <Core/Types.h>
#include <convert.h>

BOOST_AUTO_TEST_SUITE(convert)

    BOOST_AUTO_TEST_CASE(convert_trit)
    {
        using namespace Utilities;
        TCore::Trit t;
        t.data = 0b00;
        BOOST_CHECK_EQUAL(ToString(t), "0");
        t.data = 0b01;
        BOOST_CHECK_EQUAL(ToString(t), "1");
        t.data = 0b11;
        BOOST_CHECK_EQUAL(ToString(t), "T");
        t.data = 0b10;
        BOOST_CHECK_THROW(ToString(t), TConvertException);
        BOOST_CHECK_EQUAL(ToString(t, true), "N");
    }

BOOST_AUTO_TEST_SUITE_END()
