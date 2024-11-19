#include "refrmodel.h"

RefrResult::RefrResult(double npsi_d, double npsi_g, double nd) : psi_d{npsi_d}, psi_g{npsi_g}, d{nd} {}

InvRefrResult::InvRefrResult(double nh_s, double nd) : h_s{nh_s}, d{nd} {}

double RefractionModel::get_Re() const
{
    return R_e;
}
