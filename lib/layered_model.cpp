#include "layered_model.h"
#include "atmosphere_model.h"
#include <stdexcept>

LayeredAtmosphere::LayeredAtmosphere(const std::vector<AtmosphereModel*> atmospheres,
                      const std::vector<double> _heights):
        models{atmospheres}, heights{_heights} {
        if(models.size() == 0 || heights.size() == 0)
            throw std::runtime_error("Empty vector provided");
        if (heights.size() - 1 != models.size())
            throw std::runtime_error("Invalid sizes of arguments");
        for (size_t i = 0; i < heights.size() - 1; ++i)
            if (heights[i] >= heights[i + 1])
                throw std::runtime_error("The monotony of heights is broken");
    }

double LayeredAtmosphere::N(double h) {
    int i = 0;
    for (i; i < heights.size(); i++)
        if (h < heights[i])
            return models[i]->N(h);
    return models[i]->N(h);
}

