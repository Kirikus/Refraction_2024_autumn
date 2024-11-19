#ifndef REFRGEOM_H
#define REFRGEOM_H

#include "refrmodel.h"
#include <math.h>


class GeometricLine : public RefractionModel
{
public:
    RefrResult calculate(double const h_a, double const h_s, double const R) override;
    InvRefrResult reverse(double const h_a, double const psi_d, double const R) override;
};


class GeometricRound : public RefractionModel
{
public:
    virtual RefrResult calculate(double const h_a, double const h_s, double const R) override;
    virtual InvRefrResult reverse(double const h_a, double const psi_d, double const R) override;
};


class EffectiveRadius : public GeometricRound
{
private:
    virtual double k() = 0;
public:
    RefrResult calculate(double const h_a, double const h_s, double const R) override;
    InvRefrResult reverse(double const h_a, double const psi_d, double const R) override;
};


class FourThirds : public EffectiveRadius
{
private:
    double k() override;
};

#endif // REFRGEOM_H
