#pragma once
#include <utility>
#include <vector>

class LayeredAtmosphere : public AtmosphereModel {
public:
    LayeredAtmosphere(const std::vector<AtmospherModel> atmospheres,
                      const std::vector<double> _heights) :
        models{atmospheres}, heights{_segments} {
        if(models.size() == 0 || heights.size() == 0)
            throw std::runtime_error("Empty vector provided");
        if (heights.size() - 1 != models.size())
            throw std::runtime_error("Invalid sizes of arguments");
        for (size_t i = 0; i < heights.size() - 1; ++i)
            if (heights[i] >= heights[i + 1])
                throw std::runtime_error("The monotony of heights is broken");
    }

    virtual double N(double h) override;

private:
    // heights - [m]
    std::vector<double> heights;
    const std::vector<AtmosphereModel> models;
};
