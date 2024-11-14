#ifndef REFRGEOM_H
#define REFRGEOM_H

#include "refrmodel.h"
#include <math.h>

class GeometricRound : public RefractionModel
{
public:
    virtual RefrResult calculate(double const h_a, double const h_s, double const R);
};

class EffectiveRadius : public GeometricRound
{
private:
    virtual double k() = 0;
public:
    RefrResult calculate(double const h_a, double const h_s, double const R);
};

class FourThirds : public EffectiveRadius
{
private:
    double k();
};

#endif // REFRGEOM_H
