#ifndef REFRMODEL_H
#define REFRMODEL_H

#include <cmath>

// psi_d : declination angle in radians;
// psi_g : glide angle in radians;
// d : arc length in meters.
struct RefrResult
{
    double psi_d;
    double psi_g;
    double d;
    RefrResult();
    RefrResult(double npsi_d, double npsi_g, double nd);
};

// h_s : target height in meters;
// psi_g : glide angle in radians;
// d : arc length in meters.
struct InvRefrResult
{
    double h_s;
    double psi_g;
    double d;
    InvRefrResult();
    InvRefrResult(double nh_s, double psi_g, double nd);
};


class RefractionModel
{
private:
    // R_e : Earth radius in meters.
    double R_e = 6378100;
public:
    // Get Earth radius in meters.
    double get_Re() const;
    // h_a : station height in meters;
    // h_s : target height in meters;
    // R : slant range in meters.
    virtual RefrResult calculate(double const h_a, double const h_s, double const R) = 0;
    // h_a : station height in meters;
    // psi_d : declination angle in radians;
    // R : slant range in meters.
    InvRefrResult reverse(double const h_a, double const psi_d, double const R);
};

#endif // REFRMODEL_H
