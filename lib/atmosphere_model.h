#pragma once

#include <cmath>

class AtmosphereModel {
    public:
        // N - refractive index - []
        // h - height - [m]
        virtual double N() (double h) = 0;
};

