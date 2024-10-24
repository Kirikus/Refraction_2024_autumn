#include <QApplication>

#include "../lib/segmented_model.h"
#include "qcustomplot.h"

#if !defined(WIN32)
//#define BOOST_TEST_DYN_LINK
#endif
#include <boost/test/unit_test.hpp>

namespace tt = boost::test_tools;

BOOST_AUTO_TEST_SUITE(test_N_segmented)

BOOST_AUTO_TEST_CASE(N_at_ground_level) {
    SegmentedModel testSegmentedModelGroundLevel(324.8, 0);
    BOOST_TEST(testSegmentedModelGroundLevel.N(0) == 324.8, tt::tolerance(1e-6));
}

BOOST_AUTO_TEST_CASE(N_at_1000m_continuous) {
    SegmentedModel testSegmentedModel(324.8, 0);
    BOOST_TEST(testSegmentedModel.N(1000 - 1e-6) == testSegmentedModel.N(1000 + 1e-6), tt::tolerance(1e-6));
}

BOOST_AUTO_TEST_CASE(N_at_9000m_continuous) {
    SegmentedModel testSegmentedModel(324.8, 0);
    BOOST_TEST(testSegmentedModel.N(9000 - 1e-6) == testSegmentedModel.N(9000 + 1e-6), tt::tolerance(1e-6));
}

BOOST_AUTO_TEST_SUITE_END()
