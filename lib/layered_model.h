#pragma once
#include <cmath>
#include <utility>
#include <vector>

class LayeredAtmosphere : public AtmosphereModel{
public:
    SegmentedAtmosphere(const std::vector<Atmosphereodel*> atmospheres, const std::vector<std::pair<double, double>> _segments) : 
        models{atmospheres}, segments{_segments} {}

     virtual double N(double h) override;

private:
    std::vector<std::pair<double, double>> segments;
    const std::vector<AtmosphereModel*> models;
};