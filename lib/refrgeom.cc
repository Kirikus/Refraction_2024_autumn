#include "refrgeom.h"


RefrResult GeometricLine::calculate(double h_a, double h_s, double R)
{
    // psi_d == psi_g
    double psi = std::sin((h_a - h_s)/R);
    double d = R*std::cos(psi);
    return RefrResult(psi, psi, d);
}

InvRefrResult GeometricLine::reverse(double h_a, double psi_d, double R)
{
    double h_s = h_a - R*std::sin(psi_d);
    double d = R*std::cos(psi_d);
    return InvRefrResult(h_s, d);
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

InvRefrResult GeometricRound::reverse(double h_a, double psi_d, double R)
{
    double oR_e = get_Re();
    double R_a = oR_e + h_a;

    double h_s = std::sqrt(R_a*(R_a - 2*R*std::sin(psi_d)) + R*R) - oR_e;

    double R_s = oR_e + h_s;
    double phi_e = std::acos((R_a*R_a + R_s*R_s - R*R)/(2*R_a*R_s));

    double d = R_s * phi_e;
    return InvRefrResult(h_s, d);
}


RefrResult EffectiveRadius::calculate(double h_a, double h_s, double R)
{
    double oR_e = k()*get_Re();
    double delta_h = h_a - h_s;
    double R_a = oR_e + h_a;
    double R_s = oR_e + h_s;

    double psi_d = std::asin((delta_h/R) * (1 - delta_h/(2*R_a)) + R/(2*R_a));
    double psi_g = std::asin((delta_h/R) * (1 + delta_h/(2*R_s)) - R/(2*R_s));
    double d = R_s * (psi_d - psi_g);
    return RefrResult(psi_d, psi_g, d);
}

InvRefrResult EffectiveRadius::reverse(double h_a, double psi_d, double R)
{
    double oR_e = k()*get_Re();
    double R_a = oR_e + h_a;

    double h_s = std::sqrt(R_a*(R_a - 2*R*std::sin(psi_d)) + R*R) - oR_e;

    double R_s = oR_e + h_s;
    double phi_e = std::acos((R_a*R_a + R_s*R_s - R*R)/(2*R_a*R_s));

    double d = R_s * phi_e;
    return InvRefrResult(h_s, d);
}


double FourThirds::k() { return 4/3; }
