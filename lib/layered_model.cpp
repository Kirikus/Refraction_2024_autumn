#include "layered_model.h"

double LayeredAtmosphere::N(double h) {
    int i = 0;
    for (i; i < heights.size(); i++)
        if (h < heights[i])
            return models[i].N(h);
    return models[i].N(h);
}
