#pragma once
#include <cmath>

class ExponentialAtmosphere : public AtmosphereModel{
public:
    ExponentialAtmosphere(double _N0, double _decay_rate) : N0(_N0), decay_rate(_decay_rate) {}

    virtual double N(double h) override {
        return N0 * std::exp(_decay_rate * h);
    }

private:
    double N0;
    double decay_rate;
};