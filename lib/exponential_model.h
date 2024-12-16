#pragma once
#include <cmath>

#include "atmosphere_model.h"

class ExponentialAtmosphere : public AtmosphereModel {
 public:
  ExponentialAtmosphere(double _Ns, double _hs, double _Hb)
      : Ns(_Ns), hs(_hs), Hb(_Hb) {}

  // SOURCE: (2.30, 2.31)
  //    N : refractive index, []
  //    h : height above the sea level, [m]
  virtual double N(double h) override;

 public:
  double Ns;
  double hs;
  double Hb;
};

class ExponentialAtmosphere3k : public ExponentialAtmosphere {
  ExponentialAtmosphere3k(double _Ns, double _hs)
      : ExponentialAtmosphere(_Ns, _hs, 0.0) {
    const double dN = -0.00732 * std::exp(0.005577 * Ns);
    Hb = 1000 / std::log(_Ns / (_Ns + 1000 * dN));
  }
};

class ExponentialAtmosphere10k : public ExponentialAtmosphere {
 public:
  ExponentialAtmosphere10k(double _Ns, double _hs)
      : ExponentialAtmosphere(_Ns, _hs, 0.0) {
    const double hb = 9144;
    const double Nb = 102.9;
    Hb = (hb - hs) / std::log(Ns / Nb);
  }
};

class ExponentialAtmosphere15k : public ExponentialAtmosphere {
 public:
  ExponentialAtmosphere15k(double _Ns, double _hs)
      : ExponentialAtmosphere(_Ns, _hs, 0.0) {
    const double hb = 12192;
    const double Nb = 66.65;
    Hb = (hb - hs) / std::log(Ns / Nb);
  }
};
