#include "layered_model.h"
 
double LayeredAtmosphere::N(double h) {
    if (segments.size() == 0) {
        throw std::runtime_error("No segments provided.");
    }
    for (int i=0; i<segments.size(); i++) {
        if (segments[i].first <= height && height <= segments[i].second) {
            return atmospheres[i];
    }}
    }
