#pragma once

#include <cmath>

class AtmosphereModel {
    public:
        // Function of recieving the refractive index from height
        virtual double N() (double h) = 0;
};

