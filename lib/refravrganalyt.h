#ifndef REFRAVRGANALYT_H
#define REFRAVRGANALYT_H

#include <cmath>
#include "refrgeom.h"
#include "exponential_model.h"

class AverageKAnalytical : public EffectiveRadius
{
    ExponentialAtmosphere* atmo;
public:
    AverageKAnalytical(ExponentialAtmosphere* atmo): atmo{atmo} {};
    // Reference: Refraction manual (2.38);
    // h_a : station height in meters;
    // h_s : target height in meters;
    // R : slant range in meters;
    // Returns average effective Earth radius multiplier.
    double k(double h_a, double h_s, double R) override;
};


class AveragePAnalytical : public EffectiveRadius
{
    ExponentialAtmosphere* atmo;
public:
    AveragePAnalytical(ExponentialAtmosphere* atmo): atmo{atmo} {};
    // Reference: Refraction manual (2.38);
    // h_a : station height in meters;
    // h_s : target height in meters;
    // R : slant range in meters;
    // Returns effective Earth radius based on average rho.
    double k(double h_a, double h_s, double R) override;
};

#endif // REFRAVRGANALYT_H
