#include "refrgeom.h"

RefrResult GeometricRound::calculate(double h_a, double h_s, double R)
{
    double oR_e = get_Re();
    double psi_d = std::asin((h_a/R) * (1 - (h_a/(2*(oR_e + h_a)))) + R/(2*(oR_e + h_a)));
    double psi_g = std::asin((h_a/R)*(1 + h_a/(2*oR_e)) - R/(2*oR_e));
    double d = oR_e * (psi_d - psi_g);
    return RefrResult(psi_d, psi_g, d);
}

RefrResult EffectiveRadius::calculate(double h_a, double h_s, double R)
{
    double oR_e = k()*get_Re();
    // double K = k();
    double psi_d = std::asin((h_a/R) * (1 - (h_a/(2*(oR_e + h_a)))) + R/(2*(oR_e + h_a)));
    double psi_g = std::asin((h_a/R)*(1 + h_a/(2*oR_e)) - R/(2*oR_e));
    double d = oR_e * (psi_d - psi_g);
    return RefrResult(psi_d, psi_g, d);
}

double FourThirds::k()
{
    return 4/3;
}
