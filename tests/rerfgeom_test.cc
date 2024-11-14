#include "../lib/refrgeom.h"

#if !defined(WIN32)
#define BOOST_TEST_DYN_LINK
#endif
#include <boost/test/unit_test.hpp>

namespace tt = boost::test_tools;
namespace utf = boost::unit_test;

BOOST_AUTO_TEST_SUITE(geom_round)

BOOST_AUTO_TEST_CASE(generic1)
{
    double in_h_a = 300, in_h_s = 50, in_R = 500;
    double test_psi_d = 0.643532464987906, test_psi_g = 0.6434697518612371, test_d = 399.9905932064908;
    GeometricRound a;
    RefrResult thing = a.calculate(in_h_a, in_h_s, in_R);
    // BOOST_TEST(test_psi_d == thing.psi_d, tt::tolerance(1e-6));
    // BOOST_TEST(test_psi_g == thing.psi_g, tt::tolerance(1e-6));
    // BOOST_TEST(test_psi_d == thing.psi_d && test_psi_g == thing.psi_g && test_d == thing.d);
    BOOST_TEST(test_d == thing.d);
}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(four_thirds)
BOOST_AUTO_TEST_CASE(generic1)
{
    double in_h_a = 300, in_h_s = 50, in_R = 500;
    double test_psi_d = 0.6435246261466453, test_psi_g = 0.6434775910251165, test_d = 399.9929448305851;
    FourThirds a;
    RefrResult thing = a.calculate(in_h_a, in_h_s, in_R);
    // BOOST_TEST(test_psi_d == thing.psi_d, tt::tolerance(1e-6));
    // BOOST_TEST(test_psi_g == thing.psi_g, tt::tolerance(1e-6));
    // BOOST_TEST(test_d == thing.d, tt::tolerance(1e-6));
    // BOOST_TEST(test_psi_d == thing.psi_d && test_psi_g == thing.psi_g && test_d == thing.d);
    BOOST_TEST(test_d == thing.d);
}
BOOST_AUTO_TEST_SUITE_END()
