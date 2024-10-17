#pragma once

class ExponentialAtmosphere : public AtmosphereModel{
public:
    ExponentialAtmosphere(double _Ns, double _hs) : Ns(_N0), hs(_hs) {}

    // SOURCE: (2.30, 2.31)
    //    N : refractive index, []
    //    h : height above the sea level, [m]
    virtual double N(double h) override {
        // Values for diaposon 0 - 15 km
        double const hb = 12192;
        double const Nb = 66.65;
        double Hb =  (hb - hs) / log(Ns / Nb);
        return Ns * exp(-(h - hs) / Hb);
    }

private:
    double Ns;
    double hs
};