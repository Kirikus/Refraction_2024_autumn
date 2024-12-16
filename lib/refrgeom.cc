#include "refrgeom.h"


RefrResult GeometricLine::calculate(double h_a, double h_s, double R)
{
    // psi_d == psi_g
    double psi = std::asin((h_a - h_s)/R);
    double d = R*std::cos(psi);
    return RefrResult(psi, psi, d);
}


RefrResult GeometricRound::calculate(double h_a, double h_s, double R)
{
    double oR_e = get_Re();
    double delta_h = h_a - h_s;
    double R_a = oR_e + h_a;
    double R_s = oR_e + h_s;

    double psi_d = std::asin((delta_h/R) * (1 - delta_h/(2*R_a)) + R/(2*R_a));
    double psi_g = std::asin((delta_h/R) * (1 + delta_h/(2*R_s)) - R/(2*R_s));
    double d = R_s * (psi_d - psi_g);
    return RefrResult(psi_d, psi_g, d);
}


RefrResult EffectiveRadius::calculate(double h_a, double h_s, double R)
{
    double oR_e = k(h_a, h_s, R)*get_Re();
    double delta_h = h_a - h_s;
    double R_a = oR_e + h_a;
    double R_s = oR_e + h_s;

    double psi_d = std::asin((delta_h/R) * (1 - delta_h/(2*R_a)) + R/(2*R_a));
    double psi_g = std::asin((delta_h/R) * (1 + delta_h/(2*R_s)) - R/(2*R_s));
    double d = R_s * (psi_d - psi_g);
    return RefrResult(psi_d, psi_g, d);
}


double FourThirds::k(double, double, double) { return 4/3; }
