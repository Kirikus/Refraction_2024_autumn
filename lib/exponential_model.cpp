#include "exponential_model.h"

double ExponentialAtmosphere::N(double h) {
        // Values for diaposon 0 - 15 km
        double const hb = 12192;
        double const Nb = 66.65;
        double Hb =  (hb - hs) / log(Ns / Nb);
        return Ns * exp(-(h - hs) / Hb);
    }