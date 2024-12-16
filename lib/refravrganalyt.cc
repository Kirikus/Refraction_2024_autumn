#include "refravrganalyt.h"

double AverageKAnalytical::k(double h_a, double h_s, double R)
{
    double oRe = get_Re();
    double delta_h = h_a - h_s;
    // 'cos_psi' calculated as in GeometricLine
    // using Pythagorean theorem
    double cos_psi = (R*R - delta_h*delta_h)/R;
    double varNH = 1e-6*atmo->N_s*cos_psi*oRe/atmo->H_b;
    double varLN = std::log((std::pow(delta_h/atmo->H_b) - varNH)/(1 - varNH));

    double k_avg = (atmo->H_b/delta_h)*varLN;
    return k_avg;
}


double AveragePAnalytical::k(double h_a, double h_s, double R)
{
    double oRe = get_Re();
    double delta_h = h_a - h_s;
    // 'cos_psi' calculated as in GeometricLine
    // using Pythagorean theorem
    double cos_psi = (R*R - delta_h*delta_h)/R;
    double varNH = 1e-6*atmo->N_s*cos_psi*oRe/atmo->H_b;

    double rho_avg = (1/varNH)*(std::pow(delta_h/atmo->H_b) - 1)/(delta_h/atmo->H_b);
    double k_avg = rho_avg/(rho_avg - oRe);
    return k_avg;
}
