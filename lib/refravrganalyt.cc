#include "refravrganalyt.h"

double AverageKAnalytical::k(double h_a, double h_s, double R) {
  double oRe = get_Re();
  double delta_h = h_a - h_s;
  // 'cos_psi' calculated as in GeometricLine
  // using Pythagorean theorem
  double cos_psi = (R * R - delta_h * delta_h) / R;
  double varNH = 1e-6 * atmo->Ns * cos_psi * oRe / atmo->Hb;
  double varLN = std::log((std::exp(delta_h / atmo->Hb) - varNH) / (1 - varNH));

  double k_avg = (atmo->Hb / delta_h) * varLN;
  return k_avg;
}

double AveragePAnalytical::k(double h_a, double h_s, double R) {
  double oRe = get_Re();
  double delta_h = h_a - h_s;
  // 'cos_psi' calculated as in GeometricLine
  // using Pythagorean theorem
  double cos_psi = (R * R - delta_h * delta_h) / R;
  double varNH = 1e-6 * atmo->Ns * cos_psi * oRe / atmo->Hb;

  double rho_avg =
      (1 / varNH) * (std::exp(delta_h / atmo->Hb) - 1) / (delta_h / atmo->Hb);
  double k_avg = rho_avg / (rho_avg - oRe);
  return k_avg;
}
