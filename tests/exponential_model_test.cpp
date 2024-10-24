#include <QApplication>

#include "../lib/exponential_model.h"
#include "qcustomplot.h"

#if !defined(WIN32)
#define BOOST_TEST_DYN_LINK
#endif
#include <boost/test/unit_test.hpp>

namespace tt = boost::test_tools;

BOOST_AUTO_TEST_SUITE(test_N_exponential)

BOOST_AUTO_TEST_CASE(N_at_ground_level_Ns_324_8_equals_to_324_8) {
    ExponentialModel testExponentialModelGroundLevel(324.8, 0);
    BOOST_TEST(testExponentialModelGroundLevel.N(0) == 324.8, tt::tolerance(1e-6));
}

BOOST_AUTO_TEST_CASE(N_at_ground_level_Ns_66_65_equals_to_66_65) {
    ExponentialModel testExponentialModelGroundLevel(66.65, 0);
    BOOST_TEST(testExponentialModelGroundLevel.N(0) == 66.65, tt::tolerance(1e-6));
}

BOOST_AUTO_TEST_SUITE_END()
