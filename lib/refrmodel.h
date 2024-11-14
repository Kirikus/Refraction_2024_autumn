#ifndef REFRMODEL_H
#define REFRMODEL_H


struct RefrResult
{
    double psi_d;
    double psi_g;
    double d;
    RefrResult(double npsi_d, double npsi_g, double nd);
};


class RefractionModel
{
private:
    // Earth radius in meters
    double R_e = 6378100;
public:
    // Get Earth radius in meters
    double get_Re() const;
    virtual RefrResult calculate(double const h_a, double const h_s, double const R) = 0;
    double reverse(double const h_a, double const psi_d, double const R);
};

#endif // REFRMODEL_H
