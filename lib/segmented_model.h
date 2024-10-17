#pragma once

#include "atmosphere_model.h"

class SegmentedAtmosphere : public AtmosphereModel {
public:
    // SOURCE: (2.27-28)
    // N - refractive index - []
    // h - height - [m]
    virtual double N(double h) override;
    SegmentedModel(double _Ns = 324.8, double _hs = 0): Ns(_Ns), hs(_hs) {
        dN =  -0.00732 * exp(0.005577 * Ns);
        N1 = Ns + (1000 - hs) * dN;
        H =  (8000 - hs) / log(N1 / 105);
    }

private:
    double Ns;
    double hs;
    double dN; // Linear coefficient of reduction refractive idx - []
    double H; // Exponential reduction constant of refractive idx - []
    double N1; // Refractive index at a height of 1 km above the surface - []
};
