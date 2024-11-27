#include "../lib/refrgeom.h"

#if !defined(WIN32)
#define BOOST_TEST_DYN_LINK
#endif
#include <boost/test/unit_test.hpp>
namespace tt = boost::test_tools;
namespace utf = boost::unit_test;

BOOST_AUTO_TEST_SUITE(geom_round)

BOOST_AUTO_TEST_CASE(direct_thousand1)
{
    // Reference: Refraction manual formulas (2.17), (2.19).
    double input_h_a = 1000,
           input_h_s = 20,
           input_R   = 1000;

    double expected_psi_d = 1.37047708,
           expected_psi_g = 1.37044588,
           expected_d     = 198.9822;

    GeometricRound model;
    RefrResult output = model.calculate(input_h_a, input_h_s, input_R);

    BOOST_TEST(expected_psi_d == output.psi_d, tt::tolerance(1e-6));
    BOOST_TEST(expected_psi_g == output.psi_g, tt::tolerance(1e-6));
    BOOST_TEST(expected_d == output.d, tt::tolerance(1e-2));
}

BOOST_AUTO_TEST_CASE(reverse_thousand1)
{
    double input_h_a   = 1000,
           input_psi_d = 1.37047708,
           input_R     = 1000;

    double expected_h_s = 20.,
           expected_d   = 198.9822;

    GeometricRound model;
    InvRefrResult output = model.reverse(input_h_a, input_psi_d, input_R);

    BOOST_TEST(expected_h_s == output.h_s, tt::tolerance(1e-1));
    BOOST_TEST(expected_d == output.d, tt::tolerance(1e-1));
}

BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE(four_thirds)

BOOST_AUTO_TEST_CASE(direct_sixty1)
{
    // Reference: Refraction manual formulas (2.17), (2.19).
    double input_h_a = 60,
           input_h_s = 20,
           input_R   = 750;

    double expected_psi_d = 5340268e-8,
           expected_psi_g = 5331461e-8,
           expected_d     = 748.9308;

    FourThirds model;
    RefrResult output = model.calculate(input_h_a, input_h_s, input_R);

    BOOST_TEST(expected_psi_d == output.psi_d, tt::tolerance(1e-3));
    BOOST_TEST(expected_psi_g == output.psi_g, tt::tolerance(1e-3));
    BOOST_TEST(expected_d == output.d, tt::tolerance(1e-2));
}

BOOST_AUTO_TEST_CASE(reverse_sixty1)
{
    double input_h_a   = 60,
           input_psi_d = 5340268e-8,
           input_R     = 750;

    double expected_h_s = 20.,
           expected_d   = 748.9308;

    FourThirds model;
    InvRefrResult output = model.reverse(input_h_a, input_psi_d, input_R);

    BOOST_TEST(expected_h_s == output.h_s, tt::tolerance(1e-1));
    BOOST_TEST(expected_d == output.d, tt::tolerance(1e-1));
}

BOOST_AUTO_TEST_SUITE_END()
