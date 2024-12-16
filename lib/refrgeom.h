#ifndef REFRGEOM_H
#define REFRGEOM_H

#include "refrmodel.h"


class GeometricLine : public RefractionModel
{
public:
    // h_a : station height in meters;
    // h_s : target height in meters;
    // R : slant range in meters.
    RefrResult calculate(double const h_a, double const h_s, double const R) override;
};


class GeometricRound : public RefractionModel
{
public:
    // Reference: Refraction manual (2.17), (2.19);
    // h_a : station height in meters;
    // h_s : target height in meters;
    // R : slant range in meters.
    virtual RefrResult calculate(double const h_a, double const h_s, double const R) override;
};


class EffectiveRadius : public GeometricRound
{
private:
    // h_a : station height in meters;
    // h_s : target height in meters;
    // R : slant range in meters;
    // Returns effective Earth radius multiplier.
    virtual double k(double h_a, double h_s, double R) = 0;
public:
    // Reference: Refraction manual (2.17), (2.19);
    // h_a : station height in meters;
    // h_s : target height in meters;
    // R : slant range in meters.
    RefrResult calculate(double const h_a, double const h_s, double const R) override;
};


class FourThirds : public EffectiveRadius
{
private:
    // Reference: Refraction manual (2.36);
    // Returns effective Earth radius multiplier.
    double k(double, double, double) override;
};

#endif // REFRGEOM_H
