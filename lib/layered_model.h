#pragma once
#include "atmosphere_model.h"
#include <utility>
#include <vector>

class LayeredAtmosphere : public AtmosphereModel {
public:
    LayeredAtmosphere(const std::vector<AtmosphereModel*> atmospheres,
                      const std::vector<double> _heights);

    virtual double N(double h) override;

private:
    // heights - [m]
    std::vector<double> heights;
    const std::vector<AtmosphereModel*> models;
};
