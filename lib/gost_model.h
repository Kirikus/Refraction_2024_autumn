#pragma once
#include "atmosphere_model.h"
#include "linear_interpolation.h"

template <class PressureModel, class TemperatureModel>
class GOSTModel : public AtmosphereModel {
public:
// Calculate the refractive index based on height
// Reference: Equations (2.23) and (2.24) from the source
// N : refractive index, dimensionless
// h : height above sea level, in meters
    virtual double N(double h) override;

// Calculate the density based on height
// Reference: Equations (2.25) and (2.26) from the source
// rho_w : density, in grams per cubic meter
// h : height above sea level, in meters
    double rho_w(double height);
// Initialization
    GOSTModel(PressureModel Press_M, TemperatureModel Temp_M) : Press_M(Press_M), Temp_M(Temp_M) {}

private:
    PressureModel Press_M;
    TemperatureModel Temp_M;
};
