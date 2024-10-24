#pragma once
#include <cmath>
#include "atmosphere_model.h"


class ExponentialAtmosphere : public AtmosphereModel{
public:
    ExponentialAtmosphere(double _Ns, double _hs) : Ns(_Ns), hs(_hs) {}

    // SOURCE: (2.30, 2.31)
    //    N : refractive index, []
    //    h : height above the sea level, [m]
    virtual double N(double h) override;

private:
    double Ns;
    double hs;
};